int URPWM =3;
int URTRIG = 5;
unsigned int Distance=0;
uint8_t EnPwmCmd[4]={0x44,0x02,0xbb,0x01};
void setup()
{
  Serial.begin(9600);
  PWM_Mode_Setup();
}
void loop()
{
  PWM_Mode();
  delay(500);
}
void PWM_Mode_Setup()
{
  pinMode(URTRIG,OUTPUT);
  digitalWrite(URTRIG,HIGH);
  pinMode(URPWM,INPUT);
  for(int i=0;i<4;i++)
  {
    Serial.write(EnPwmCmd[i]);
  }
}
void PWM_Mode()
{
  digitalWrite(URTRIG,LOW);
  digitalWrite(URTRIG,HIGH);
  unsigned long DistanceMeasured=pulseIn(URPWM,LOW);
  
  if(DistanceMeasured>=10200);
   {
      Distance=DistanceMeasured/50;
      Serial.print("Distance=");
      Serial.print(Distance);
      Serial.println("cm");
  
  
  
  }
}
