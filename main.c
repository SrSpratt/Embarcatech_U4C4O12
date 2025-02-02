#include "pico/stdlib.h"
#include <stdio.h>
#include <General_U4C4.h>
#include <MainLED_U4C4.h>
#include <LEDMatrix_U4C4.h>

#define PINS 1

int main(){

    PIORefs pio;

    PinOut pins[PINS] = {
        { .Pin = LEDPIN, .Input = false}
    };
    Sketch sketch = {
        .Figure = {
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0
        },
        .MainColor = {
            .Red = 1.0,
            .Green = 0.0,
            .Blue = 0.0
        },
        .BackgroundColor = {
            .Red = 1.0,
            .Green = 1.0,
            .Blue = 1.0
        }
    };
    uint32_t ledConf = 0;

    Config(pins, PINS, &pio);
    PrintPIO(pio);
    InitPIO(&pio, MATRIXPIN);

    Draw(sketch, ledConf, pio);

    while(1){
        TogglePin(LEDPIN, 200); // pisca 5 vezes por segundo/ 1 vez a cada 200 ms
    }

}