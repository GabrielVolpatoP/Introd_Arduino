#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

int sens = 7;


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2); // DIMENÇÂO DA TELA
  lcd.setBacklight(HIGH);
  pinMode(sens, INPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(sens)==HIGH) {
    lcd.setCursor(0,0);
    lcd.print("NAUM ME APERTA!");
    lcd.setCursor(4,2);
    lcd.print(">////<");
    delay(2000);
    lcd.clear();
  } else {
    lcd.setCursor(0,0);
    lcd.print("Olha Humano!");
    delay(2000);
    lcd.clear();
  }


}
