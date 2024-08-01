void setup() {
  //GPIO0のセットアップ
  pinMode(0, OUTPUT);
  TCB0.CTRLA = TCB_ENABLE_bm | TCB_CLKSEL_CLKDIV1_gc; //start the timer, set the prescaler to 1
  TCB0.CTRLB = TCB_CCMPEN_bm | TCB_CNTMODE_PWM8_gc; //enable WO0, select the 8 bits PWM mode
  TCB0.CCMPL = 255; //set the PWM resolution to 8 bits
  TCB0.CCMPH = 0; //set the duty cycle
  //GPIO3のセットアップ
  pinMode(3, OUTPUT);
}

void loop()
{
  for (int i = 0; i < 256; i++)
  {
    //GPIO0のPWM
    TCB0.CCMPH = i;
    //GPIO3のPWM
    analogWrite(3,i);
    delay(10);
  }
}
