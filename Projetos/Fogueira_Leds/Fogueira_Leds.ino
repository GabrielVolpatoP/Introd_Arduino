int led1 = 11;
int led2 = 10;
//int led3 = 5;
//int led4 = 3;

int time = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  //pinMode(led3, OUTPUT);
  //pinMode(led4, OUTPUT);
}

void loop()
{
 
  analogWrite(led, random(195)+50);
  analogWrite(led3, random(195)+50);
  //analogWrite(led1, random(195)+50);
  //analogWrite(led4, random(195)+50);

  delay(time);


}
