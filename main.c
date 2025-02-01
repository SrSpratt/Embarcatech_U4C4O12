#include "pico/stdlib.h"
#include <stdio.h>
#include <General_U4C4.h>
#include <MainLED_U4C4.h>

#define PINS 1

int main(){

    PinOut pins[PINS] = {
        { .Pin = LEDPIN, .Input = false}
    };

    Config(pins, PINS);

    while(1){
        TogglePin(LEDPIN, 200); // pisca 5 vezes por segundo/ 1 vez a cada 200 ms
    }

}