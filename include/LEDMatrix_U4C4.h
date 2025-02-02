#ifndef LEDMATRIXU4C4_H
#define LEDMATRIXU4C4_H

#include "General_U4C4.h"

#define MATRIXPIN 7
#define VECTORSIZE 25

typedef struct Drawing {
    double Figure[25];
    RGB MainColor;
    RGB BackgroundColor;
} Sketch;

void PrintArraySketch(double*, int);
void PrintSketch(Sketch);
double* SketchArray(int);
void ArrayCopySameSize(double*, double*, int);
uint32_t RGBMatrix(RGB);
void Draw(Sketch, uint32_t, PIORefs);
void Count(Sketch, uint32_t, PIORefs, int delay);

#endif