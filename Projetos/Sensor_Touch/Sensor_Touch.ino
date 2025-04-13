const int touchSensorPin = 7;  // Pino digital conectado ao sensor de toque
const int ledPin = 1;         // Pino digital conectado ao LED
boolean interrup = 0; 

void setup() {
  pinMode(touchSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  //Serial.print(9600);
}

void loop() {
  int touchValue = digitalRead(touchSensorPin); // Lê o valor do sensor de toque

  if (touchValue == HIGH) { // Se o sensor for tocados
    swifth();
  }
}

void swifth(){


  interrup = !interrup;
  digitalWrite(ledPin, interrup);
  delay(1100);
  

}