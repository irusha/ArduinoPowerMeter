# ArduinoPowerMeter

This simple circuit is made to display the power consumption, total energy used in the session, voltage and current on a SSD1306 OLED display. This code takes about 20kB flash memory. So please use atmega 328p or higher for this project. 

## What do you want to make this Powermeter?

* Arduino compatible Microcontroller board (such as Arduino nano, uno pro mini, etc.)
* SSD1306 Oled Display with 128x64 refresh rate
* Acs712 current sensor board
* Voltage regulator (7805 for an example or you can also use a premade buck converter)

## Final product

![bbbbbb](https://user-images.githubusercontent.com/78542929/181099927-60098ee5-0d40-4fd4-aa31-2a6e5a64f31b.jpg)
![aaa](https://user-images.githubusercontent.com/78542929/181099937-4122c689-d298-4caf-bf92-2b19b4f0eb23.jpg)

I used a cheap plastic box to contain all of the circuitry and I am using the powermeter to power my laptop. (As I have a dell laptop, I had to do some changes in the circuitry. But I don't state them here because they are unnecessary for the most of the users. Anyway feel free to send me an email for any clarification). 

## Limitations

* Since we are using a hall effect current sensor like acs712 and the atmega328p's built in ADC, The readings are not suitable for an accuracy crucial application. These should only be used for a reference. 
* Also the voltage readings are not dead accurate as we are using arduino ADC. Use it only as a reference value

# If anyone of the viewers made this powermeter, please let me know <3
