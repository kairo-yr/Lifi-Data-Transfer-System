# Light Data Transfer System

This project demonstrates a light-based data transfer system using two Arduino Uno boards. An LED on the left Arduino transmits data through light pulses, while an LDR sensor on the right Arduino receives and decodes the data, displaying the keypress on an LCD screen.

## Components
- 2 x Arduino Uno
- 1 x Keypad
- 1 x LED
- 1 x Light Dependent Resistor (LDR)
- 1 x LCD Display (16x2)
- Jumper wires

## Project Structure
lifedata-transfer-system
├── LeftArduino
│   └── LeftArduino.ino    
├── RightArduino
│   └── RightArduino.ino   


## Setup Instructions

1. **Left Arduino**: 
   - Connect the keypad to pins 2-9.
   - Connect the LED to pin 10.

2. **Right Arduino**:
   - Connect the LDR sensor to analog pin A0.
   - Connect the LCD to digital pins 2, 3, 4, 5, 11, and 12.

3. Upload `LeftArduino.ino` to the left Arduino and `RightArduino.ino` to the right Arduino.

## How It Works
1. The left Arduino takes input from the keypad.
2. Each keypress has a unique binary code; `1` indicates a blink, and `0` indicates no blink.
3. The LED blinks in the specific pattern, which the LDR on the right Arduino detects.
4. The right Arduino decodes the blinks and displays the key pressed on the LCD.

## Usage
1. Power both Arduino boards.
2. Press keys on the keypad. The LED will blink based on the binary code for each key.
3. The LDR sensor on the right Arduino reads the blinks and displays the corresponding key on the LCD.

## License
This project is open-source and licensed under the MIT License.
