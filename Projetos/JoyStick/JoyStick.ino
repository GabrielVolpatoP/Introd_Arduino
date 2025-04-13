int eixo_Y = A0;  //Saída analógica (Eixo X)
int eixo_X = A1;  //Saída analógica (Eixo Y)
int botao = 2;    //Saída digital do botão (Eixo Z)

void setup() {
  //Serial.begin(9600); //Inicializa a comunicação serial
  pinMode(botao, INPUT_PULLUP);  //Define botao como entrada e em modo PULL UP, ou seja, lê HIGH quando o botão não estiver pressionado
}

void loop() {

  if ((analogRead(eixo_X)) == 0) {  //SE LEITURA FOR IGUAL A 0, FAZ //"PARA CIMA"

  } else {
    if ((analogRead(eixo_X)) == 1023) {  //SE LEITURA FOR IGUAL A 1023, FAZ//"PARA BAIXO"
    
    } else {
      if ((analogRead(eixo_Y)) == 0) {  //SE LEITURA FOR IGUAL A 0, FAZ//"DIREITA"
      
      } else {
        if ((analogRead(eixo_Y)) == 1023) {  //SE LEITURA FOR IGUAL A 1023, FAZ//"ESQUERDA"
        
        } else {
          if (digitalRead(botao) == LOW) {  //SE LEITURA FOR IGUAL A HIGH, FAZ//"BOTAO PRESSIONADO"
          
          }
        }
      }
    }
  }
}
