#include <Arduino.h>
// #include "../../Adafruit_VL53L0X_Sensor/lib/Adafruit_VL53L0X/src/Adafruit_VL53L0X.h"

// Adafruit_VL53L0X lox = Adafruit_VL53L0X();

// int counterOfFailedMessures = 0;
// int maxFailedMeasure = 10;

// #include <Adafruit_NeoPixel.h>

// #define PIN D3

// // How many NeoPixels are attached to the Arduino?
// #define NUMPIXELS 12

// Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// int delayval = 250; // delay for half a second

// void resetled()
// {
//     for (int i = 0; i < NUMPIXELS; i++)
//     {
//         // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
//         pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Moderately bright green color.
//     }
// }

#include "CSensorAdafruit_VL53L0X.h"
#include "Ticker.h"

Ticker m_CallTickerSensor;


void attachTimerToSensor()
{
  m_CallTickerSensor.attach_ms(75, CSensorAdafruit_VL53L0X::doMeasure);
}

CSensorAdafruit_VL53L0X sensor = CSensorAdafruit_VL53L0X();
void setup()
{
    Serial.begin(115200);
    sensor.initLongRange();
    delay(100);
    attachTimerToSensor();
    delay(100);
}

void loop()
{
    // Serial.println(CSensorAdafruit_VL53L0X::getMeasureValue());

}



