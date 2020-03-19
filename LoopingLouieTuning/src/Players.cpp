/* Funktionen Players */
extern bool debug;

/* Einbinden von Headerdateien */
#include "Players.h"


/* Funktionen */
Players::Players()
{
  if(debug == true)
  {
    Serial.println("Player angelegt");
  }
}

bool Players::getBoostPlayerAvailable()
{
  return _BoostPlayerAvailable;
}


