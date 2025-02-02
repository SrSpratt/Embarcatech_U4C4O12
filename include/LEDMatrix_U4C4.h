#ifndef LEDMATRIXU4C4_H
#define LEDMATRIXU4C4_H

#include "General_U4C4.h"

#define MATRIXPIN 7 // Número do pino para a matriz de LEDs.
#define VECTORSIZE 25 // Tamanho do vetor que representa a matriz de LEDs (5x5).

/**
 * @brief Estrutura que representa o desenho da matriz de LEDs.
 *
 * Esta estrutura armazena a figura (representada por um vetor de 25 valores), 
 * as cores principais e de fundo do desenho a ser exibido na matriz de LEDs.
 */
typedef struct Drawing {
    double Figure[25]; // Vetor de 25 valores representando a figura a ser exibida na matriz.
    int Index; // Guarda o valor do desenho
    RGB MainColor;     // Cor principal a ser exibida na matriz de LEDs.
    RGB BackgroundColor; // Cor de fundo da matriz de LEDs.
} Sketch;

/**
 * @brief Imprime um array de valores de desenho.
 *
 * Esta função imprime o conteúdo do array de valores de desenho (`Figure`).
 *
 * @param array Ponteiro para o array de valores de desenho.
 * @param size Tamanho do array.
 */
void PrintArraySketch(double* array, int size);

/**
 * @brief Imprime as informações de um desenho.
 *
 * Esta função imprime as informações completas de um desenho (`Sketch`), 
 * incluindo a figura, a cor principal e a cor de fundo.
 *
 * @param sketch Estrutura `Sketch` contendo as informações do desenho.
 */
void PrintSketch(Sketch sketch);

/**
 * @brief Cria um array para representar a figura do desenho.
 *
 * Esta função cria um array de valores de desenho baseado no índice passado 
 * como parâmetro. O array resultante pode ser usado para exibir a figura 
 * desejada na matriz de LEDs.
 *
 * @param index Índice que será utilizado para gerar o array de desenho.
 * @return Um ponteiro para o array de valores de desenho gerado.
 */
double* SketchArray(int index);

/**
 * @brief Copia os valores de um array para outro.
 *
 * Esta função copia os valores de um array de origem para um array de destino 
 * de forma segura, mantendo o mesmo tamanho entre os dois arrays.
 *
 * @param src Ponteiro para o array de origem.
 * @param dest Ponteiro para o array de destino.
 * @param size Tamanho dos arrays.
 */
void ArrayCopySameSize(double* src, double* dest, int size);

/**
 * @brief Converte uma cor RGB para um valor uint32_t.
 *
 * Esta função converte uma cor RGB (com valores de vermelho, verde e azul) 
 * para um valor `uint32_t`, para ser utilizado ao controlar os LEDs.
 *
 * @param color A cor `RGB` a ser convertida.
 * @return O valor `uint32_t` correspondente à cor.
 */
uint32_t RGBMatrix(RGB color);

/**
 * @brief Desenha a figura na matriz de LEDs.
 *
 * Esta função utiliza as informações do desenho (`Sketch`) e as envia para a 
 * matriz de LEDs, definindo as cores e os pixels com base na estrutura `Sketch`.
 *
 * @param sketch Estrutura `Sketch` contendo as informações do desenho.
 * @param ledConf Valor de configuração dos LEDs.
 * @param pio Referência para a PIO configurada.
 */
void Draw(Sketch sketch, uint32_t ledConf, PIORefs pio);

/**
 * @brief Contabiliza o desenho e controla o tempo de exibição.
 *
 * Esta função contabiliza a quantidade de tempo em que o desenho será exibido 
 * na matriz de LEDs, com base no parâmetro `delay`. Ela também faz a transição 
 * entre diferentes desenhos ou configurações de LEDs.
 *
 * @param sketch Estrutura `Sketch` contendo as informações do desenho.
 * @param ledConf Valor de configuração dos LEDs.
 * @param pio Referência para a PIO configurada.
 * @param delay A quantidade de tempo que o desenho será exibido.
 */
void Count(Sketch sketch, uint32_t ledConf, PIORefs pio, int delay);

#endif
