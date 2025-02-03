#ifndef INTERRUPTU4C4_H
#define INTERRUPTU4C4_H

#include <General_U4C4.h>
#include "LEDMatrix_U4C4.h"

/**
 * @brief Tipo de função callback usada para manipulação de interrupções.
 * 
 * Este tipo de função callback é usado para definir o comportamento
 * que deve ser executado quando a interrupção for disparada.
 * A função recebe um objeto `Sketch`, um valor `ledConf` (configuração dos LEDs)
 * e um objeto `PIORefs` que contém as referências de PIO.
 *
 * @param sketch A estrutura contendo os dados de desenho a serem manipulados.
 * @param ledConf A configuração dos LEDs que será utilizada.
 * @param pio A estrutura que contém referências para o PIO.
 */
typedef void (*InterruptCallback)(Sketch, uint32_t, PIORefs);

/**
 * @brief Estrutura de contexto para a interrupção.
 * 
 * Esta estrutura contém todas as informações necessárias para lidar
 * com uma interrupção, como a função callback a ser chamada,
 * o objeto `Sketch`, a configuração dos LEDs, as referências do PIO
 * e os pinos de entrada e de comparação utilizados para a interrupção.
 */
typedef struct {
    InterruptCallback callback; /** Função callback a ser chamada na interrupção. */
    Sketch sketch;              /** Estrutura contendo os dados do desenho. */
    uint32_t ledConf;           /** Configuração dos LEDs a ser utilizada. */
    PIORefs pio;                /** Referências para o PIO. */
    int inputPin;               /** Pino de entrada que ativa a interrupção. */
    int pinToCompare[2];           /** Pino que será comparado para disparar a interrupção. */
} InterruptContext;

/** 
 * @brief Variável global do contexto da interrupção.
 * 
 * Esta variável armazena as informações do contexto da interrupção,
 * incluindo o callback e os parâmetros necessários.
 */
extern InterruptContext interruptContext;

/**
 * @brief Configura a interrupção com os parâmetros fornecidos.
 * 
 * Esta função configura a interrupção para ser disparada no pino de
 * entrada especificado e chama a função callback definida.
 * A função `HandleInterruptMatrix` é usada para tratar a interrupção.
 * 
 * @param sketch A estrutura `Sketch` que contém os dados do desenho.
 * @param ledConf A configuração dos LEDs.
 * @param pio Referências para o PIO.
 * @param callback Função que será chamada quando a interrupção ocorrer.
 * @param inputPin Pino de entrada que aciona a interrupção.
 * @param pinToCompare Pino a ser comparado para a interrupção.
 */
void SetInterrupt(Sketch, uint32_t, PIORefs, InterruptCallback, int, int[2]);

/**
 * @brief Função de tratamento de interrupção para o acionamento de pinos GPIO.
 * 
 * Esta função é chamada automaticamente quando ocorre uma interrupção em um pino de entrada configurado.
 * Ela verifica se o tempo entre a última interrupção e a atual respeita o tempo de debounce, evitando que múltiplas
 * interrupções sejam acionadas devido ao "bouncing" de um botão. Caso o tempo de debounce seja válido, a interrupção
 * é processada e a função callback configurada é chamada.
 *
 * @param gpio O número do pino GPIO que gerou a interrupção.
 * @param events Os eventos que ocorreram no pino (por exemplo, borda de subida ou descida).
 * 
 * @note O debounce é implementado para evitar múltiplas detecções rápidas do botão.
 *       O tempo de debounce é configurável e é aplicado ao verificar o intervalo de tempo entre interrupções consecutivas.
 *       Caso o tempo entre as interrupções seja menor que o valor de debounce, a interrupção é ignorada.
 *
 **/
void HandleInterruptMatrix(uint gpio, uint32_t events);

#endif
