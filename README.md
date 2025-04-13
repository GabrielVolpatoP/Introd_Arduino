<header>
<h2> 🛠 Sensores e Módulos Arduino - Guia Prático 
<img src="https://img.shields.io/badge/READ%20ME-555555" alt="ReadMe" align="right"  width="q35">
</h2>
</header>

Este repositório contém um guia prático com resumos e exemplos de uso dos principais sensores e módulos compatíveis com Arduino. Ideal para projetos de iniciação científica, competições e aprendizado em eletrônica embarcada.


## Checklist de Bibliotecas Necessárias

Estas bibliotecas são requeridas para executar os exemplos fornecidos neste repositório. Instale-as via Arduino IDE:

### 1. Biblioteca DHT

- Nome: ```DHT sensor library```
- Autor: Adafruit

### 2. Biblioteca MFRC522

- Nome: ```MFRC522```
- Autor: Github Community / Miguel Balboa

### 3. Biblioteca Adafruit HMC5883L (Bússola GY-271)

- Nome: ```Adafruit HMC5883 Unified```
- Autor: Adafruit

### 4. Biblioteca LiquidCrystal I2C

- Nome: ```LiquidCrystal I2C```
- Autor: Frank de Brabander ou similar


> [!IMPORTANT]\
> **Instalação:**
>  - Vá em: Sketch > Incluir Biblioteca > Gerenciar Bibliotecas...
>  - Busque pelo nome da Biblioteca
>  - Instale a versão mais recente


## Sumário

- [Sensor Ultrassônico HC-SR04](#sensor-ultrassônico-hc-sr04)
- [Sensor de Temperatura LM35](#sensor-de-temperatura-lm35)
- [Sensor de Temperatura e Umidade DHT11](#sensor-de-temperatura-e-umidade-dht11)
- [Módulo RFID RC522](#módulo-rfid-rc522)
- [Sensor de Chama IR](#sensor-de-chama-ir)
- [Sensor Magnético (Reed Switch)](#sensor-magnético-reed-switch)
- [Módulo Joystick XY](#módulo-joystick-xy)
- [Sensor de Gás MQ-2](#sensor-de-gás-mq-2)
- [Sensor de Gás MQ-135](#sensor-de-gás-mq-135)
- [Sensor de Chuva](#sensor-de-chuva)
- [Sensor de Luz (LDR)](#sensor-de-luz-ldr)
- [Módulo Bússola GY-271](#módulo-bússola-gy-271)
- [Display LCD 16x2 com I2C](#display-lcd-16x2-com-i2c)

---

## Sensor Ultrassônico HC-SR04
Mede distância usando pulsos ultrassônicos. Faixa: 2 a 400 cm.

```cpp
#define trig 9
#define echo 10

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duracao = pulseIn(echo, HIGH);
  float distancia = duracao * 0.034 / 2;
  Serial.println(distancia);
  delay(500);
}
```

## Sensor de Temperatura LM35
Saída analógica proporcional à temperatura em °C.

```cpp
int pinoLM35 = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(pinoLM35);
  float temperatura = leitura * 5.0 * 100.0 / 1023.0;
  Serial.println(temperatura);
  delay(1000);
}
```

## Sensor de Temperatura e Umidade DHT11
Interface digital. Requer biblioteca: DHT.h

```cpp
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();
  Serial.print("Temp: "); Serial.print(temperatura);
  Serial.print(" C | Umid: "); Serial.println(umidade);
  delay(2000);
}
```

## Módulo RFID RC522
Comunicação SPI. Requer biblioteca: MFRC522.h

```cpp
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial()) return;

  Serial.print("UID: ");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
}
```

## Sensor de Chama IR
Detecta presença de fogo (IR). Saída digital.

```cpp
int sensorChama = 7;

void setup() {
  pinMode(sensorChama, INPUT);
  Serial.begin(9600);
}

void loop() {
  int valor = digitalRead(sensorChama);
  if (valor == LOW) {
    Serial.println("🔥 Chama detectada!");
  } else {
    Serial.println("Nada detectado.");
  }
  delay(500);
}
```

## Sensor Magnético (Reed Switch)
Detecta campo magnético (ímã).

```cpp
int reed = 3;

void setup() {
  pinMode(reed, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(reed) == LOW) {
    Serial.println("⚠️ Ímã detectado");
  }
  delay(200);
}
```

## Módulo Joystick XY
Potenciômetros nos eixos X e Y + botão.

```cpp
int x = A0;
int y = A1;
int botao = 2;

void setup() {
  Serial.begin(9600);
  pinMode(botao, INPUT_PULLUP);
}

void loop() {
  Serial.print("X: "); Serial.print(analogRead(x));
  Serial.print(" | Y: "); Serial.print(analogRead(y));
  Serial.print(" | Botão: "); Serial.println(digitalRead(botao));
  delay(500);
}
```

## Sensor de Gás MQ-2
Detecta GLP, gás natural, álcool. Saída analógica/digital.

```cpp
int mq2 = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(mq2);
  Serial.print("Gás: "); Serial.println(leitura);
  delay(1000);
}
```

## Sensor de Gás MQ-135
Detecta gases tóxicos e qualidade do ar.

```cpp
int mq135 = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(mq135);
  Serial.print("Qualidade do ar: "); Serial.println(leitura);
  delay(1000);
}
```

## Sensor de Chuva
Detecta gotas ou água no sensor. Saída digital/analógica.

```cpp
int chuva = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int valor = analogRead(chuva);
  Serial.print("Chuva: "); Serial.println(valor);
  delay(1000);
}
```

## Sensor de Luz (LDR)
Sensor de luminosidade.

```cpp
int ldr = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int valor = analogRead(ldr);
  Serial.print("Luz: "); Serial.println(valor);
  delay(500);
}
```

## Módulo Bússola GY-271
Sensor magnético 3 eixos HMC5883L. Usa I2C. Requer biblioteca Adafruit HMC5883.

```cpp
#include <Wire.h>
#include <Adafruit_HMC5883_U.h>

Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

void setup() {
  Serial.begin(9600);
  mag.begin();
}

void loop() {
  sensors_event_t event;
  mag.getEvent(&event);
  Serial.print("X: "); Serial.print(event.magnetic.x);
  Serial.print(" Y: "); Serial.print(event.magnetic.y);
  Serial.print(" Z: "); Serial.println(event.magnetic.z);
  delay(1000);
}
```

## Display LCD 16x2 com I2C
Exibição simples via I2C (endereço padrão 0x27).

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();
  lcd.backlight();
  lcd.print("Hello, Arduino!");
}

void loop() {
  // Atualizações dinâmicas aqui
}
```

## Licença
Este projeto está licenciado sob a [MIT License](LICENSE).

## Autores
- Gabriel Volpato

## Contato
Para suporte ou dúvidas, entre em contato pelo email: volpatocursin@outlook.com 
<img src="https://github.com/GabrielVolpatoP/GabrielVolpatoP/blob/main/imagens/Duck__icon.svg?raw=true" alt="Icon Usuario" align="right"  width="60">
