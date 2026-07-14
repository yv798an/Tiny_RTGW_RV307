from flask import Flask, render_template, jsonify
from flask_socketio import SocketIO
import paho.mqtt.client as mqtt
import json
import sqlite3
import time
import threading
from datetime import datetime

app = Flask(
    __name__,
    template_folder="."  # HTML文件放在同一目录
)
socketio = SocketIO(app,cors_allowed_origins="*")

# =========================
# SQLite 数据库
# =========================

DB_PATH = "gateway_data.db"

# MQTT在独立线程回调，需允许跨线程使用连接并加锁
db_conn = sqlite3.connect(DB_PATH, check_same_thread=False)
db_lock = threading.Lock()

# 最近一次的LED状态（0=关，1=开）
current_led_state = 0


def init_db():
    with db_lock:
        db_conn.execute(
            """
            CREATE TABLE IF NOT EXISTS sensor_data
            (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                temperature REAL,
                humidity REAL,
                light_adc INTEGER,
                light_mv INTEGER,
                led_state INTEGER,
                timestamp INTEGER,
                datetime TEXT
            )
            """
        )
        db_conn.commit()


def save_sensor_data(data):
    ts = int(time.time())
    dt = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

    with db_lock:
        db_conn.execute(
            """
            INSERT INTO sensor_data
                (temperature, humidity, light_adc, light_mv,
                 led_state, timestamp, datetime)
            VALUES (?, ?, ?, ?, ?, ?, ?)
            """,
            (
                data.get("temperature"),
                data.get("humidity"),
                data.get("light_adc"),
                data.get("light_mv"),
                current_led_state,
                ts,
                dt,
            ),
        )
        db_conn.commit()

    print("已保存到数据库:", dt)


init_db()

MQTT_SERVER = ""    #公共broker.emqx.io
MQTT_PORT = XXX        #公共1883
MQTT_USERNAME = ""
MQTT_PASSWORD = ""
# 数据上传主题
MQTT_SUB_TOPIC = "" 
# 控制下发主题
MQTT_PUB_TOPIC = ""


def mqtt_on_message(client, userdata, msg):
    print("\n收到MQTT数据:")
    payload = msg.payload.decode()
    print(payload)


    try:
        data = json.loads(payload)
        # 保存到SQLite数据库
        save_sensor_data(data)
        # 推送给网页
        socketio.emit("sensor_data",data)
    except Exception as e:
        print("JSON错误:",e)

def mqtt_on_connect(client, userdata, flags, rc):

    if rc == 0:

        print("MQTT连接成功")


        # 订阅传感器数据
        client.subscribe(
            MQTT_SUB_TOPIC
        )
    else:

        print(
            "MQTT连接失败:",
            rc
        )

# =========================
# MQTT客户端
# =========================

mqtt_client = mqtt.Client()

mqtt_client.username_pw_set(MQTT_USERNAME,MQTT_PASSWORD)


mqtt_client.on_connect = mqtt_on_connect

mqtt_client.on_message = mqtt_on_message


mqtt_client.connect(MQTT_SERVER,MQTT_PORT,60)


mqtt_client.loop_start()

@app.route("/")
def index():

    return render_template(
        "index.html"
    )


@app.route("/history")
def history():
    with db_lock:
        rows = db_conn.execute(
            """
            SELECT temperature, humidity, light_adc, light_mv,
                   led_state, datetime
            FROM sensor_data
            ORDER BY id DESC
            LIMIT 10
            """
        ).fetchall()

    result = [
        {
            "temperature": r[0],
            "humidity": r[1],
            "light_adc": r[2],
            "light_mv": r[3],
            "led_state": r[4],
            "datetime": r[5],
        }
        for r in rows
    ]

    return jsonify(result)



@socketio.on("control")
def handle_control(data):


    print("网页控制:")
    print(data)

    mqtt_payload = json.dumps( data)

    mqtt_client.publish(MQTT_PUB_TOPIC, mqtt_payload)

    print("发布:",mqtt_payload)



@socketio.on("led_control")
def handle_led_control(data):
    global current_led_state
    command = data.get("command")
    print("LED控制命令:", command)

    current_led_state = 1 if command == "ON" else 0

    mqtt_payload = json.dumps({"led": command})
    mqtt_client.publish(MQTT_PUB_TOPIC, mqtt_payload)
    print("LED指令已发布:", mqtt_payload)


if __name__ == "__main__":
    socketio.run(app,host="0.0.0.0",port=5000)