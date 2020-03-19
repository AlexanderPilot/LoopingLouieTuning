/* Header für InterruptServiceRoutines */

/* Vermeidung Doppeldefinitionen */
#ifndef ISR_H
#define ISR_H

#include "Arduino.h"
#include "Configurations.h"


/* Definitionen */


/* Klasse InterruptServiceRoutines */
class InterruptServiceRoutines {
  public:
    //Konstruktor

    //Funktionen
    void ISR_BoostButton();
    void ISR_ModeChange();    

    //Variablen
  private:
    //Funktionen

    //Variablen
    int _debounceTimeBoostButton = 50;
    int _debounceTimeModeChange = 50;
};

#endif
