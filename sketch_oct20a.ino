#include <OneWire.h>
#include <DallasTemperature.h>

#define WPIN A1
#define WPINp 4
#define phpin A0
#define phpinp 5
#define term_power 3 
#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  pinMode(WPINp, OUTPUT);
  pinMode(WPIN,INPUT);
  pinMode(term_power, OUTPUT);
  sensors.begin();
  Serial.begin(9600);
}

float temperature() { // Измеряем температуру 10 секунд
  digitalWrite(term_power, HIGH);                // Включаем питание датчика температуры
  delay(100);                                    // Задержка перед первым измерением 
  sensors.requestTemperatures();                 // Запрос на измерение температуры (1-й ошибочный)
  delay(500);                                    // Задержка перед поторным измерением
  sensors.requestTemperatures();                 // Запрос на измерение температуры (повторный)
  float t = float(sensors.getTempCByIndex(0));   // Получаем значение температуры
  digitalWrite(term_power, LOW);                 // Отключаем питание датчика температуры
  delay(9400);                                   // Задержка, чтобы датчик не нагревался от частых измерений
  return(t);                                     // Возвращаем значение температуры в место вызова функции
}

void loop() {
  digitalWrite(13, 1);                                                                                                                                                                                            
  delay(4000);
  digitalWrite(13, 0);
  digitalWrite(WPINp, 1);
  digitalWrite(phpinp, 1);
  int WaterLevel = analogRead(WPIN) / 10;
  float temperature_ = temperature();
  int phdat = analogRead(phpin);
  Serial.println("[" + String(WaterLevel) + "," + String(temperature_) + "," + String(phdat) + "]") ;
}
