#pragma once
#include "esp_mac.h"
#include "freertos/FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "freeRTOS/task.h"
#include "esp_err.h"  // Include this header for esp_err_t

#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#define LOG_TAG "MAIN"

#define pdSECOND pdMS_TO_TICKS(1000)

class Main final {
public:
    Main();
    esp_err_t setup(void);
    void loop(void);
    ~Main();
};
