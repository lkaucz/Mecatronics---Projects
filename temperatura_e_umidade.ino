#include "DHT.h"
 
#define DHTPIN A1 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11
 
// Conecte pino 1 do sensor (esquerda) ao +5V
// Conecte pino 2 do sensor ao pino de dados definido em seu Arduino
// Conecte pino 4 do sensor ao GND
// Conecte o resistor de 10K entre pin 2 (dados) 
// e ao pino 1 (VCC) do sensor
DHT dht(DHTPIN, DHTTYPE);
int pot = A3;
int valor = 0;

void setup() 
{
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();
}
 
void loop() 
{
  // A leitura da temperatura e umidade pode levar 250ms!
  // O atraso do sensor pode chegar a 2 segundos.
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  valor = (analogRead(pot)/34.1)+20;
  // testa se retorno é valido, caso contrário algo está errado.
  if (isnan(t) || isnan(h)) 
  {
    Serial.println("Failed to read from DHT");
  } 
  else
  {
    Serial.print(" Umidade: ");
    Serial.print(h);
    Serial.print(" %t");
    Serial.print(" Temperatura: ");
    Serial.print(t);
    Serial.println(" *C");
    Serial.print(" Temperatura escolhida: ");
    Serial.print(valor);
    Serial.print(" Temperatura erro: ");
    Serial.print(valor-t);
  };
  delay(1000);
}
