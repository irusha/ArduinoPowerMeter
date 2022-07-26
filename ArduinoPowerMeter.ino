#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

float energy = 0.0;
bool ledOn = LOW;
void setup()
{
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    pinMode(13, OUTPUT);
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
}

void loop()
{
    digitalWrite(13, ledOn);
    ledOn = !ledOn;    
    float digitalReadToVolts = 0.02587890625;
    float voltage = 0.0;
    float current = 0.0;
    int i = 0;
    while (i < 250)
    {

        current = current + (analogRead(A0) * 0.0264 - 13.51) / 250;
        voltage = voltage + analogRead(A1) * digitalReadToVolts / 250;
        i++;
        delay(1);
    }
    if (current < 0)
    {
        current = 0;
    }

    if (voltage < 0.09){
      voltage = 0;
    }
    
    float power = current * voltage;
    float hoursPerQuaterSeconds = 0.00006944;

    energy = energy + power * hoursPerQuaterSeconds;

    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    // Display static text
    display.print(F("Power:"));
    display.print(power, 0);
    display.print(F("W"));
    display.setCursor(0, 27);
    display.setTextSize(2);
    // For one decimal place
    display.print(voltage, 1);
    display.print(F("V"));
    display.setCursor(68, 27);
    float test = 0;
    display.print(current);
    display.print(F("A"));
    display.setCursor(0, 55);
    display.setTextSize(1);
    display.print(F("Energy: "));
    display.print(energy);
    display.print(F("Wh"));
    display.display();
}