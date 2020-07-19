/* Header für Players */

/* Vermeidung Doppeldefinitionen */
#ifndef PLAYERS_H
#define PLAYERS_H

#include "Arduino.h"
#include "Configurations.h"
#include <Wire.h>

/* Definitionen */


/* Klasse Players */
class Players {
  public:
    //Konstruktor
    Players();
    
    //Funktionen
    bool getBoostPlayerAvailable();

    //Variablen
    
  private:
    //Funktionen

    //Variablen
    bool _BoostPlayerAvailable;
};

#endif
