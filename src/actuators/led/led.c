#include "led.h"

void led_init(){
    gpio_init(RIGHT_LED_PIN);
    gpio_set_dir(RIGHT_LED_PIN, GPIO_OUT);

    gpio_init(LEFT_LED_PIN);
    gpio_set_dir(LEFT_LED_PIN, GPIO_OUT);
}

void led_on(uint16_t led_pin) {
        gpio_put(led_pin, 1);
}

void led_off(uint16_t led_pin) {
        gpio_put(led_pin, 0);
}