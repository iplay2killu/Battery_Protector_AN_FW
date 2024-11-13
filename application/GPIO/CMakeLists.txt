set(SOURCES Gpio_input.cpp Gpio_output.cpp)

idf_component_register(SRCS ${SOURCES}
                        INCLUDE_DIRS .
                        REQUIRES driver
                                    esp_event)

