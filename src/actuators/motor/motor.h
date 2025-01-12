#ifndef MOTOR_H
#define MOTOR_H

#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

#ifndef PICO_STDIO_H
#define PICO_STDIO_H
#include "pico/stdlib.h"
#endif

//H1 Left
#define MOTOR_IN1_H1_PIN   15  // in 1 and 3
#define MOTOR_IN2_H1_PIN   14   // in 2 and 4
#define MOTOR_EN_H1_PIN    19   

//H2 Right
#define MOTOR_IN1_H2_PIN   5  //in 1 and 3
#define MOTOR_IN2_H2_PIN   6   //in 2 and 4
#define MOTOR_EN_H2_PIN    4  

void motor_init(void);        
void motor_forward(uint16_t pin1,uint16_t pin2,uint16_t enable,uint8_t speed);
void motor_backward(uint16_t pin1,uint16_t pin2,uint16_t enable,uint8_t speed);
void motor_stop(uint16_t pin1,uint16_t pin2,uint16_t enable);             
void motor_set_speed(uint16_t enable,uint8_t speed);
void motor_turn_left(uint8_t speed);
void motor_turn_right(uint8_t speed);

#endif // MOTOR_H
