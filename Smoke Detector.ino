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
