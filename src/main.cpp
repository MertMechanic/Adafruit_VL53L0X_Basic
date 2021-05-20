#include <Arduino.h>
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
    //On Nodemcu:
    //SCL D1 
    //SDA D2
    
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



