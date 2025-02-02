#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"
#include <General_U4C4.h>
#include <MainLED_U4C4.h>
#include <LEDMatrix_U4C4.h>
#include <Interrupt_U4C4.h>

#define PINS 3
#define BUTTONA 5
#define BUTTONB 6

int main(){

    PIORefs pio;

    PinOut pins[PINS] = {
        { 
            .Pin = LEDPIN, 
            .Input = false
        },
        { 
            .Pin = BUTTONA, 
            .Input = true
        },
        { 
            .Pin = BUTTONB, 
            .Input = true
        }
    };
    Sketch sketch = {
        .Figure = {
            0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0
        },
        .Index = 0,
        .MainColor = {
            .Red = 0.01,
            .Green = 0.0,
            .Blue = 0.0
        },
        .BackgroundColor = {
            .Red = 0.0,
            .Green = 0.0,
            .Blue = 0.01
        }
    };
    uint32_t ledConf = 0;

    Config(pins, PINS, &pio);
    //PrintPIO(pio);
    InitPIO(&pio, MATRIXPIN);

    Draw(sketch, ledConf, pio);
    //PrintPIO(pio);
    SetInterrupt(sketch, ledConf, pio, Draw, BUTTONA, BUTTONA);
    
    while(1){
        //Count(sketch, ledConf, pio, 1000);
        TogglePin(LEDPIN, 200); // pisca 5 vezes por segundo/ 1 vez a cada 200 ms
        //printf("LAÇO\n");
    }

}

