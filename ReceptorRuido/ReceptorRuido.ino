void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  analogRead(2);
  Serial.println(analogRead(2));
  delay(1000);

}
