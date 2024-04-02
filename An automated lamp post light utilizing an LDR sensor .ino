 int ldr_pin = 7;
 int led_pin = 5;
void setup() {
  // put your setup code here, to run once:
    pinMode(7,INPUT);
    pinMode(5,OUTPUT);
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   if( digitalRead( ldr_pin ) == 1){
      digitalWrite( led_pin,HIGH);
   }
   else{
      digitalWrite( led_pin , LOW);
   }
   
   Serial.println( digitalRead( ldr_pin ));
   delay(100);
}
