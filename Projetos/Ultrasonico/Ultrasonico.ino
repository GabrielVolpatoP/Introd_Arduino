// Defina os pinos do sensor ultrassônico
#define trigPin 11
#define echoPin 0

// Variáveis para armazenar o tempo de ida e volta do pulso ultrassônico
long duration;
int distance_cm;

void setup() {
  // Inicialize os pinos
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Inicialize a porta serial para exibir a distância
  Serial.begin(9600);
}

void loop() {
  // Limpe o pino TRIG
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Envie um pulso de 10 microssegundos no pino TRIG
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Leia o tempo de retorno do pulso no pino ECHO
  duration = pulseIn(echoPin, HIGH);

  // Calcule a distância em centímetros usando a fórmula: distância = (tempo x velocidade do som) / 2
  distance_cm = (duration / 2) / 29.1; // 29.1 µs/cm é a velocidade do som em ar a 20°C

  // Exiba a distância medida no monitor serial
  Serial.print("Distancia: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  // Aguarde um curto período de tempo antes de fazer a próxima leitura
  delay(1000);
}
