/* 

  // Usando:
  Lembre-se da biblioteca para incluir,
  Divisao do Amarelo para Azul é na x15 -> x16
  
  // Configurações 
  display.clearDisplay()  // all pixels are off
  display.display()       // call this method for the changes to make effect
  display.invertDisplay(true);

  // Desenhando Formas
  display.drawPixel(x, y, color)  // plot a pixel in the x,y coordinates
  display.drawLine(x1, y1, x2, y2, color) // method to create a line

  display.drawRect(x, y, width, height, color)  // provides an easy way to draw a rectangle
    display.drawRoundRect(10, 10, 30, 50, 2, WHITE);

  display.fillRect(x, y, width, height, color)    // to draw a filled rectangle
    display.fillRoundRect(10, 10, 30, 50, 2, WHITE);

  display.drawCircle(x, y, radius, color) // the (x,y) coordinates indicate the center of the circle
    display.fillCircle(64, 32, 10, WHITE);

  display.drawTriangle(x1, y1, x2, y2, x3, y3, color) // method to build a triangle. This method accepts as arguments the coordinates of each corner and the color.
    display.fillTriangle(x1, y1, x2, y2, x3, y3, color)


  // Textos
  display.setTextSize(n)    // set the font size, supports sizes from 1 to 8
  display.setCursor(x, y)   // set the coordinates to start writing text
  display.print(“message”)  // print the characters at location x,y

  // Coordernadas 
  startscrollright(0x00, 0x0F)      // scroll text from left to right
  startscrollleft(0x00, 0x0F)       // scroll text from right to left
  startscrolldiagright(0x00, 0x07)  // scroll text from left bottom corner to right upper corner
  startscrolldiagleft(0x00, 0x07)   // scroll text from right bottom corner to left upper corner

*/


#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif9pt7b.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Declaração de Variáveis
const int timer = 5000;

void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
}

void loop() {
  delay(2000);  // Pause for 2 seconds

  display.setFont(&FreeSerif9pt7b);  // Set font

  // Clear the buffer
  display.clearDisplay();
  // Tamanho da Fonte
  display.setTextSize(1);
  display.setTextColor(WHITE);
  // Posição
  display.setCursor(10, 20);
  display.println("Hello, world!");
  display.display();
  delay(timer);

  // Clear the buffer
  display.clearDisplay();
  // Tamanho da Fonte
  display.setTextSize(2);
  display.setTextColor(WHITE);
  // Posição
  display.setCursor(1, 20);
  display.println("Hello, world!");
  display.display();
  delay(timer);

  // Clear the buffer
  display.clearDisplay();

  // Draw a single pixel in white
  display.drawPixel(64, 32, WHITE);
  display.display();
  delay(timer);

  // Draw line
  display.clearDisplay();
  display.drawLine(0, 0, 127, 20, WHITE);
  display.display();
  delay(timer);

  // Draw rectangle
  display.clearDisplay();
  display.drawRect(30, 10, 50, 30, WHITE);
  display.display();
  delay(timer);

  // Fill rectangle
  display.fillRect(30, 10, 50, 30, WHITE);
  display.display();
  delay(timer);

  // Draw round rectangle
  display.clearDisplay();
  display.drawRoundRect(10, 10, 30, 50, 2, WHITE);
  display.display();
  delay(timer);

  // Fill round rectangle
  display.clearDisplay();
  display.fillRoundRect(10, 10, 30, 50, 2, WHITE);
  display.display();
  delay(timer);

  // Draw circle
  display.clearDisplay();
  display.drawCircle(64, 32, 10, WHITE);
  display.display();
  delay(timer);

  // Fill circle
  display.fillCircle(64, 32, 10, WHITE);
  display.display();
  delay(timer);

  // Draw triangle
  display.clearDisplay();
  display.drawTriangle(10, 10, 55, 20, 5, 40, WHITE);
  display.display();
  delay(timer);

  // Fill triangle
  display.fillTriangle(10, 10, 55, 20, 5, 40, WHITE);
  display.display();
  delay(timer);

  // Invert and restore display, pausing in-between
  display.invertDisplay(true);
  delay(timer);
  display.invertDisplay(false);
  delay(timer);
}