#ifndef GENERALU4C_H
#define GENERALU4C_H

#include "pico/stdlib.h"
#include "hardware/pio.h"

/**
 * @brief Estrutura que representa um pino de entrada ou saída.
 *
 * Esta estrutura armazena um número de pino GPIO e define se ele 
 * será configurado como entrada ou saída.
 */
typedef struct PinSet {
    int Pin;   /// Número do pino GPIO.
    bool Input; /// Define se o pino será entrada ou saída.
} PinOut;

/**
 * @brief Estrutura que representa a PIO
 *
 * Esta estrutura armazena o endereço de memória da referência para 
 * a PIO, o endereço da máquina de estados, e o valor do offset.
 */
typedef struct PIO {
    PIO Address; //Ponteiro para PIO
    int StateMachine; // Endereço da máquina de estados
    int Offset; // Valor do offset
} PIORefs;

/**
 * @brief Estrutura que representa a três cores RGB
 *
 * Esta estrutura armazena os coeficientes das cores Vermelho, Verde e
 * Azul, para organizar melhor as cores que serão enviadas para os LEDs WS2812.
 */
typedef struct RGB {
    double Red;
    double Green;
    double Blue;
} RGB;

/**
 * @brief Imprime as informações de um pino GPIO.
 *
 * Esta função recebe um `PinOut` e exibe no console seu número de pino 
 * e se ele está configurado como entrada ou saída.
 *
 * @param pin Estrutura `PinOut` contendo o número do pino e seu modo de operação.
 */
void PrintPinOut(PinOut);

/**
 * @brief Imprime as informações da PIO configurada.
 *
 * Esta função recebe um `PIORefs` e exibe no console seu endereço de memória 
 * .
 *
 * @param pio Estrutura `PIORefs`, com endereço de memória, valor de offset e endereço
 * da Máquina de estados
 */
void PrintPIO(PIORefs);

/**
 * @brief Imprime as informações do RGB configurado.
 *
 * Esta função recebe um `RGB` e exibe no console os valores de vermelho, verde 
 * e azul.
 *
 * @param color Estrutura `RGB`, com valores de vermelho, verde e azul
 * da Máquina de estados
 */
void PrintRGB(RGB);

/**
 * @brief Configura um conjunto de pinos GPIO.
 *
 * Esta função inicializa e configura vários pinos GPIO como entrada ou saída, 
 * com base em um array de estruturas `PinOut`, e atribui uma PIO à referência `PIORefs`.
 *
 * @param pins Ponteiro para um array de estruturas `PinOut` contendo os pinos e seus modos.
 * @param size Número total de pinos no array.
 * @param pio Endereço da PIO a qual se deseja atribuir informações de PIO.
 */
void Config(PinOut*, int, PIORefs*);


/**
 * @brief Inicializa a PIO com um valor de offset específico.
 *
 * Esta função inicializa a PIO configurada com o valor de offset dado,
 * permitindo o controle da Máquina de Estado no pino correspondente.
 *
 * @param pio Estrutura `PIORefs` a ser configurada.
 * @param offset O valor do offset a ser configurado.
 */
void InitPIO(PIORefs*, int);

/**
 * @brief Inicializa o pino GPIO especificado como entrada ou saída.
 *
 * Esta função configura o pino GPIO fornecido para operar no modo de entrada ou saída, 
 * dependendo do valor do segundo parâmetro.
 *
 * @param pin O número do pino GPIO a ser inicializado.
 * @param input Se for `true`, o pino será configurado como entrada; se for `false`, como saída.
 */
void InitPin(int, bool);

/**
 * @brief Configura o pino GPIO especificado como entrada.
 *
 * Esta função define o pino GPIO como entrada, permitindo a leitura de sinais externos.
 *
 * @param pin O número do pino GPIO a ser configurado como entrada.
 */
void SetInput(int);

/**
 * @brief Configura o pino GPIO especificado como saída.
 *
 * Esta função define o pino GPIO como saída, permitindo o envio de sinais.
 *
 * @param pin O número do pino GPIO a ser configurado como saída.
 */
void SetOutput(int);

#endif
