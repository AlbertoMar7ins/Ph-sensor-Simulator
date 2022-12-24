
int sensorPh = A0; //potenciômetro conectado A0
int ledAc = 8; //led vermelho (ph ácido) conectado pin 8
int ledBs = 12; //led azul (ph básico) conectado pin 12
int ledn = 9;//Led que indica ph neutro
int potValue;
int pH;

void setup()
{
  pinMode(sensorPh, INPUT); //Entrada PH sensor
  pinMode(ledAc, OUTPUT); //Saída LED
  pinMode(ledBs, OUTPUT);
  pinMode(ledn, OUTPUT);
  Serial.begin (9600);
}

void loop()
{
  Serial.println (pH); //mostra o valor do ph
  potValue = analogRead (sensorPh); //potValue recebe valor do Sensor
  digitalWrite(ledAc, LOW);
  digitalWrite(ledBs, LOW);
  digitalWrite(ledn, LOW);
  
  //conversão ph pra obter valor 0-14
  pH = (14 * potValue / 1023);
  
  //ph ácido acende led vermelho
  if (pH < 5.5 || pH > 9.5) 
  {
    digitalWrite(ledAc, HIGH);
   
  }
  /**ph Neutro
  if (pH > 5.5 && pH <6){
    digitalWrite(ledn, HIGH);
    delay(500);
  }**/
  
  //ph básico acende led azul
  if (pH >= 6 && pH <= 9.5)
  {
    digitalWrite(ledBs, HIGH);
  }
 if (pH > 9.5)
  {
   digitalWrite(ledBs, LOW);
  digitalWrite(ledAc, HIGH);
  }

}



