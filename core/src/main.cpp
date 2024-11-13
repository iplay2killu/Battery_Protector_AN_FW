#include "main.h"

#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#define LOG_TAG "MAIN"

static Main my_main;

extern "C" void app_main(void)
{
    ESP_LOGI(LOG_TAG, "Creating default event loop");
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    ESP_LOGI(LOG_TAG, "Initialising NVS");
    ESP_ERROR_CHECK(nvs_flash_init());

    ESP_ERROR_CHECK(my_main.setup());

    while (true)
    {
        my_main.loop();
    }
}

esp_err_t Main::setup(void)
{
    esp_err_t status{ESP_OK};

    ESP_LOGI(LOG_TAG, "Setup!");

    // status |= led.init();

    cppButton.enableInterrupt(GPIO_INTR_NEGEDGE);
    cppButton.setEventHandler(&button_event_handler);

    return status;
}

void Main::loop(void)
{
    ESP_LOGI(LOG_TAG, "Hello World!");

    ESP_LOGI(LOG_TAG, "LED on");
    led.setLevel(true);
    vTaskDelay(pdSECOND * 2);

    ESP_LOGI(LOG_TAG, "LED off");
    led.setLevel(false);
    vTaskDelay(pdSECOND * 2);
}

void Main::button_event_handler(void *handler_args, esp_event_base_t base, int32_t id, void *event_data)
{
    std::cout << "Button triggered interrupt with ID: " << id << '\n';
}