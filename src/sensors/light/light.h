#ifndef LIGHT_H
#define LIGHT_H

#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

#ifndef PICO_STDIO_H
#define PICO_STDIO_H
#include "pico/stdlib.h"
#endif

#define LIGHT_READ_IN  26  

void light_init();
uint16_t light_read();

#endif 