/* Header für Konfigurationsparameter */

/* Vermeidung Doppeldefinitionen */
#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#define FIRMWARE_VERSION "1.0"

/* Geschwindigkeit des seriellen Monitors */
#define SERIAL_SPEED 9600     

/* LED Einstellungen */
#define Pixel_Num 114
#define LED_Pin 7

/* Motor Einstellungen */
#define Pin_Motor_Wert  6 //PWM Pin
#define Pin_Motor_Enable_channel_1  7
#define Pin_Motor_Enable_channel_2  8

/* Interrupt Einstellungen */
#define Pin_Interrupt_Boost 2
#define Pin_Interrupt_GameMode 3

/* I2C Einstelllungen */
#define addressPCF8574 0x20

/* Debouncing */
#define debounceTime 50


#include "Arduino.h"


#endif
