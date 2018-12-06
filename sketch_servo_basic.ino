#include <Servo.h>

#define Y_LEFT_PIN A1                  //X axis reading from joystick will go into analog pin A1
#define X_LEFT_PIN A0                  //X axis reading from joystick will go into analog pin A1

#define X_RIGHT_PIN  A3
#define Y_RIGHT_PIN  A4

// Controlled by LEFT JOYSTICK
Servo a;  
Servo b;


// CONTROLLED by RIGHT JOYSTICK
Servo c;
Servo d;   
 
void setup()
{
 Serial.begin(9600);
 
  a.attach(12); // lateral
  b.attach(9);  // extend in and out
  
  c.attach(7);  // extend up and down  
  d.attach(10); // claw 

}
 
void loop()
{
  
  delay(200);                    

  // The map function takes the following args
  // map(value, fromLow, fromHigh, toLow, toHigh)

  // LEFT JOYSTICK - LATERAL MOTION
  int leftYVal = analogRead(Y_LEFT_PIN) ; 
  leftYVal = map(leftYVal, 0, 1023, 20, 150);
 
  Serial.print("Y=");
  Serial.println(leftYVal);
  
  a.write(leftYVal);      // extend arm in and out.  

// LATERAL MOTION
  int leftXVal = analogRead(X_LEFT_PIN) ;  
  leftXVal = map(leftXVal, 0, 1023, 0,150);
  Serial.print("X=");
  Serial.println(leftXVal);

  b.write(leftXVal);      // rotate 


  int rightXVal = analogRead(X_RIGHT_PIN) ;
  // right joystick
  rightXVal = map(rightXVal,0 ,1023, 0, 150);
  c.write(rightXVal);

  //  extend up and down
  int rightYVal = analogRead(Y_RIGHT_PIN) ;
  rightYVal = map(rightYVal, 40, 1023, 0, 150);
  d.write(rightYVal);

}
