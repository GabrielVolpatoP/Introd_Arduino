#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

char telas[3];
int atual_tela = 0;
int eixo_Y = A0;  //Saída analógica (Eixo X)
int eixo_X = A1;  //Saída analógica (Eixo Y)
int botao = 2;    //Saída digital do botão (Eixo Z)

int led_vemelho = 11;
int led_verde = 10;

int ptc_vermelho = 5;
int ptc_verde = 5;


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);  // DIMENÇÂO DA TELA
  lcd.setBacklight(HIGH);
  pinMode(botao, INPUT_PULLUP);  //Define botao como entrada e em modo PULL UP, ou seja, lê HIGH quando o botão não estiver pressionado

  pinMode(led_verde, OUTPUT);
  pinMode(led_vemelho, OUTPUT);
}

void tela(int i) {

  lcd.setCursor(0, 0);

  if (i == 0) {
    lcd.print("Desligar");
    atual_tela = 0;
  } else {
    if (i == 1) {
      lcd.print("Vermelho");
      lcd.setCursor(6, 1);
      lcd.print(ptc_vermelho);

      atual_tela = 1;
    } else {
      if (i == 2) {
        lcd.print("Verde");
        lcd.setCursor(6, 1);
        lcd.print(ptc_verde);

        atual_tela = 2;
      } else {
        lcd.print("erro");
      }
    }
  }
}

void Potencia_led(bool j) {

  if (j == true) {  // Vermelho

    if (atual_tela == 1) {
      if (ptc_vermelho <= 245) {
        ptc_vermelho += 10;
      }

    } else if (atual_tela == 2) {
      if (ptc_verde <= 245) {
        ptc_verde += 10;
      }
    }

  } else {

    if (atual_tela == 1) {
      if (ptc_vermelho >= 15) {
        ptc_vermelho -= 15;
      } else {
        ptc_vermelho = 0;
      }

    } else if (atual_tela == 2) {
      if (ptc_verde >= 15) {
        ptc_verde -= 15;
      } else {
        ptc_verde = 0;
      }
    }
  }

  delay(300);
  lcd.clear();
}

void troca_telas(bool j) {

  if (j == true) {
    if (atual_tela == 2) {
      atual_tela = -1;
    }
    atual_tela += 1;
    tela(atual_tela);
  } else {
    if (atual_tela == 0) {
      atual_tela = 3;
    }
    atual_tela -= 1;
    tela(atual_tela);
  }

  lcd.clear();
  delay(100);
}

void ligar_led() {
  
  if (atual_tela == 0) {
    analogWrite(led_vemelho, LOW);
    analogWrite(led_verde, LOW);
  }
  if (atual_tela == 1) {
    analogWrite(led_vemelho, ptc_vermelho);  // 0 to 255
  }
  if (atual_tela == 2) {
    analogWrite(led_verde, ptc_verde);  // 0 to 255
  }
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  telas[0] = "Default";
  telas[1] = "Vermelhor";
  telas[2] = "Verde";

  tela(atual_tela);

  if ((analogRead(eixo_X)) == 0) {  //SE LEITURA FOR IGUAL A 0, FAZ
    Potencia_led(true);
    //delay(500);

  } else {
    if ((analogRead(eixo_X)) == 1023) {  //SE LEITURA FOR IGUAL A 1023, FAZ
      Potencia_led(false);
      //delay(500);

    } else {
      if ((analogRead(eixo_Y)) == 0) {  //SE LEITURA FOR IGUAL A 0, FAZ
        troca_telas(true);  

      } else {
        if ((analogRead(eixo_Y)) == 1023) {  //SE LEITURA FOR IGUAL A 1023, FAZ
          troca_telas(false);  
        } else {
          
          if (digitalRead(botao) == LOW) {  //SE LEITURA FOR IGUAL A HIGH, FAZ
            ligar_led();                    
          }
        }
      }
    }
  }
}
