#include "motor.h"
#include "hardware/pwm.h"

void motor_init(void) {
    gpio_init(MOTOR_IN1_H1_PIN);
    gpio_set_dir(MOTOR_IN1_H1_PIN, GPIO_OUT);

    gpio_init(MOTOR_IN2_H1_PIN);
    gpio_set_dir(MOTOR_IN2_H1_PIN, GPIO_OUT);

    gpio_init(MOTOR_IN1_H2_PIN);
    gpio_set_dir(MOTOR_IN1_H2_PIN, GPIO_OUT);

    gpio_init(MOTOR_IN2_H2_PIN);
    gpio_set_dir(MOTOR_IN2_H2_PIN, GPIO_OUT);

    gpio_set_function(MOTOR_EN_H1_PIN, GPIO_FUNC_PWM);
    gpio_set_function(MOTOR_EN_H2_PIN, GPIO_FUNC_PWM);


    uint slice_num1 = pwm_gpio_to_slice_num(MOTOR_EN_H1_PIN);
    pwm_set_wrap(slice_num1, 255); // PWM range from 0 to 255 (8-bit)
    pwm_set_clkdiv(slice_num1, 488.28125f); // Set PWM frequency
    pwm_set_enabled(slice_num1, true);  // Enable PWM for speed control

    uint slice_num2 = pwm_gpio_to_slice_num(MOTOR_EN_H2_PIN);
    pwm_set_wrap(slice_num2, 255); // PWM range from 0 to 255 (8-bit)
    pwm_set_clkdiv(slice_num2, 488.28125f); // Set PWM frequency
    pwm_set_enabled(slice_num2, true);  // Enable PWM for speed control

}

void motor_forward(uint16_t pin1,uint16_t pin2,uint16_t enable,uint8_t speed) {
    gpio_put(pin1, 1);     
    gpio_put(pin2, 0);     
    motor_set_speed(enable,speed);         
}

void motor_backward(uint16_t pin1,uint16_t pin2,uint16_t enable,uint8_t speed) {
    gpio_put(pin1, 0);     
    gpio_put(pin2, 1);     
    motor_set_speed(enable,speed);         
}

void motor_stop(uint16_t pin1,uint16_t pin2,uint16_t enable) {
    gpio_put(pin1, 0);     
    gpio_put(pin2, 0);     
    motor_set_speed(enable,0);             
}

void motor_set_speed(uint16_t enable,uint8_t speed) {
    uint slice_num = pwm_gpio_to_slice_num(enable);
    pwm_set_gpio_level(enable, speed); 
}

void motor_turn_left(uint8_t speed) {
    motor_backward(MOTOR_IN1_H1_PIN, MOTOR_IN2_H1_PIN, MOTOR_EN_H1_PIN, speed); 
    motor_forward(MOTOR_IN1_H2_PIN, MOTOR_IN2_H2_PIN, MOTOR_EN_H2_PIN, speed);  
    //sleep_ms(320);   
}

void motor_turn_right(uint8_t speed) {
    motor_backward(MOTOR_IN1_H2_PIN, MOTOR_IN2_H2_PIN, MOTOR_EN_H2_PIN, speed); 
    motor_forward(MOTOR_IN1_H1_PIN, MOTOR_IN2_H1_PIN, MOTOR_EN_H1_PIN, speed);
    //sleep_ms(250);     
}
