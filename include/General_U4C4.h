#ifndef GENERALU4C_H
#define GENERALU4C_H

#include "pico/stdlib.h"

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
 * @brief Imprime as informações de um pino GPIO.
 *
 * Esta função recebe um `PinOut` e exibe no console seu número de pino 
 * e se ele está configurado como entrada ou saída.
 *
 * @param pin Estrutura `PinOut` contendo o número do pino e seu modo de operação.
 */
void PrintPinOut(PinOut);

/**
 * @brief Configura um conjunto de pinos GPIO.
 *
 * Esta função inicializa e configura vários pinos GPIO como entrada ou saída, 
 * com base em um array de estruturas `PinOut`.
 *
 * @param pins Ponteiro para um array de estruturas `PinOut` contendo os pinos e seus modos.
 * @param size Número total de pinos no array.
 */
void Config(PinOut*, int);

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
