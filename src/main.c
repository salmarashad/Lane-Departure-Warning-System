#include "pico/stdlib.h"
#include <stdio.h>
#include "sensors/light/light.h"
#include "sensors/ultrasonic/ultrasonic.h"
#include "sensors/infrared/infrared.h"
#include "actuators/led/led.h"
#include "actuators/buzzer/buzzer.h"
#include "actuators/motor/motor.h"
#include "FreeRTOS.h"
#include "task.h"

#define LIGHT_TASK_PRIORITY (1)
#define INFRA_TASK_PRIORITY (1)
#define ULTRA_TASK_PRIORITY (1)

#define TASK_STACK_SIZE (configMINIMAL_STACK_SIZE)
bool LeftLane = true;
void lightTask(void *pvParameters)
{
    while (1)
    {
        float mapped_value = light_read(LIGHT_READ_IN);
        printf("Light sensor mapped value: %f\n", mapped_value);
        if (mapped_value > 50)
        {
            led_on(RIGHT_LED_PIN);
            led_on(LEFT_LED_PIN);
            printf("I am in the dark\n");
        }
        else
        {
            led_off(RIGHT_LED_PIN);
            led_off(LEFT_LED_PIN);
            printf("I see light\n");
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void infraTask(void *pvParameters)
{
    while (1)
    {
        int infra_state = infra_read(IR_SENSOR_PIN);
        if (infra_state == 0)
        {
            printf("I detected white!\n");
        }
        else
        {
            buzzer_beep(1000);
            printf("I detected black :(\n");
        }
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void ultraTask(void *pvParameters)
{
    while (1)
    {
        ultra_trigger();
        float distance = get_distance();

        printf("Ultrasonic detected distance: %.2f cm\n", distance);
        if (distance >= STOP_DISTANCE)
        {
            motor_forward(MOTOR_IN1_H1_PIN, MOTOR_IN2_H1_PIN, MOTOR_EN_H1_PIN, 60);
            motor_forward(MOTOR_IN1_H2_PIN, MOTOR_IN2_H2_PIN, MOTOR_EN_H2_PIN, 60);
        }
        else
        {
            if (LeftLane)
            {
                LeftLane = false;
                motor_turn_right(180);
                vTaskDelay(pdMS_TO_TICKS(320));
                motor_forward(MOTOR_IN1_H1_PIN, MOTOR_IN2_H1_PIN, MOTOR_EN_H1_PIN, 60);
                motor_forward(MOTOR_IN1_H2_PIN, MOTOR_IN2_H2_PIN, MOTOR_EN_H2_PIN, 60);
                vTaskDelay(pdMS_TO_TICKS(1700));
                // sleep_ms(1800);  // Adjust duration_ms for 90-degree left turn
                motor_turn_left(180);
                vTaskDelay(pdMS_TO_TICKS(210)); // Adjust duration_ms for 90-degree right turn
               
            }
            else
            {
                LeftLane = true;
                motor_turn_left(180);
                vTaskDelay(pdMS_TO_TICKS(320));
                motor_forward(MOTOR_IN1_H1_PIN, MOTOR_IN2_H1_PIN, MOTOR_EN_H1_PIN, 60);
                motor_forward(MOTOR_IN1_H2_PIN, MOTOR_IN2_H2_PIN, MOTOR_EN_H2_PIN, 60);
                vTaskDelay(pdMS_TO_TICKS(1700));
                // sleep_ms(1800);  // Adjust duration_ms for 90-degree left turn
                motor_turn_right(160);
                vTaskDelay(pdMS_TO_TICKS(210)); // Adjust duration_ms for 90-degree right turn
                
            }

            // sleep_ms(500);
        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

int main()
{
    stdio_init_all();
    light_init();
    infra_init();
    ultra_init();
    buzzer_init();
    led_init();
    motor_init();

    xTaskCreate(lightTask, "LightTask", TASK_STACK_SIZE, NULL, LIGHT_TASK_PRIORITY, NULL);
    xTaskCreate(infraTask, "InfraTask", TASK_STACK_SIZE, NULL, INFRA_TASK_PRIORITY, NULL);
    xTaskCreate(ultraTask, "UltraTask", TASK_STACK_SIZE, NULL, ULTRA_TASK_PRIORITY, NULL);

    vTaskStartScheduler();

    return 0;
}