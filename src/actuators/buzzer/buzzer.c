#include "buzzer.h"
#include "pico/stdlib.h"

void buzzer_init(void) {
    gpio_init(BUZZER_PIN);   
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
    gpio_put(BUZZER_PIN, 0);      
}

void buzzer_on(void) {
    gpio_put(BUZZER_PIN, 1); 
}

void buzzer_off(void) {
    gpio_put(BUZZER_PIN, 0);  
}

void buzzer_beep(uint32_t duration_ms) {
    buzzer_on();             
    sleep_ms(duration_ms);   
    buzzer_off();            
}