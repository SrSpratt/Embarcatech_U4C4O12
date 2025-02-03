#include <General_U4C4.h>
#include <MainLED_U4C4.h>


void TogglePin(int pin, int period){
    int pinLevel = gpio_get(pin);
    // printf("Pin Level: %d\n", pinLevel);
    // printf("Pin: %d\n", pin);
    gpio_put(pin, !pinLevel);
    sleep_ms(period);
}