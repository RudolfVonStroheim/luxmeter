#include <LiquidCrystalRus.h>
#include <TroykaLight.h>
#define s1 13
#define s2 12
#define s3 2
LiquidCrystalRus lcd (6, 7, 8, 9, 5, 11);
TroykaLight sensorLight(A0);
float light = 0.0;
bool MeterFlag = false;
float max_lightness = -99999.99999;
float min_lightness = 99999.99999;
float average_lightness = 0.0;

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
  if (digitalRead(s1) == LOW){
      if(MeterFlag){
        average_lightness = (min_lightness + max_lightness) / 2;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Avg lights: ");
        lcd.print(average_lightness);
        lcd.print("Lx\t");
        delay(10000);
        lcd.clear();
        lcd.setCursor(0, 0);
        max_lightness = -99999.99999;
        min_lightness = 99999.99999;
        MeterFlag = false;
      }
      else {
        MeterFlag = true;
      }
    }
  // вывод показателей сенсора освещённости в люксах
  lcd.print("Освещённость");
  lcd.setCursor(0, 1);
  light = sensorLight.getLightLux();
  lcd.print(light);
  lcd.print("Lx\t");
  lcd.clear();
  lcd.setCursor(0, 0);
  if (MeterFlag){
      if (light < min_lightness){
        min_lightness = light;
      }
      if (light > max_lightness){
        max_lightness = light;
      }
    }
  delay(1000);
}
