#include <WiFi.h>
#include <PubSubClient.h>

// ================= 1. 硬件引脚与串口配置 =================
// ESP32-C6 有多个硬件串口，我们使用 Serial 连电脑调式，Serial1 连接你的大开发板
#define RX1_PIN 6   // 根据你C6开发板的实际引脚修改（GPIO6）
#define TX1_PIN 7   // 根据你C6开发板的实际引脚修改（GPIO7）

// ================= 2. 手机热点与MQTT服务器配置 =================
const char* ssid         = "your_wifi_name";     // 手机热点名称（须为2.4GHz）
const char* password     = "wifi_pd";  // 手机热点密码

// 这里以公共免费的 EMQX 服务器为例
const char* mqtt_server  = ""; 			//公共broker.emqx.io
const int mqtt_port      = 1883;
const char* mqtt_user    = "";                       // 如果有MQTT用户名请输入
const char* mqtt_pass    = "";                       // 如果有MQTT密码请输入

// MQTT 主题
const char* pub_topic    = "";    // 数据发布主题
const char* sub_topic    = ""; // 数据订阅主题

// ================= 3. 实例化网络对象 =================
WiFiClient espClient;
PubSubClient client(espClient);

// 变量：用于存储从串口接收到的数据
char inputBuf[256];
int inputLen = 0;
bool stringComplete = false;

// 初始化 Wi-Fi 连接
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("connecting wifi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Wi-Fi is OK");
  Serial.print("ESP32-C6 IP address: ");
  Serial.println(WiFi.localIP());
}

// MQTT 收到云端指令的回调函数
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("get cloud send message [");
  Serial.print(topic);
  Serial.print("]: ");
  
  Serial.write(payload, length);
  Serial.println();

  Serial1.write(payload, length);
  Serial1.println();
}

// MQTT 断线重连逻辑
void reconnect() {
  while (!client.connected()) {
    Serial.print("connecting MQTT server...");
    char clientId[40];
    snprintf(clientId, sizeof(clientId), "ESP32C6Client-%04X", (unsigned int)random(0, 0xffff));
    
    if (client.connect(clientId, mqtt_user, mqtt_pass)) {
      Serial.println("MQTT connecting is OK");
      client.subscribe(sub_topic);
    } else {
      Serial.print("error number is rc=");
      Serial.print(client.state());
      Serial.println(" Try again in 5 seconds...");
      delay(5000);
    }
  }
}

// 2. 新增函数：将解析出的数据封装为JSON并发布
// 将解析出的传感器数据封装为指定的 JSON 格式并发布
void publishSensorData(int temp, int hum, int adc, int mv, int LED_state) {
  char jsonBuf[200];
  snprintf(jsonBuf, sizeof(jsonBuf),
    "{\"temperature\":%d,\"humidity\":%d,\"light_adc\":%d,\"light_mv\":%d,\"led_state\":%d}",
    temp, hum, adc, mv, LED_state);

  Serial.print("Generated JSON: ");
  Serial.println(jsonBuf);

  if (client.publish(pub_topic, jsonBuf)) {
    Serial.println("MQTT PUT IS OK!");
  } else {
    Serial.println("MQTT PUT FAILED");
  }
}

void setup() {
  // 初始化调试串口（连电脑）
  Serial.begin(115200);
  
  // 初始化通信串口（连大开发板）
  Serial1.begin(115200, SERIAL_8N1, RX1_PIN, TX1_PIN);

  // 初始化网络
  setup_wifi();
  
  // 设置 MQTT 服务器及回调
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  
  Serial.println("Initialization complete. Waiting for data");
}

void loop() {
  // 1. 确保 Wi-Fi 和 MQTT 保持连接
  if (!client.connected()) {
    reconnect();
  }
  client.loop(); // 维持 MQTT 心跳机制

  // 2. 检查是否有来自串口的数据
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      stringComplete = true;
    } else if (inChar != '\r') {
      if (inputLen < (int)sizeof(inputBuf) - 1) {
        inputBuf[inputLen++] = inChar;
      }
    }
  }

  // 3. 处理并中转串口数据到 MQTT 云端
  if (stringComplete) {
    inputBuf[inputLen] = '\0';

    char *end = inputBuf + inputLen - 1;
    while (end >= inputBuf && (*end == ' ' || *end == '\t' || *end == '\r' || *end == '\n')) {
      *end-- = '\0';
    }
    char *data = inputBuf;
    while (*data == ' ' || *data == '\t') data++;

    if (*data != '\0') {
      Serial.print("Get raw data: ");
      Serial.println(data);

      size_t len = strlen(data);
      if (data[0] == '$' && data[len - 1] == '#') {
        int val1, val2, val3, val4, va15;
        int parsedItems = sscanf(data, "$%d,%d,%d,%d,%d#", &val1, &val2, &val3, &val4, &va15);

        if (parsedItems == 5) {
          Serial.printf("Parsed data: %d, %d, %d, %d, %d\n", val1, val2, val3, val4, va15);
          publishSensorData(val1, val2, val3, val4, va15);
        } else {
          Serial.println("Error: Data format is incorrect.");
        }
      } else {
        Serial.println("Error: Data does not start with '$' or end with '#'.");
      }
    }

    inputLen = 0;
    stringComplete = false;
  }
}