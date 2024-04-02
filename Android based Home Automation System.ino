    
  void setup() 
{
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(2,OUTPUT);          // setes digital pin 2,3 as output and input pin of IR Sensor
  pinMode(3,INPUT);
  pinMode(5,OUTPUT);        //Sets digital pin 5,6 as output pin of Voice control
  pinMode(6,OUTPUT);
  pinMode(7,INPUT);         //sets digistal pin 7,8 as input and output pin for LDR sensor
  pinMode(8,OUTPUT);
  pinMode(9, OUTPUT);       //define Rain Alarm
 

}
int ldr_pin = 7;
int led_pin = 8;
int IR = 0;
char c;
String voice;

//voice control
void loop()
{
  if(Serial.available() > 0)  
  { voice="";
  delay(2);
    voice=Serial.readString();
    delay(2);
    Serial.println(voice);
  }
  if(voice=="turn off light")
    { digitalWrite(5,HIGH);
    }
  else if (voice=="turn on light")
    {digitalWrite(5,LOW);
    }

  else if(voice=="turn off fan")
    { digitalWrite(6,HIGH);
    }
  else if (voice=="turn on fan")
    {digitalWrite(6,LOW);
    }
  
}

//Ir R sensor
void loop() {
 IR = digitalRead(3);
if(IR==1)
digitalWrite(2,HIGH);
else if(IR==0)
digitalWrite(2,LOW);
}

   
//LDR Sensor
void loop() {
  
   if( digitalRead( ldr_pin ) == 1){
      digitalWrite( led_pin,HIGH);
   }
   else{
      digitalWrite( led_pin , LOW);
   }
   
   Serial.println( digitalRead( ldr_pin ));
   delay(100);
}

 // water Sensor
void loop() {
  int value = analogRead(A3);//read value
  Serial.print("Value : ");
  Serial.println(value);
  if (value < 300) {//check condition
    digitalWrite(9, HIGH);
    Serial.print("Heavy rain  Buzzer on ");
  } else {
    digitalWrite(4, LOW);
  }
}
int trigger_pin = 2;

int echo_pin = 3;

int buzzer_pin = 10; 

int time;

int distance; 




void setup ( ) {

        Serial.begin (9600); 

        pinMode (trigger_pin, OUTPUT); 

        pinMode (echo_pin, INPUT);

        pinMode (buzzer_pin, OUTPUT);




}




void loop ( ) {

    digitalWrite (trigger_pin, HIGH);

    delayMicroseconds (10);

    digitalWrite (trigger_pin, LOW);

    time = pulseIn (echo_pin, HIGH);

    distance = (time * 0.020) / 2;

    

  if (distance <= 10) 

        {

        Serial.println (" Door Open ");

        Serial.print (" Distance= ");              

        Serial.println (distance);        

        digitalWrite (buzzer_pin, HIGH);

        delay (500);

        }

  else {

        Serial.println (" Door closed ");

        Serial.print (" Distance= ");              

        Serial.println (distance);        

        digitalWrite (buzzer_pin, LOW);

        delay (500);        

  } 

  }
  float sensor = A0;
float gas_value;
int R_LED = 2;
int G_LED = 3;
int Buzzer = 4;
void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  pinMode(R_LED , OUTPUT);
  pinMode(G_LED , OUTPUT);
  pinMode(Buzzer , OUTPUT);
}
void loop() {
  gas_value = analogRead(sensor);
  delay(1000);
  Serial.println(gas_value);
  if (gas_value >= 400) {
    Serial.println("Gas Leaking");
    digitalWrite(R_LED , HIGH);
    digitalWrite(G_LED , LOW);
    digitalWrite(Buzzer , HIGH);
  }
  else {
    digitalWrite(R_LED , LOW);
    digitalWrite(Buzzer , LOW);
    digitalWrite(G_LED , HIGH);
    Serial.println("NORMAL");
  }
}
