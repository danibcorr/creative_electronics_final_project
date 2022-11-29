#include <Servo.h>

Servo myservo; 
Servo myservo2;

int pos = 0;    // variable to store the servo position

void setup() 
{
  myservo.attach(22); 
  myservo2.attach(24);  
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) 
  {
    myservo.write(pos);        
    myservo2.write(pos);       
    delay(5);              
  }
  for (pos = 180; pos >= 0; pos -= 1) 
  { 
    myservo.write(pos);       
    myservo2.write(pos);
    delay(15);                   
  }
}
