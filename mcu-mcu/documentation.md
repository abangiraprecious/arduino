# Arduino Mega and Uno I2C Communication Documentation

This document provides a detailed guide on how to set up I2C communication between an Arduino Mega (master) and an Arduino Uno (slave). The setup includes a potentiometer connected to the master and an LED connected to the slave.

## Components Required

- **Arduino Mega (Master)**
- **Arduino Uno (Slave)**
- **Potentiometer** (10kΩ recommended)
- **LED** (any color)
- **220Ω Resistor** (for the LED)
- **Breadboard and Jumper Wires**
- **USB Cables** (for power and programming)

## Connections

### 1. I2C Communication Wiring

Connect the Arduino Mega and Arduino Uno for I2C communication as follows:

| **Arduino Mega** | **Arduino Uno** | **Description**       |
|------------------|----------------|-----------------------|
| Pin 20 (SDA)    | A4 (SDA)        | I2C Data Line        |
| Pin 21 (SCL)    | A5 (SCL)        | I2C Clock Line       |
| GND             | GND             | Common Ground        |

> **Note:** The Mega has dedicated SDA (Pin 20) and SCL (Pin 21) pins for I2C communication, while the Uno uses A4 (SDA) and A5 (SCL).

### 2. Potentiometer Wiring (Master - Mega)

Connect the potentiometer to the Arduino Mega as follows:

| **Potentiometer Pin** | **Arduino Mega** | **Description**            |
|-----------------------|-----------------|----------------------------|
| Pin 1 (Left Pin)      | GND             | Ground                     |
| Pin 2 (Middle Pin)    | A0              | Analog Input (Potentiometer) |
| Pin 3 (Right Pin)     | 5V              | 5V Power                   |

### 3. LED Wiring (Slave - Uno)

Connect the LED to the Arduino Uno as follows:

| **LED**            | **Arduino Uno** | **Description**                    |
|--------------------|----------------|------------------------------------|
| Anode (Long Leg)  | Pin 11          | PWM Output (via 220Ω resistor)    |
| Cathode (Short Leg) | GND            | Ground                            |

> **Note:** Use a **220Ω resistor** between the LED's anode and **Pin 11** to limit current.

### 4. Power Connections

- Power the Arduino Mega via **USB** or an external power source.
- Power the Arduino Uno via **USB** or through the **5V pin from the Mega** (if using a common power source).

## Circuit Diagram

Below is a simplified circuit diagram for the setup:

