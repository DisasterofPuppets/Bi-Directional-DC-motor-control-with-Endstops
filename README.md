# Bi-Directional-DC-motor-control-with-Endstops
Control DC motor backwards and forwards with endstops

Based on https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/

I added endstops as this will end up being used to control my Gargoyle wing opening and closing.
At the moment the code simply goes back and forward between endstops. I will update it later to stop when the limit switch is triggered.
Movement will likely be controlled by a joystick or some form of Bluetooth device.

Hardware required:
=================

Esp8266 (I'm using NodeMCU 1.0 (ESP-12E Module) as the Board)
L298N Motor Driver
2 x Limit switches
