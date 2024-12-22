void setup() {
  pinMode(1, OUTPUT);
  pinMode(4, INPUT);
}

void loop() {
  //ADC は1,2,3,4が使用可能
  int adc = analogRead(4);
  analogWrite(1, adc);
}
