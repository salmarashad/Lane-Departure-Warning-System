#ifndef BUZZER_H
#define BUZZER_H

#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

#ifndef PICO_STDIO_H
#define PICO_STDIO_H
#include "pico/stdlib.h"
#endif

#define BUZZER_PIN  18  

void buzzer_init(void);       
void buzzer_on(void);              
void buzzer_off(void);             
void buzzer_beep(uint32_t duration_ms); 

#endif