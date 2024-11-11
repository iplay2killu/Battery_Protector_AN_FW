#pragma once

# include "driver/gpio.h"

namespace GPIO {

    class GPIO_output{
        bool _state = false;
        gpio_num_t _pin;
    public:
        constexpr GPIO_output(const gpio_num_t pin, const bool state) : _pin{pin}, _state{state} { // member initializer list (more efficient as it avoids default initialization)
            init(pin, state);
        };
        esp_err_t init(const gpio_num_t pin, const bool state);

        esp_err_t set(const bool state);
        esp_err_t toggle(void);
        bool state(void) { return _state; };

        ~GPIO_output();
    };
}

/* CPP concepts i have to brush up on:
    virtual functions
    pure virtual functions
    abstract classes
    inheritance
    polymorphism
    encapsulation
    friend functions
    operator overloading
    templates
    list initializaiton vs direct initialization
*/