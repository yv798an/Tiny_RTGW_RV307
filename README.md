# Tiny_RTGW_RV307

基于 **CH32V307（RISC-V）+ RT-Thread + LVGL** 的微型实时物联网网关（Tiny Real-Time GateWay）。

设备端采集温湿度与光照数据，在本地 LCD 上以仪表盘形式展示，并通过 UART → ESP32-C6 → MQTT → Web 的链路上云，实现远程数据监控与 LED 远程控制。

## 系统架构

```
 ┌──────────────────────┐   UART2    ┌──────────────┐   MQTT    ┌──────────────────┐
 │   CH32V307 边缘设备   │  115200bps │  ESP32-C6    │  1883     │  Flask Web 服务   │
 │  RT-Thread + LVGL     │◄──────────►│  Wi-Fi 网桥  │◄─────────►│  SocketIO + SQLite│
 │  DHT20 / 光敏 / LCD    │  $..#帧    │  UART↔MQTT   │  JSON     │  浏览器实时监控    │
 └──────────────────────┘            └──────────────┘           └──────────────────┘
        采集 + 显示 + 控制                  协议转换                    存储 + 可视化 + 下发
```

数据流：`传感器 → CH32V307 → UART → ESP32-C6 → MQTT → Web → 浏览器`
控制流：`浏览器 → Web → MQTT → ESP32-C6 → UART → CH32V307 → LED`

## 目录结构

| 目录 | 说明 |
| --- | --- |
| `Internet_Edge/` | CH32V307 边缘设备固件（RT-Thread + LVGL 工程） |
| `CH32v307_esp32/` | ESP32-C6 Arduino 网桥固件（UART ↔ MQTT） |
| `iot_web/` | Flask + SocketIO Web 后端与前端页面 |

### 边缘设备固件（`Internet_Edge/`）

| 模块 | 路径 | 功能 |
| --- | --- | --- |
| 主程序 | `User/main.c` | 初始化并创建 sensor / uart2 线程 |
| 传感器服务 | `equipment/sensor/` | 采集数据、线程共享数据、LED 状态管理 |
| DHT20 | `equipment/DHT20/` | 温湿度采集（I2C1） |
| ADC | `equipment/ADC/` | 光敏电压采集（通道 11，TIM3 100Hz 触发） |
| UART | `equipment/usart/` | UART2 收发 `$temp,hum,adc,mv,led#` 帧、解析 ON/OFF 指令 |
| GUI | `GUI/` | ILI9341 显示驱动 + LVGL 仪表盘 |

## 通信协议

### 上行数据帧（CH32V307 → ESP32-C6，UART）

```
$<temperature>,<humidity>,<light_adc>,<light_mv>,<led_state>#
例如：$26,55,2048,1650,1#
```

### 上云数据（ESP32-C6 → MQTT，JSON）

```json
{
  "temperature": 26,
  "humidity": 55,
  "light_adc": 2048,
  "light_mv": 1650,
  "led_state": 1
}
```

### 下行控制（Web → MQTT → ESP32-C6 → UART）

```json
{ "led": "ON" }    // 或 "OFF"
```

CH32V307 端解析 UART 数据中的 `ON` / `OFF` 关键字控制 LED（GPIOD Pin9）。

## 快速开始

### 1. 边缘设备（CH32V307）

使用 **MounRiver Studio (MRS)** 打开 `Internet_Edge/` 工程，编译并烧录到 CH32V307 开发板。

- LCD：ILI9341（SPI）
- 温湿度：DHT20（I2C1）
- 光敏：ADC1 通道 11（PC1）
- LED：GPIOD Pin9

### 2. Wi-Fi 网桥（ESP32-C6）

用 Arduino IDE 打开 `CH32v307_esp32/CH32v307_esp32.ino`，安装依赖库 `PubSubClient`，并配置以下参数后烧录：

```cpp
const char* ssid        = "your_wifi_name";   // 2.4GHz 热点
const char* password    = "wifi_pd";
const char* mqtt_server  = "broker.emqx.io";  // MQTT 服务器
const int   mqtt_port    = 1883;
const char* pub_topic    = "your/pub/topic";  // 数据发布主题
const char* sub_topic    = "your/sub/topic";  // 控制订阅主题
```

> 接线：ESP32-C6 `GPIO6(RX)`、`GPIO7(TX)` ↔ CH32V307 UART2。

### 3. Web 服务（iot_web）

```bash
pip install flask flask-socketio paho-mqtt
```

编辑 `iot_web/app.py`，填写与 ESP32-C6 一致的 MQTT 参数：

```python
MQTT_SERVER   = "broker.emqx.io"
MQTT_PORT     = 1883
MQTT_SUB_TOPIC = "your/pub/topic"   # 订阅设备上行数据
MQTT_PUB_TOPIC = "your/sub/topic"   # 下发控制指令
```

启动服务：

```bash
python app.py
```

浏览器访问 `http://<服务器IP>:5000` 查看实时仪表盘，支持：

- 温度 / 湿度 / 光照 ADC / 光照电压实时展示
- LED 远程开关控制
- 历史数据查询（`/history`，SQLite 存储）

## 技术栈

- **边缘设备**：CH32V307（RISC-V）、RT-Thread、LVGL v8.3、ILI9341
- **网桥**：ESP32-C6、Arduino、PubSubClient (MQTT)
- **云 / Web**：Python、Flask、Flask-SocketIO、paho-mqtt、SQLite
- **消息中间件**：MQTT（如 EMQX 公共 Broker）

## 许可证

本项目仅供学习与交流使用。
