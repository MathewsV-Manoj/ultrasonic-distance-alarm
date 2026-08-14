# Ultrasonic Distance Alarm

An Arduino learning project that reads an HC-SR04 ultrasonic sensor and warns when something gets too close.

## Hardware

- Arduino Uno or compatible board
- HC-SR04 ultrasonic sensor
- Piezo buzzer
- Optional LED

## Wiring

- HC-SR04 TRIG to D9
- HC-SR04 ECHO to D10
- Buzzer positive to D6
- LED to D13 or use the built-in LED
- All grounds connected together

## Run it

Upload ultrasonic_distance_alarm.ino, then open the Serial Monitor at 9600 baud. Adjust warningDistanceCm to tune the alarm range.

Use a voltage divider on the HC-SR04 ECHO line when connecting it to a 3.3 V microcontroller.