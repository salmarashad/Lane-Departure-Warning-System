#ifndef INFRARED_H
#define INFRARED_H

#ifndef PICO_STDIO_H
#define PICO_STDIO_H
#include "pico/stdlib.h"
#endif

#define IR_SENSOR_PIN  20 // digital

void infra_init();       
int infra_read();    

#endif