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


int64_t TogglePinCallback(alarm_id_t id, void *user_data);

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

    int buttons[2] = {BUTTONA, BUTTONB};

    SetInterrupt(sketch, ledConf, pio, Draw, BUTTONA, buttons);
    
    SetInterrupt(sketch, ledConf, pio, Draw, BUTTONB, buttons);

    add_alarm_in_ms(200, TogglePinCallback, NULL, true);
    
    while(1){
        //Count(sketch, ledConf, pio, 1000);
        //TogglePin(LEDPIN, 200); // pisca 5 vezes por segundo/ 1 vez a cada 200 ms
        //printf("LAÇO\n");
        sleep_ms(1);
    }


}

/**
 * @brief Função de callback para alternar o estado de um pino de LED.
 * 
 * Esta função é chamada para alternar o nível lógico de um pino específico (geralmente um LED) de 
 * acordo com a sua configuração de entrada. Ela altera o estado do pino de `HIGH` para `LOW` ou vice-versa.
 * A função retorna um valor que representa o próximo intervalo de tempo para a próxima execução da callback,
 * permitindo que a alternância ocorra a intervalos regulares.
 * 
 * @return O tempo em microssegundos até que a próxima execução da callback seja disparada.
 *         No caso desta função, ela retorna `200000`, ou seja, 200 mil microssegundos (200ms), 
 *         para que o LED seja alternado periodicamente a cada 200ms.
 */
int64_t TogglePinCallback(alarm_id_t id, void *user_data) {
    int toggleLevel = !gpio_get(LEDPIN);
    gpio_put(LEDPIN, toggleLevel);
    return 200000;
}

