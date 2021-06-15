#include <Arduino.h>
#include "CSensorAdafruit_VL53L0X.h"

#include "Adafruit_VL53L0X.h"
#include "Ticker.h"

Ticker m_CallTickerSensor;

void attachTimerToSensor()
{
  m_CallTickerSensor.attach_ms(75, CSensorAdafruit_VL53L0X::doMeasure);
}

void setup()
{
    //On Nodemcu:
    //SCL D1 
    //SDA D2

    // IMPORTANT NOTE
    // Note if the sensor Init failed - try to reset VCC (3V) to sensor 
    
    CSensorAdafruit_VL53L0X sensor;
    Serial.begin(115200);
    sensor.initLongRange();
    delay(100);
    attachTimerToSensor();
    delay(100);
}

void loop()
{
    Serial.println(CSensorAdafruit_VL53L0X::getMeasureValue());

}
