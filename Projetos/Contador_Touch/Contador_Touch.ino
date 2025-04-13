// Entradas
int sens = 11;

int a = 6;
int b = 2;
int c = 10;
int d = 12;
int e = 13;
int f = 5;
int g = 9;

// Posições
int p1 = 8;
int p2 = 3;
int p3 = 4;
int p4 = 7;

int cont = 0;

void setup() {
  pinMode(sens, INPUT);

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


  
  setNum(1, 3);
  delay(3);
  setNum(2, 3);
  delay(3);
  setNum(3, 5);
  delay(3);

  /*
  if (Press()) {  // Quando pressionado "corretamente"
    cont++;       // Soma a contagem de "clicks"
    setDisplay(cont);
  } else {  // Quando não pressionado
    setDisplay(cont);
  }
  
  */

}

bool Press() {
int t = 0;
  // Reconhecedor do Sensor, limitante
  if (digitalRead(sens) == HIGH) {
    
    for (t; t <= 120 || digitalRead(sens) == LOW; t++) {  // t = tempo nessesario para a pressionar o sensor.
      setDisplay(cont);
    }
    return true;  // Retorna true quando o tempo for comprido.

  } else {
    t = 0;
    return false;  // Retorna falso caso o tempo nao tenha sido comcluido
  }
}

void setDisplay(unsigned int number) {

  String Str4 = String(number);   // Trasnforma o numero em string
  int legn_Str4 = Str4.length();  // Recolhe o tamnho da String

  for (int i = 0; i < legn_Str4; i++) {  // for que vai "desenha" os numeros no Display

    int Sn = (String(Str4[i]).toInt());  // Valor do numero referente a sua casa
    setNum(i + 1, Sn);
    delay(5);  // Contador de delay relacionado a quatidade de casa do parametro
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
