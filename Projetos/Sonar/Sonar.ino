/*
{
  // Configurações
  display.clearDisplay();  // all pixels are off
  display.display();       // call this method for the changes to make effect
  display.invertDisplay(true);

  // Desenhando Formas
  display.drawPixel(x, y, color);             // plot a pixel in the x,y coordinates
  display.drawLine(l_x, l_y, x2, y2, color);  // method to create a line

  display.drawRect(x, y, width, height, color);     // provides an easy way to draw a rectangle
  display.drawRoundRect(10, 10, 30, 50, 2, WHITE);  // provides an easy way to draw a rectangle

  display.fillRect(x, y, width, height, color);     // to draw a filled rectangle
  display.fillRoundRect(10, 10, 30, 50, 2, WHITE);  // to draw a filled rectangle

  display.drawCircle(x, y, radius, color);  // the (x,y) coordinates indicate the center of the circle
  display.fillCircle(64, 32, 10, WHITE);

  display.drawTriangle(l_x, l_y, x2, y2, x3, y3, color);  // method to build a triangle. This method accepts as arguments the coordinates of each corner and the color.
  display.fillTriangle(l_x, l_y, x2, y2, x3, y3, color);  // method to build a triangle.


  // Textos
  display.setTextSize(n);    // set the font size, supports sizes from 1 to 8
  display.setCursor(x, y);   // set the coordinates to start writing text
  display.print(“message”);  // print the characters at location x,y

  // Coordernadas
  startscrollright(0x00, 0x0F);      // scroll text from left to right
  startscrollleft(0x00, 0x0F);       // scroll text from right to left
  startscrolldiagright(0x00, 0x07);  // scroll text from left bottom corner to right upper corner
  startscrolldiagleft(0x00, 0x07);   // scroll text from right bottom corner to left upper corner
}
*/

// Biblioteca motor
#include <Servo.h>

// Biblioteca Visor
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
int pos = 0;
int timer = 70;
long duration;
float distance_cm;
double x, y;

// Define steering gear objects, up to eight
Servo myservo;
// Define the steering position of the steering gear

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myservo.attach(3);  // Set the servo control pin
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }

  display.setFont(&FreeMono9pt7b);  // Set font
  display.setTextColor(WHITE);      // set the font color
  display.setTextSize(1);           // set the font size, supports sizes from 1 to 8
}

void loop() {

  return_base();
  tragetoria();
}

// ---------------- TRAGETORIA SONAR ---------------

void tragetoria() {
  int pos = 0;
  for (int x = 17; x <= 107; x++) {
    // display.clearDisplay();
    // display.display();
    display(x);

    delay(150);
    pos += 2;
  }
  for (int x = 107; x >= 17; x--) {
    // display.clearDisplay();
    // display.display();
    display(x);

    delay(150);
    pos -= 2;
  }
}

// ----------------  ---------------

void display(int x) {

  posit_calcule(x);
  myservo.write(pos);
  setDisplay();
  display.display();
}


// ---------------- CALULANDO AS CORDENADAS ---------------

void posit_calcule(int x) {

  int cos = ((x - 45) - 17);
  int y = -(round(sqrt(abs((pow(cos, 2) - pow(45, 2))))) - 62);
  float dist_base = 20;
  float distanc = round(get_Distanc());

  if (distanc < dist_base) {
    float porcent = (distanc / dist_base);
    int l_x = (((64 - x) * porcent) + x);
    int l_y = (((61 - y) * porcent) + y);
    display.drawLine(64, 61, l_x, l_y, WHITE);
    //display.drawPixel(x, y, color);  // plot a pixel in the x,y coordinates

  } else {
    // display.drawLine(64, 61, x, y, WHITE);
  }
}

// ---------------- RETORNO BASE ---------------

void return_base() {
  int loca = myservo.read();
  display.invertDisplay(true);
  display.clearDisplay();
  display.display();
  if (loca != 0) {

    for (loca; loca > 0; loca--) {
      myservo.write(loca);
      delay(20);
    }
    display.invertDisplay(false);
    display.display();
  } else {
    return;
  }
}

// ---------------- DESENHANDO VISOR ---------------

void draw_tela() {
  display.drawLine(0, 14, 128, 14, WHITE);  // method to create a line

  display.drawCircle(62, 61, 45, WHITE);      // the (x,y) coordinates indicate the center of the circle
  display.drawLine(17, 62, 17, 63, BLACK);    // method to create a line
  display.drawLine(107, 62, 107, 63, BLACK);  // method to create a line

  display.drawLine(15, 62, 55, 62, WHITE);              // method to create a line
  display.drawLine(73, 62, 109, 62, WHITE);             // method to create a line
  display.fillTriangle(59, 62, 69, 62, 64, 57, WHITE);  // method to build a triangle. This method accepts as arguments the coordinates of each corner and the color.
  display.drawPixel(64, 57, BLACK);
}

// ---------------- ESCREVENDO DISTANCIA ---------------

void setDisplay() {  // Integração do Valor da distancia com o desenho de escala

  float distanc = get_Distanc();
  printDistanc(distanc);  // Desenhando o valor (cm) da distancia
}

void printDistanc(float dist) {  // Recolhendo e posicionando o valor da distancia

  display.setCursor(3, 13);                // set the coordinates to start writing text
  display.print(String(dist, 1) + " cm");  // print the characters at location x,y
}

// ---------------- RECOLHIMENTO DISTANCIA ---------------

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