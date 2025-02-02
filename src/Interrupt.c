#include <Interrupt_U4C4.h>

InterruptContext interruptContext = {NULL, {0}, 0, {0}, 0, 0};

void SetInterrupt(Sketch sketch, uint32_t ledConf, PIORefs pio, InterruptCallback callback, int inputPin, int pinToCompare) {
    
    interruptContext.callback = callback;
    interruptContext.sketch = sketch;
    interruptContext.ledConf = ledConf;
    interruptContext.pio = pio;
    interruptContext.inputPin = inputPin;
    interruptContext.pinToCompare = pinToCompare;

    gpio_set_irq_enabled_with_callback(inputPin, GPIO_IRQ_EDGE_RISE, true, &HandleInterruptMatrix);
}

void HandleInterruptMatrix() {

    //Sketch sketch = (*interruptContext.sketch);
    //PIORefs pio = (*interruptContext.pio);
    //PrintSketch(sketch);
    //PrintPIO(pio);

    if (interruptContext.callback != NULL) {
        if (interruptContext.inputPin == interruptContext.pinToCompare){
            if (interruptContext.sketch.Index < 10)
                interruptContext.sketch.Index += 1;
            else
                interruptContext.sketch.Index = 0;
            ArrayCopySameSize(interruptContext.sketch.Figure, SketchArray(interruptContext.sketch.Index), VECTORSIZE);
            interruptContext.callback(interruptContext.sketch, interruptContext.ledConf, interruptContext.pio);
        }
    }
}