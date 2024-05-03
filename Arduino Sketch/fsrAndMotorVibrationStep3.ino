/*
Code to Read pressure from FSR pressure sensor 
attached to Analog pin 0
then print FRS value every 3 second on Serial Monitor
*/
int fsr_Analog_Pin = 0;
int fsr_Pressure_Value;
int fsr_Step_Count = 0;

int motor_DigitalPin_PWM = 3;

// the setup function runs once when you press reset or power the board
void setup() {
Serial.begin(9600);
pinMode(LED_BUILTIN, OUTPUT);

pinMode(motor_DigitalPin_PWM,OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
 fsr_Pressure_Value = analogRead(fsr_Analog_Pin);

 Serial.print("FSR Pressure Value = ");
 Serial.println(fsr_Pressure_Value);

 if(fsr_Pressure_Value > 200)
    {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
      digitalWrite(LED_BUILTIN, LOW);
      fsr_Step_Count ++;
      Serial.print("fsr_Step_Count = ");
      Serial.println(fsr_Step_Count);

      float every5Steps = fsr_Step_Count%5;

      if(fsr_Step_Count != 0 && every5Steps == 0)
      {
        Serial.println("Vibration Activated...");
        for (int i=0; i < 256; i++)
          {
            analogWrite(motor_DigitalPin_PWM,i);
            delay(10);
          }
          delay(2000);

        for (int i=255; i > 0; i--)
          {
            analogWrite(motor_DigitalPin_PWM,i);
            delay(10);
          }
          delay(2000);
       Serial.println("Vibration Stop! ");   
      }
    }
delay(100);
}
