add_executable(${ProjectName}
    main.c
    actuators/led/led.c
    actuators/motor/motor.c
    actuators/buzzer/buzzer.c
    sensors/infrared/infrared.c
    sensors/ultrasonic/ultrasonic.c
    sensors/light/light.c
)

target_include_directories(${ProjectName} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${ProjectName} 
    pico_stdlib 
    FreeRTOS-Kernel-Heap4 
    hardware_adc
    hardware_pwm
)

pico_add_extra_outputs(${ProjectName})