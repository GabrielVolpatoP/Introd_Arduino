// Incluindo bibliotecas necessárias
// https://docs.arduino.cc/learn/electronics/lcd-displays#text-direction-example

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int del=250;

void setup() {  // inicia o void setup

  lcd.begin(16, 2);        // Dimensão da tela
  lcd.setBacklight(HIGH);  //Liga a luz de fundo
  lcd.print("hello, world!");
}

void loop() {  // inicia o void loop
/*
  lcd.setCursor(0, 0);  // coluna 0, linha 0
  lcd.print("Texto");   // Insira seu texto Aqui, dentro das Aspas
  delay(5000);          // Espera de 5 segundos

  lcd.clear();  // apaga o texto escrito no Display

  lcd.setCursor(0, 0);  // coluna 0, linha 0
  lcd.print("Texto2");   // Insira seu texto aqui, dentro das Aspas

  delay(5000);  // Espera de 5 segundos
  lcd.clear();  // apaga o texto escrito no Display
*/
  
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(del);
  }

  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(del);
  }

  // scroll 16 positions (display length + string length) to the left
  // to move it back to center:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(del);
  }
}