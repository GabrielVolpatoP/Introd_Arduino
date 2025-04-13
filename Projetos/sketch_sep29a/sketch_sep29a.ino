// Entradas

// Defina os pinos do sensor ultrassônico
#define trigPin 11
#define echoPin 0

#define a 6
#define b 2
#define c 10
#define d 12
#define e 13
#define f 5
#define g 9

// Posições
#define p1 8
#define p2 3
#define p3 4
#define p4 7

// Variáveis para armazenar o tempo de ida e volta do pulso ultrassônico
long duration;
int distance_cm;

unsigned long previousMillis = 0;     // Variável para armazenar o tempo anterior
const unsigned long interval = 1000;  // Intervalo desejado em milissegundos (1 segundo)


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  unsigned long currentMillis = millis();  // Obter o tempo atual

  // Verificar se o intervalo de tempo passou
  if (currentMillis - previousMillis >= interval) {
    // Faça algo aqui a cada intervalo de tempo
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
    distance_cm = (duration / 2) / 29.1;  // 29.1 µs/cm é a velocidade do som em ar a 20°C

    // Exiba a distância medida no monitor serial
    Serial.print("Distancia: ");
    Serial.print(distance_cm);
    Serial.println(" cm");


    previousMillis = currentMillis;  // Salvar o tempo atual como o anterior
  }

  setDisplay(distance_cm);
  // Seu código principal aqui
}

void setDisplay(unsigned int number) {

  String Str_number = String(number);  // Trasnforma o numero em string
  int legn_Str = Str_number.length();  // Recolhe o tamnho da String

  for (int i = 0; i < legn_Str; i++) {  // for que vai "desenha" os numeros no Display

    int Sn = (String(Str_number[i]).toInt());  // Valor do numero referente a sua casa
    setNum(i + 1, Sn);
    delayMicroseconds(50);
    setNum(i + 1, 10);
  }
}

void setNum(unsigned int pos, unsigned int num) {  // Junção entre as funções (Posição e Numero)
  getPosition(pos);
  getNumber(num);
}

void getPosition(unsigned int pos) {
  switch (pos) {

    // Posição (Milhar)
    case 4:
      digitalWrite(p1, LOW);
      digitalWrite(p2, HIGH);
      digitalWrite(p3, HIGH);
      digitalWrite(p4, HIGH);
      break;

    // Posição (Centenha)
    case 3:
      digitalWrite(p1, HIGH);
      digitalWrite(p2, LOW);
      digitalWrite(p3, HIGH);
      digitalWrite(p4, HIGH);
      break;

    // Posição (Dezana)
    case 2:
      digitalWrite(p1, HIGH);
      digitalWrite(p2, HIGH);
      digitalWrite(p3, LOW);
      digitalWrite(p4, HIGH);
      break;

    // Posição (Unidade)
    case 1:
      digitalWrite(p1, HIGH);
      digitalWrite(p2, HIGH);
      digitalWrite(p3, HIGH);
      digitalWrite(p4, LOW);
      break;

    // Posição padrão
    default:
      digitalWrite(p1, HIGH);
      digitalWrite(p2, HIGH);
      digitalWrite(p3, HIGH);
      digitalWrite(p4, HIGH);
  }
}

void getNumber(unsigned int num) {

  //digitalWrite(dp, LOW);
  switch (num) {
    case 0:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, LOW);
      break;
    case 1:
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      break;
    case 2:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH);
      break;
    case 3:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH);
      break;
    case 4:
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 5:
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 6:
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 7:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      break;
    case 8:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 9:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    default:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
  }
}
