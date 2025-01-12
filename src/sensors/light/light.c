#include "light.h"
#include <hardware/adc.h>

void light_init(){
    adc_init();
    adc_gpio_init(LIGHT_READ_IN);
    adc_select_input(0);
}

uint16_t light_read(){
    uint16_t raw_value = adc_read();
    float mapped_value = (raw_value / 4095.0)*100;    //0-100
    return mapped_value;
}
