int Liquid_level=0;
int first=0;
int numTones = 5;
int tones[] = {261, 330, 392, 330, 261};
void setup() {
Serial.begin(9600);
pinMode(5,INPUT);
pinMode(6,OUTPUT);
}

void loop() {
  if(first==0)
{  
  first++;
  for (int i = 0; i <3; i++) {
      tone(6, tones[i]);
      delay(500);
    }
    noTone(6);
}
Liquid_level=digitalRead(5);
Serial.print("Liquid_level= ");
Serial.println(Liquid_level,DEC);
if(Liquid_level==1)
{  for (int i = 0; i < numTones; i++) {
      tone(6, tones[i]);
      delay(70);
    }
    noTone(6);
 }
delay(50);
}
