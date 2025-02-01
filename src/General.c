#include <General_U4C4.h>

void PrintPinOut(PinOut pin){
    printf("Pin: %d\n", pin.Pin);
    printf("Input: %d\n", pin.Input);
}

void Config(PinOut* pins, int size){
    stdio_init_all();

    // for(int i = 0;i < size; i++)
    //     PrintPinOut(pins[i]);
    // printf("configurada a saída\n");

    for(int i = 0; i < size; i++)
        InitPin(pins[i].Pin, pins[i].Input);

    //printf("configuração terminada\n");
}

void InitPin(int PIN, bool input){
    gpio_init(PIN);
    if (input)
        SetInput(PIN);
    else
        SetOutput(PIN);
}

void SetInput(int PIN){
    gpio_set_dir(PIN, GPIO_IN);
    gpio_pull_down(PIN);
    //printf("%d set as Input\n", PIN);
}

void SetOutput(int PIN){
    gpio_set_dir(PIN, GPIO_OUT);
    gpio_put(PIN, 0);
    //printf("%d set as Output\n", PIN);
}