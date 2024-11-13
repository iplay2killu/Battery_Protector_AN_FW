#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#define pdSECOND pdMS_TO_TICKS(1000)

#include "esp_event.h"
#include "nvs_flash.h"
#include <iostream>

#include "C:\Users\nima.shirazi\Desktop\Personal_Projects\E-Bike_PMS\application\Gpio\Gpio.h"

class Main final
{
public:
    esp_err_t setup(void);
    void loop(void);

    GPIO::GpioOutput led{GPIO_NUM_2, true};

    // Repurpose the BOOT button to work as an input
    GPIO::GpioInput cppButton{GPIO_NUM_9};

    // Event Handler for cppButton
    static void button_event_handler(void *handler_args, esp_event_base_t base, int32_t id, void *event_data);
};
