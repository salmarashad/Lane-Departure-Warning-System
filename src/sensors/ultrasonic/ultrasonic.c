#include "ultrasonic.h"

void ultra_init(void) {
    gpio_init(ULTRA_TRIGGER_PIN);
    gpio_set_dir(ULTRA_TRIGGER_PIN, GPIO_OUT);
    
    gpio_init(ULTRA_ECHO_PIN);
    gpio_set_dir(ULTRA_ECHO_PIN, GPIO_IN);
    
    gpio_put(ULTRA_TRIGGER_PIN, 0);
    sleep_ms(500); 
}

void ultra_trigger(void) {
    gpio_put(ULTRA_TRIGGER_PIN, 1);
    sleep_us(10);
    gpio_put(ULTRA_TRIGGER_PIN, 0);
}

uint32_t pulse_in(uint gpio, bool level) {
    uint32_t duration = 0;
    while (gpio_get(gpio) != level) {
    }
    while (gpio_get(gpio) == level) {
        duration++;
        sleep_us(1); 
    }
    return duration;
}

float get_distance(void) {
    uint32_t duration;
    float distance;

    duration = pulse_in(ULTRA_ECHO_PIN, true);

    distance = (duration * 0.0343) / 2;

    return distance;
}
