#include "main.h"

static Main mymain;

extern "C" void app_main(void) { // idf uses C linkage, so we need to use extern "C"
    ESP_ERROR_CHECK(mymain.setup());
    while (1) {
        mymain.loop();
    }
}

esp_err_t Main::setup(void) {
    ESP_LOGI(LOG_TAG, "Setting up...");
    return ESP_OK;
}

void Main::loop(void) {
    ESP_LOGI(LOG_TAG, "Looping...");
    vTaskDelay(pdSECOND);
}

Main::Main() {
    // Constructor definition
}

Main::~Main() {
    // Destructor definition
}