
#include <AFMotor.h>
// #include <IRremote.hpp>
#include <string.h>

const int IR_RECEIVE_PIN = 53;
const char TERMINAL = '|';


AF_DCMotor motor1(1);//define motor1
AF_DCMotor motor2(2);//define motor2
AF_DCMotor motor3(3);//define motor3
AF_DCMotor motor4(4);//define motor4


void forward()
{
  motor1.setSpeed(200);//setup the speed of motor1
  motor2.setSpeed(200);//setup the speed of motor2
  motor3.setSpeed(200);//setup the speed of motor3
  motor4.setSpeed(200);//setup the speed of motor4
  // //car move forward
  motor1.run(BACKWARD);//motor1 run BACKWARD
  motor2.run(BACKWARD); //motor2 run FORWARD
  motor3.run(BACKWARD);//motor3 run BACKWARD
  motor4.run(BACKWARD); //motor4 run FORWARD
}
void backward()
{
  motor1.setSpeed(200);//setup the speed of motor1
  motor2.setSpeed(200);//setup the speed of motor2
  motor3.setSpeed(200);//setup the speed of motor3
  motor4.setSpeed(200);//setup the speed of motor4
  // //car move forward
  motor1.run(FORWARD);//motor1 run BACKWARD
  motor2.run(FORWARD); //motor2 run FORWARD
  motor3.run(FORWARD);//motor3 run BACKWARD
  motor4.run(FORWARD); //motor4 run FORWARD
}
void turn_left()
{
  motor1.setSpeed(200);//setup the speed of motor1
  motor2.setSpeed(200);//setup the speed of motor2
  motor3.setSpeed(200);//setup the speed of motor3
  motor4.setSpeed(200);//setup the speed of motor4

  motor1.run(FORWARD);//motor1 run BACKWARD
  motor2.run(BACKWARD); //motor2 run FORWARD
  motor3.run(BACKWARD);//motor3 run BACKWARD
  motor4.run(FORWARD); //motor4 run FORWARD
}
void turn_right()
{
  motor1.setSpeed(200);//setup the speed of motor1
  motor2.setSpeed(200);//setup the speed of motor2
  motor3.setSpeed(200);//setup the speed of motor3
  motor4.setSpeed(200);//setup the speed of motor4

  motor1.run(BACKWARD);//motor1 run BACKWARD
  motor2.run(FORWARD); //motor2 run FORWARD
  motor3.run(FORWARD);//motor3 run BACKWARD
  motor4.run(BACKWARD); //motor4 run FORWARD
}
void stop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
// void remote_control()
// {
//   if (IrReceiver.decode()) {
//       // Serial.println(IrReceiver.decodedIRData.decodedRawData); // Print "old" raw data
//       // IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
//       // IrReceiver.printIRSendUsage(&Serial);   // Print the statement required to send this data
//       IrReceiver.resume(); // Enable receiving of the next value
//       if(IrReceiver.decodedIRData.decodedRawData == 3877175040) // press forward
//       {
//         forward();
//       }
//       else if(IrReceiver.decodedIRData.decodedRawData == 2907897600) // press backward
//       {
//         backward();
//       }
//       else if(IrReceiver.decodedIRData.decodedRawData == 4144561920) // press left
//       {
//         turn_left();
//       }
//       else if(IrReceiver.decodedIRData.decodedRawData == 2774204160) // press right
//       {
//         turn_right();
//       }
//       else if(IrReceiver.decodedIRData.decodedRawData == 3810328320) // press ok
//       {
//         stop();
//       }
//   }
    
// }
void setup() 
{
  Serial.begin(9600);
  // IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

}
void loop() 
{
  if (Serial.available())
  {
    String data = Serial.readStringUntil(TERMINAL);
    if(data == "FORWARD")
    {
      forward();
    }
    else if(data == "BACKWARD")
    {
      backward();
    }
    else if(data == "LEFT")
    {
      turn_left();
    }
    else if(data == "RIGHT")
    {
      turn_right();
    }
    else if(data == "STOP")
    {
      stop();
    }
    
    Serial.print(data);
  }
}
