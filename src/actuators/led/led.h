#ifndef LED_H
#define LED_H

#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

#ifndef PICO_STDIO_H
#define PICO_STDIO_H
#include "pico/stdlib.h"
#endif

#define RIGHT_LED_PIN   13
#define LEFT_LED_PIN    12

void led_init();
void led_on(uint16_t led_pin);
void led_off(uint16_t led_pin);

#endif 