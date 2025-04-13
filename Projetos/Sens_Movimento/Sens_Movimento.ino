// Define o pino do sensor PIR
int sensorPin = 2;

// Define o pino Relé
int rele = 7;

// Define o pino do LED
int ledPin_M = 4;
int ledPin_S = 3;

// Define uma variável para armazenar o estado do sensor
int motionState = 1;

void setup() {
  // Inicializa o pino do sensor como entrada
  pinMode(sensorPin, INPUT);
  
  // Inicializa o pino do LED como saída
  pinMode(ledPin_M, OUTPUT);
  pinMode(ledPin_S, OUTPUT);
  // Inicializa o pino do Relé como saída
  pinMode(rele, OUTPUT);  

  // Inicializa a comunicação serial para depuração
  Serial.begin(9600);
}

void loop() {
  
  // Lê o estado do sensor
  motionState = digitalRead(sensorPin);

  // Verifica se o sensor detectou movimento
  
  if (motionState == HIGH) {
    Charc(1);
    digitalWrite(rele, LOW);

    for (int i=0; i <= 5; i++){
      motionState = digitalRead(sensorPin);
      if (motionState == HIGH) {
        i = 0;
      }
      delay(1000);
      Serial.println("Movimento detectado!" + String(i));
    }
    
  } else {
    digitalWrite(rele, HIGH);
    Serial.println("Nenhum movimento detectado.");
    Charc(0);
  }
  
  // Aguarda um curto período de tempo antes de verificar novamente
  delay(300);
}

void Charc(boolean led_switch) {
  digitalWrite(ledPin_M, led_switch);
  
  digitalWrite(ledPin_S, !led_switch);
}