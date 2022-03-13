int sensorpin=A0;
int ledpin= LED_BUILTIN;
int sensorvalue=0;

void setup() {
  // put your setup code here, to run once:
pinMode(ledpin, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
sensorvalue=analogRead  (sensorpin);
if (sensorvalue>900){
  digitalWrite(ledpin, HIGH);
  
}
else{
  digitalWrite(ledpin, LOW);
  
}
Serial.println(sensorvalue, DEC);
}
