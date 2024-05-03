#include <Servo.h>  // servo library
Servo servo;    //create a servo object from above library
int servoPin = 9;  //the Digital pin 11 provides PWM signal to the servo motor
int LDRpin = A5;   //LDR connected to Analog Pin A0
int maxLDR =0;  //this is the maximum reading from LDR
int reading, maxAngle;

void setup() 
{
  // put your setup code here, to run once:
servo.attach(servoPin);   //link servo motor to the servo library
Serial.begin(9600);    // speed transission for serial output
}

void loop() 
{     //scanning angle in range 0 to 180
  // put your main code here, to run repeatedly:
    for (int angle=0; angle<180; angle = angle +10)
    {
      servo.write(angle);   //rotate servo
      reading = analogRead(LDRpin); //reading LDR values
        if(reading>maxLDR) //compare reading to Maximum value
        {
          maxLDR = reading;   // update the max value
          maxAngle = angle;   //update angle of max light reading
        }
        delay(50); //wait 50 ms between reading
    }
    Serial.print("Light source at" );  //print value to serial monitor
    Serial.print(maxAngle);    //print angle
    Serial.println( "degrees");  //print word degrees
    delay(1000);  //rotate servo to point @ light source
    maxLDR=0;   //reset max light reading
    servo.write(0);   //rotate 0 degree
    delay(500); //wait 500ms before repating void loop code

}
