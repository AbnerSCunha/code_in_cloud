#include <DallasTemperature.h>
#include <OneWire.h>

OneWire  ONEWIRE(10);
DallasTemperature sensor(&ONEWIRE);

int celsius;

void setup() {
  //inicializando o sensor DHT
  sensor.begin();

  //inicializando o monitor serial
  Serial.begin(9600);

}

void loggingTemperature() {
  sensor.requestTemperatures();
  celsius = sensor.getTempCByIndex(0);

  Serial.println(celsius);
  Serial.write(celsius);
}


void loop() {
  loggingTemperature();
  delay(2000);
}
