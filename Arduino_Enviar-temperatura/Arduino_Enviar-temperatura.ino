#include <DallasTemperature.h>
#include <OneWire.h>
#include "dht.h"

#define DHTPIN A1
#define DHTTYPE DHT11

dht DHT;

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

  Serial.print("\nTemperatura: ");
  Serial.print(celsius);
  Serial.print("°C");
  Serial.write("t"+(int)celsius);
}

void loggingHumidity() {
  DHT.read11(DHTPIN);
  Serial.print("\nUmidade: ");
  float u = DHT.humidity;
  Serial.print(u); //IMPRIME NA SERIAL O VALOR DE UMIDADE MEDIDO
  Serial.print("%");
  Serial.write("u"+(int)u);
}

void loop() {
  loggingTemperature();
  delay(1000);
  loggingHumidity();
  delay(1000);
}
