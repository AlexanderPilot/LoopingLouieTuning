/* Header für Motor */

/* Vermeidung Doppeldefinitionen */
#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"
#include "Configurations.h"
#include <Wire.h>

/* Definitionen */


/* Klasse Motor */
class Motor {
  public:
    //Konstruktor
    Motor();

    //Funktionen
    void Modus0();
    void Modus1();
    void Modus2();
    void Modus3();
    void Modus4();
    
    void boostMotor();

    bool getBoostMotorAvailable();
    //Variablen
    
  private:
    //Funktionen
    void _startMotor();
    void _startMotor(byte motorSpeed, bool motorClockwise);
    void _stopMotor();
     
    void _setMotorSpeed(byte motorSpeed);
    byte _getMotorSpeed();
    
    void _setMotorDirection(bool motorClockwise);    
    bool _getMotorDirection();
    
    //Variablen
    byte _motorSpeed;
    bool _motorClockwise;
    byte _timerSpeed;
    byte _timerClockwise;
    byte _timerStop;
    byte _BoostSpeed;
    byte _BoostDuration;
    bool _BoostMotorAvailable;
};

#endif
