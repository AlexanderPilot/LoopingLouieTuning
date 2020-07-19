/* Funktionen ISR */
extern int GameMode;
extern bool GameModeChange;
extern bool debug;

/* Einbinden von Headerdateien */
#include "InterruptServiceRoutines.h"


/* Funktionen */
void InterruptServiceRoutines::ISR_BoostButton()
{  
  EIFR |= (1 << INTF0);
  if(millis() > _debounceTimeBoostButton)
  {
    if(debug == true)
    {
      Serial.println("ISR BoostButton aktiviert");
    }
    //prüfen, welcher Pin des PCF8574 den Interrupt ausgelöst hat
  
    //prüfen, ob der Boost allgemein verfügbar ist
    
    //prüfen, ob für den betreffenden Pin verfügbar ist
  
    //Boost des Motors aktivieren
  
    //LED des betreffenden Pins deaktivieren
  
    //starten des Timers des Pins, der den Boost aktiviert hat
  }
  _debounceTimeBoostButton = millis() + debounceTime;
}

void InterruptServiceRoutines::ISR_ModeChange()
{
  EIFR |= (1 << INTF1);
  if(millis() > _debounceTimeModeChange)
  {
    if(debug == true)
    {
      Serial.println("ISR ModeChange aktiviert");
    }
    //Weiterschalten des Modus
    if(GameMode <= 3)
    {
      GameMode++;
      GameModeChange = true;
      if(debug == true)
      {
        Serial.println("Zähler Spielmodus erhöht");
      }
    }
    else if (GameMode == 4)
    {
      GameMode = 0;
      GameModeChange = true;
      if(debug == true)
      {
        Serial.println("Zähler Spielmodus zurück gesetzt");
      }
    }
  }
  _debounceTimeModeChange = millis() + debounceTime;
}

