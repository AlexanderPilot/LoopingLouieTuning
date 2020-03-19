/* Einbinden der Headerdateien */
#include "Configurations.h"
#include "Settings.h"
#include "Buttons.h"
#include "InterruptServiceRoutines.h"
#include "Motor.h"
#include "Players.h"

/* Anlegen der Objekte */
Players player1;
Players player2;
Players player3;
Players player4;
Players player5;
Players player6;
Players player7;
Players player8;

Motor motor;

InterruptServiceRoutines ISR;

//Globale Variablen
volatile bool debug = true;
volatile int GameMode = 0; //Default-Start mit normaler Geschwindigkeit
volatile bool GameModeChange = false;

void setup(void)
{
  Serial.begin(SERIAL_SPEED);
  Serial.println("Looping Louie wird gestartet");
  Serial.print("Firmware Version ");
  Serial.println(FIRMWARE_VERSION);
  Serial.println("_________________________________________________________________");
  if(debug == true)
  {
    Serial.println("Debug Modus aktiv");
  }
  Serial.println("_________________________________________________________________");
  Serial.println("");

  //Pinmode setzen
  pinMode(Pin_Motor_Wert, OUTPUT);
  pinMode(Pin_Motor_Enable_channel_1, OUTPUT);
  pinMode(Pin_Motor_Enable_channel_2, OUTPUT);
  pinMode(Pin_Interrupt_Boost,INPUT_PULLUP);
  pinMode(Pin_Interrupt_GameMode,INPUT_PULLUP);
  
/*
  //Einbinden der ISR-Funktionen (Iterrupt 0)
  EIFR |= (1 << INTF0);
  EIFR |= (1 << INTF1);
  attachInterrupt(digitalPinToInterrupt(Pin_Interrupt_Boost), Wrapper_ISR_BoostButton, FALLING);
  if(debug == true)
  {
    Serial.println("ISR für Boost Knöpfe eingebunden");
  }
  attachInterrupt(digitalPinToInterrupt(Pin_Interrupt_GameMode), Wrapper_ISR_ModeChange, FALLING);
  if(debug == true)
  {
    Serial.println("ISR für die Änderung des Spielmodus eingebunden");
  }
  */
}

void loop()
{
  Serial.println("Modus0");
  motor.Modus0();
  
  /*
  //Auswahl des Spielmodus
  switch(GameMode)
  {
    case 0: //normaler Spielmodus
      if(debug == true && GameModeChange == true)
      {
        Serial.println("Spielmodus 0");
        GameModeChange = false;
      }
      motor.Modus0();
      break;
    case 1: //Geschwindigkeit x2
      if(debug == true && GameModeChange == true)
      {
        Serial.println("Spielmodus 1");
        GameModeChange = false;
      }
      motor.Modus1();
      break;
    case 2: //zufällige Geschwindigkeitsänderungen
      if(debug == true && GameModeChange == true)
      {
        Serial.println("Spielmodus 2");
        GameModeChange = false;
      }
      motor.Modus2();
      break;
    case 3: //zufällige Geschwindigkeitsänderungen + stoppen
      if(debug == true && GameModeChange == true)
      {
        Serial.println("Spielmodus 3");
        GameModeChange = false;
      }
      motor.Modus3();
      break;
    case 4: //zufälliges Vorwärts- und Rückwärtsfliegen + zufälligen Geschwindigkeitsänderungen + stoppen
      if(debug == true && GameModeChange == true)
      {
        Serial.println("Spielmodus 4");
        GameModeChange = false;
      }
      motor.Modus4();
      break;
    default:      
      if(debug == true)
      {
        Serial.println("ungültiger Spielmodus");
      }
      break;
  }
  GameModeChange = 0;*/
}


//Wrapperfunktion für ISR BoostButton
void Wrapper_ISR_BoostButton()
{
  ISR.ISR_BoostButton();
  if(debug == true)
  {
    Serial.println("Wrapper für Boost Knöpfe aktiviert");
  }
}

//Wrapperfunktion für ISR ModeChange
void Wrapper_ISR_ModeChange()
{
  ISR.ISR_ModeChange();
  if(debug == true)
  {
    Serial.println("Wrapper für die Änderung des Spielmodus aktiviert");
  }
}


