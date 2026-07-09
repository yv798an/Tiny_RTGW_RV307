# 基于 CH32V307 + ESP32-C6 的智能物联网网关系统

## 项目简介

本项目实现了一套完整的端到端物联网数据采集与监控系统，采用 **CH32V307 + RT-Thread** 作为底层数据采集节点，结合 **ESP32-C6 WiFi通信模块**构建边缘网关，通过 **MQTT协议**实现设备数据上传，并使用 **Python + Flask + WebSocket** 搭建实时Web监控平台。

系统实现了从传感器采集、串口通信、串口控制、数据协议转换、MQTT云端传输，到Web实时可视化的完整数据链路。

---

## 系统架构

```
          Sensors
             |
             |
      CH32V307 MCU
       (RT-Thread)
             |
             | UART
             |
        ESP32-C6
   (WiFi Gateway + JSON)
             |
             | MQTT
             |
      MQTT Broker
             |
             |
      Python Backend
   (MQTT Subscriber)
             |
             | WebSocket
             |
        Flask Web
     Real-time Dashboard
```

---

## 功能特点

### 1. 嵌入式数据采集节点

基于 CH32V307 RISC-V MCU：

- 移植并运行 RT-Thread 实时操作系统
    
- 使用线程化架构管理传感器任务
    
- 实现传感器数据采集服务
    
- 采用模块化驱动设计
    

目前支持：

- DHT20 温湿度传感器
    
- ADC光照强度采集
    

采集数据示例：

```
Temperature: 27℃
Humidity: 71%
Light ADC: 36
Light Voltage: 29mV
```

---

### 2. MCU间串口通信

CH32V307通过UART向ESP32-C6发送传感器数据。

自定义轻量级通信协议：

```
$temperature,humidity,light_adc,light_mv,LED_state#
```

示例：

```
$27,71,36,29,0#
```

ESP32-C6负责接收、解析并转换为结构化数据。

---

### 3. ESP32-C6边缘网关

ESP32-C6实现：

- WiFi联网
    
- UART数据接收
    
- 数据协议解析
    
- JSON格式转换
    
- MQTT消息发布
    

JSON示例：

```json
{
    "temperature": 27,
    "humidity": 71,
    "light_adc": 36,
    "light_mv": 29,
    "led_state": 0
}
```

---

### 4. MQTT物联网通信

采用MQTT作为设备通信协议。

实现：

- ESP32 MQTT Publisher
    
- Python MQTT Subscriber
    

数据Topic：

```
gateway/data/submit
```

实现设备端与服务器端的数据解耦，提高系统扩展能力。

---

### 5. Python Web监控平台

后端采用：

- Python
    
- Flask
    
- Flask-SocketIO
    
- Paho MQTT
    

功能：

- MQTT实时数据订阅
    
- JSON数据解析
    
- WebSocket实时推送
    
- 浏览器实时数据显示
    

网页实时显示：

- 温度
    
- 湿度
    
- 光照强度
    

---

## 软件架构

```
Embedded Layer

CH32V307
 |
 RT-Thread
 |
 Sensor Service


Gateway Layer

ESP32-C6
 |
 UART Parser
 |
 JSON Encoder
 |
 MQTT Client


Application Layer

Python
 |
 MQTT Client
 |
 Flask
 |
 Socket.IO


Frontend

HTML
JavaScript
```

---

## 技术栈

### Embedded

- CH32V307
    
- RISC-V MCU
    
- RT-Thread RTOS
    
- UART
    
- I2C
    
- ADC
    
- Sensor Driver Development
    

### IoT Communication

- MQTT
    
- JSON
    
- WiFi
    
- ESP32-C6
    

### Backend

- Python
    
- Flask
    
- Flask-SocketIO
    
- Paho MQTT
    

### Frontend

- HTML
    
- JavaScript
    
- WebSocket
    

---

## 项目运行流程

1. CH32V307启动RT-Thread系统
    
2. 传感器线程周期采集数据
    
3. 通过UART发送采集结果
    
4. ESP32-C6接收并解析数据
    
5. 转换为JSON格式
    
6. MQTT上传至Broker
    
7. Python后台订阅MQTT消息
    
8. Flask通过WebSocket推送数据
    
9. 浏览器实时显示传感器状态
    

---

## 后续计划

-  增加InfluxDB时序数据库存储
    
-  集成Grafana数据可视化
    
-  增加设备在线状态管理
    
-  完善MQTT QoS机制
    
-  增加远程参数配置功能
    
-  使用Docker完成服务部署
    

---

## 项目意义

本项目模拟真实工业物联网系统的数据链路设计，实现了从底层嵌入式设备到云端应用的完整闭环。

通过该项目实践了：

- MCU底层驱动开发
    
- RTOS任务管理
    
- 嵌入式通信协议设计
    
- IoT网关开发
    
- MQTT物联网通信
    
- 后端服务开发
    
- Web实时数据可视化
    

该系统可进一步扩展为智能家居、工业监测、环境监控等物联网应用平台。
