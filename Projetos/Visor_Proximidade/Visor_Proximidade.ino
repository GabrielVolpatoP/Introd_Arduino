#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeMono9pt7b.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define trigPin 11
#define echoPin 9

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Declaração de Variáveis
const int timer = 2000;
long duration;
float distance_cm;


void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  display.clearDisplay();

  display.setFont(&FreeMono9pt7b);  // Set font
  display.setTextColor(WHITE);      // set the font color
  display.setTextSize(1);           // set the font size, supports sizes from 1 to 8
}

void loop() {  // _________________________________________________

  setDisplay();
  delayMicroseconds(1000);
  display.clearDisplay();
}

// =============================================================

void setDisplay() {  // Integração do Valor da distancia com o desenho de escala

  float distanc = get_Distanc();
  printDistanc(distanc);  // Desenhando o valor (cm) da distancia
  drawScale(distanc);     // Desenhando a escala auxiliar
  display.display();      // Exibindo a distancia (cm) e o desenho auxilidar escalar
}


void drawScale(float escala) {  // Interpretador da Distancia para a Escala
  if (escala > 40.0) {
    // Condição:

  } else if (escala > 35.0) {
    // Condição:
    drawEscala(1);
  } else if (escala > 30.0) {
    // Condição:
    drawEscala(2);
  } else if (escala > 25.0) {
    // Condição:
    drawEscala(3);
  } else if (escala > 20.0) {
    // Condição:
    drawEscala(4);
  } else if (escala > 15.0) {
    // Condição:
    drawEscala(5);
  } else if (escala > 10.0) {
    // Condição:
    drawEscala(6);
  } else if (escala > 05.0) {
    // Condição:
    drawEscala(7);
  } else {
    // Condição:
    drawEscala(8);
  }
  display.display();
}

void printDistanc(float dist) {  // Recolhendo e posicionando o valor da distancia

  display.setCursor(3, 13);                // set the coordinates to start writing text
  display.print(String(dist, 1) + " cm");  // print the characters at location x,y
}

float get_Distanc() {
  // Limpe o pino TRIG
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Envie um pulso de 10 microssegundos no pino TRIG
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Leia o tempo de retorno do pulso no pino ECHO
  duration = pulseIn(echoPin, HIGH);

  // Calcule a distância em centímetros usando a fórmula: distância = (tempo x 2) / velocidade do som
  distance_cm = (duration / 2) / 30.8;  // 29.1 µs/cm é a velocidade do som em ar a 20°C
  return distance_cm;
}

void drawEscala(unsigned int size) {
  switch (size) {

    case 8:  // Distancia Menores que 5
      // Quarto retangulo

      display.invertDisplay(true);
      display.fillRect(111, 20, 10, 40, WHITE);
      delay(200);
      display.invertDisplay(false);

    case 7:  // Distancia entre (10) e (5)
      // Quarto retangulo vazio
      display.drawRect(111, 20, 10, 40, WHITE);

    case 6:  // Distancia entre (15) e (10)
      // Terceiro retangulo
      display.fillRect(93, 30, 10, 30, WHITE);

    case 5:  // Distancia entre (20) e (15)
      // Terceiro retangulo vazio
      display.drawRect(93, 30, 10, 30, WHITE);

    case 4:  // Distancia entre (25) e (20)
      // Segundo retangulo
      display.fillRect(76, 40, 10, 20, WHITE);

    case 3:  // Distancia entre (30) e (25)
      // Segundo retangulo vazio
      display.drawRect(76, 40, 10, 20, WHITE);

    case 2:  // Distancia entre (35) e (30)
      // Primeiro retangulo
      display.fillRect(59, 50, 10, 10, WHITE);

    case 1:  // Distancia entre (40) e (35)
      // Primeiro retangulo vazio
      display.drawRect(59, 50, 10, 10, WHITE);

    case 0:  // Distancia maiores que 40
      // Nada desenhado
      break;

    default:
      break;
  }
}