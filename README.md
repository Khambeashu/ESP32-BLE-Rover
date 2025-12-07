{"variant":"document","title":"README for ESP32 BLE Rover","id":"24314"}
# ESP32 BLE Rover

This project is an **ESP32-based BLE motor control rover**. It demonstrates hands-on skills in **embedded systems**, **IoT**, and **BLE communication**, aimed at showcasing my capabilities as an aspiring Embedded Software Engineer.

## Features
- Forward, Backward, Left, Right, Stop motor control
- BLE communication using ESP32
- Debugging via Serial Monitor
- Modular and clean Arduino code for scalability

## Hardware Required
- ESP32 DevKit
- L293D motor driver module
- 2–4 DC motors
- External power supply for motors
- Jumper wires and breadboard

## Connections
| ESP32 Pin | Motor Driver Pin | Function |
|-----------|----------------|----------|
| 22        | EN             | Enable   |
| 27        | M1             | Motor 1  |
| 14        | M2             | Motor 1  |
| 12        | M3             | Motor 2  |
| 13        | M4             | Motor 2  |

## BLE Commands
| Command | Action      |
|---------|------------|
| F       | Forward    |
| B       | Backward   |
| L       | Left       |
| R       | Right      |
| S       | Stop       |

## How to Use
1. Upload the Arduino code to the ESP32.
2. Open Serial Monitor at 115200 baud to see real-time commands.
3. Connect a BLE-enabled mobile app to `ESP32-Rover`.
4. Send commands (`F`, `B`, `L`, `R`, `S`) to control the rover.

## About Me
Hi! I’m **Ashwini Khambe**, a passionate **Electronics & Telecommunication Engineer** with a strong interest in **Embedded Systems**, **IoT**, and **Robotics**. I enjoy building practical projects that combine **hardware and software** to solve real-world problems.  

I am actively learning and applying skills in:
- **Microcontrollers & Embedded Programming** (ESP32, Arduino, C/C++)
- **Wireless Communication & IoT Protocols** (BLE, MQTT)
- **Sensors & Actuators Integration** (Motors, DHT, GPS)
- **Software Debugging & Optimization**

My goal is to secure a position as an **Embedded Software Engineer** or **IoT Developer**, where I can contribute to innovative projects while continuously learning new technologies.  

This project is part of my professional portfolio, demonstrating:
- Real-time BLE communication for motor control
- Practical embedded software development
- Ability to integrate hardware and software in an IoT environment

## Author
**Ashwini Khambe**  
Aspiring Embedded Software Engineer | IoT Enthusiast
