#include <Interrupt_U4C4.h>

InterruptContext interruptContext = {NULL, {0}, 0, {0}, 0, 0};
volatile uint32_t intervalButtonA = -1;
volatile uint32_t intervalButtonB = 0;

void SetInterrupt(Sketch sketch, uint32_t ledConf, PIORefs pio, InterruptCallback callback, int inputPin, int pinToCompare[2]) {
    //printf("\n\n%d\n\n", inputPin);
    interruptContext.callback = callback;
    interruptContext.sketch = sketch;
    interruptContext.ledConf = ledConf;
    interruptContext.pio = pio;
    interruptContext.inputPin = inputPin;
    interruptContext.pinToCompare[0] = pinToCompare[0];
    interruptContext.pinToCompare[1] = pinToCompare[1];

    gpio_set_irq_enabled_with_callback(inputPin, GPIO_IRQ_EDGE_RISE, true, &HandleInterruptMatrix);
}

void HandleInterruptMatrix(uint gpio, uint32_t events) {

    //Sketch sketch = (*interruptContext.sketch);
    //PIORefs pio = (*interruptContext.pio);
    //PrintSketch(sketch);
    //PrintPIO(pio);
    uint32_t interval = gpio == 5 ? intervalButtonA : intervalButtonB; 
    uint32_t currentTime = to_us_since_boot(get_absolute_time());
    if(currentTime - interval > 250000){
        interruptContext.inputPin = gpio;
        if (interruptContext.callback != NULL) {
            //printf("\n\nINPUT: %d\n\n",interruptContext.inputPin);
            if (interruptContext.inputPin == interruptContext.pinToCompare[0]){
                //printf("\n\nBOTÃO1\n\n");
                intervalButtonA = currentTime;
                //printf("\nbuttonA: %d\n", intervalButtonA);
                if (interruptContext.sketch.Index < 10 )
                    interruptContext.sketch.Index += 1;
                else
                    interruptContext.sketch.Index = 0;
            } else {
                //printf("\n\nBOTÃO2\n\n");
                intervalButtonB = currentTime;
                //printf("\nbuttonB: %d\n", intervalButtonB);
                if (interruptContext.sketch.Index > 0 )
                    interruptContext.sketch.Index -= 1;
                else
                    interruptContext.sketch.Index = 9;
            }
            //printf("\nindex: %d\n", interruptContext.sketch.Index);
            ArrayCopySameSize(interruptContext.sketch.Figure, SketchArray(interruptContext.sketch.Index), VECTORSIZE);
            interruptContext.callback(interruptContext.sketch, interruptContext.ledConf, interruptContext.pio);
        }
    }
}