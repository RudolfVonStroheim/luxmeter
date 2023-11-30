#include <LiquidCrystalRus.h>
#include <TroykaLight.h>
#define s1 13
#define s2 12
#define s3 2
LiquidCrystalRus lcd (6, 7, 8, 9, 5, 11);
TroykaLight sensorLight(A0);
float light;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  pinMode(s3, INPUT_PULLUP);
  pinMode(s2, INPUT_PULLUP);
  pinMode(s1, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly
  sensorLight.read();
  // вывод показателей сенсора освещённости в люксах
  lcd.print("Освещённость");
  lcd.setCursor(0, 1);
  light = sensorLight.getLightLux() - calibrate;
  lcd.print(light);
  lcd.print("Lx\t");
  lcd.clear();
  lcd.setCursor(0, 0);
  delay(1000);
}
