#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#ifndef PICO_STDIO_H
#define PICO_STDIO_H
#include "pico/stdlib.h"
#endif

#define ULTRA_TRIGGER_PIN  16  
#define ULTRA_ECHO_PIN     17 

#define STOP_DISTANCE 9 // in cm

void ultra_init();
float get_distance();
void ultra_trigger(void);    
uint32_t pulse_in(uint gpio, bool level); 

#endif