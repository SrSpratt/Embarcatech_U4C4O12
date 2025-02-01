#ifndef MAINLEDU4C_H
#define MAINLEDU4C_H

#include "pico/stdlib.h"

#define LEDPIN 11

/**
 * @brief Alterna o estado do LED no pino especificado em um intervalo determinado.
 *
 * Esta função alterna o estado do LED conectado ao pino especificado 
 * em um intervalo periódico. O LED será ligado e desligado de acordo 
 * com o valor do período fornecido em milissegundos.
 *
 * @param pin O pino GPIO ao qual o LED está conectado.
 * @param period O tempo, em milissegundos, entre cada alternância (pisca-pisca).
 */
void TogglePin(int, int);

#endif
