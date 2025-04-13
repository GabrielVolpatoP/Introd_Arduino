#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Ultrasonic.h" // Esse comando é para incluir a biblioteca no programa

Ultrasonic ultrasonic (8,9); // são as portas do sensor, Trigger na porta 5 e Echo na porta 6  

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);
long microsec = 0; 
float distanciaCM = 0;


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2); // DIMENÇÂO DA TELA
  lcd.setBacklight(HIGH);

  Serial.begin(9600); // iniciando o monitor serial na velocidade 9600


}

void loop() { 

// lendo o sensor 
microsec = ultrasonic.timing(); 

// convertendo a distância para centímetros 

distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM); 
 

// mostrar a distância no monitor serial
Serial.print(microsec); 

// unidade de medida 

Serial.println(" cm");
delay(500);
}
