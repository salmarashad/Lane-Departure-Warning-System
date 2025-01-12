#include "infrared.h"

void infra_init() {
    gpio_init(IR_SENSOR_PIN);       
    gpio_set_dir(IR_SENSOR_PIN, GPIO_IN);
    gpio_pull_up(IR_SENSOR_PIN);
}

int infra_read() {
    return gpio_get(IR_SENSOR_PIN);  // Returns 1 for HIGH (white), 0 for LOW (black)
}