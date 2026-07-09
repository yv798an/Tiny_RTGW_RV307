from flask import Flask, render_template
from flask_socketio import SocketIO
import paho.mqtt.client as mqtt
import json

app = Flask(__name__)
socketio = SocketIO(app,cors_allowed_origins="*")

MQTT_SERVER = "broker.emqx.io"
MQTT_PORT = 1883
MQTT_USERNAME = ""
MQTT_PASSWORD = ""
# 数据上传主题
MQTT_SUB_TOPIC = "gateway/data/submit"
# 控制下发主题
MQTT_PUB_TOPIC = "gateway/data/recommand"


def mqtt_on_message(client, userdata, msg):
    print("\n收到MQTT数据:")
    payload = msg.payload.decode()
    print(payload)


    try:
        data = json.loads(payload)
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



@socketio.on("control")
def handle_control(data):


    print("网页控制:")
    print(data)

    mqtt_payload = json.dumps( data)

    mqtt_client.publish(MQTT_PUB_TOPIC, mqtt_payload)

    print("发布:",mqtt_payload)



@socketio.on("led_control")
def handle_led_control(data):
    command = data.get("command")
    print("LED控制命令:", command)

    mqtt_payload = json.dumps({"led": command})
    mqtt_client.publish(MQTT_PUB_TOPIC, mqtt_payload)
    print("LED指令已发布:", mqtt_payload)


if __name__ == "__main__":
    socketio.run(app,host="0.0.0.0",port=5000)