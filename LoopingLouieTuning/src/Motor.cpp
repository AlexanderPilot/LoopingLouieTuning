/* Funktionen Motor */
extern bool debug;

/* Einbinden von Headerdateien */
#include "Motor.h"


/* Funktionen */
Motor::Motor()
{
  _stopMotor();
}

void Motor::Modus0()
{
  //20% Drehzahl, im Uhrzeigersinn
  _startMotor(50,true);
}

void Motor::Modus1()
{
  _setMotorSpeed(40);
  _setMotorDirection(true);
  _startMotor();
}

void Motor::Modus2()
{
  
}

void Motor::Modus3()
{
  
}

void Motor::Modus4()
{
  
}

void Motor::boostMotor()
{
  
}

bool Motor::getBoostMotorAvailable()
{
  
}

void Motor::_startMotor()
{
  _startMotor(_getMotorSpeed(), _getMotorDirection());
}

void Motor::_startMotor(byte motorSpeed, boolean motorClockwise)
{
  analogWrite(Pin_Motor_Wert, map(motorSpeed,0,100,130,255));
    if(motorClockwise == true)
    {
      digitalWrite(Pin_Motor_Enable_channel_1,true);
      digitalWrite(Pin_Motor_Enable_channel_2,false);
      if(debug == true)
      {
        Serial.println("Uhrzeigersinn");
      }
    }
    else
    {
      digitalWrite(Pin_Motor_Enable_channel_1,false);
      digitalWrite(Pin_Motor_Enable_channel_2,true);
      if(debug == true)
      {
        Serial.println("Gegen-Uhrzeigersinn");
      }
    }
}

void Motor::_stopMotor()
{
  _setMotorSpeed(0);
}
 
void Motor::_setMotorSpeed(byte motorSpeed)
{
  _motorSpeed = map(motorSpeed, 0, 100, 0, 255);
}

byte Motor::_getMotorSpeed()
{
  return map(_motorSpeed, 0, 255, 0, 100);
}

void Motor::_setMotorDirection(boolean motorClockwise)
{
  _motorClockwise = motorClockwise;
}

boolean Motor::_getMotorDirection()
{
  return _motorClockwise;
}




