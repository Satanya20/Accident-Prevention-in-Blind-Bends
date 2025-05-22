A microcontroller-based safety system designed to prevent vehicle collisions on blind bends (curves with limited visibility). This project uses ultrasonic sensors and NRF24L01 wireless modules to detect approaching vehicles from either side of a bend and control traffic signals to alert drivers in real time.

## Project Objectives

- Detect vehicles approaching from both sides of a **blind curve**.
- Wirelessly communicate vehicle presence between two ends of the bend.
- Trigger **traffic lights** to notify drivers and prevent head-on collisions.
- Simulate and validate the system in **Proteus** before physical implementation.

## Technologies Used

- **Microcontroller**: ATmega328P (Arduino Uno)
- **Programming**: Arduino IDE (C/C++)
- **Simulation**: Proteus
- **Wireless Module**: NRF24L01 (2.4GHz RF transceiver)
- **Sensors**: HC-SR04 Ultrasonic Distance Sensor
- **Indicators**: LEDs or Traffic Light Model


## Key Features

### Vehicle Detection
- **Ultrasonic sensors** placed on either side of the bend measure distance.
- Vehicles within a defined threshold (e.g., < 1 meter) are detected in real time.

### Wireless Communication
- When a vehicle is detected, a **signal is sent via NRF24L01** to the opposite end of the bend.
- This enables **coordinated traffic control** without needing physical wiring across the bend.

### Traffic Light Control
- LEDs or signal lights are used to **warn vehicles** on the other side of the curve.
- Lights turn red when a vehicle is approaching, and green otherwise.

### Simulation & Testing
- The entire system was modeled and tested using **Proteus** to validate timing, signal transmission, and system logic.


## System Workflow
```text
Vehicle A Detected at Side A
            ↓
Signal Sent via NRF24L01 to Side B
            ↓
Traffic Light at Side B Turns Red
            ↓
Wait Until Vehicle A Passes
            ↓
Traffic Light Turns Green
