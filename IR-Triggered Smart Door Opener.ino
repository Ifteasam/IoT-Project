//char Incoming_value = 0;
int IR = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(4,OUTPUT);
pinMode(7,INPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
 IR = digitalRead(7);
  /*if (Serial.available() > 0)
  //  {
      Incoming_value = Serial.read();
      Serial.print(Incoming_value);
      Serial.print("\n");
      if (Incoming_value == '1')
        digitalWrite(13,HIGH);
      else if(Incoming_value == '0')
        digitalWrite(13,LOW);
  //  } */

if(IR==1)
digitalWrite(4,HIGH);
else if(IR==0)
digitalWrite(4,LOW);



  
}
