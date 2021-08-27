#ifndef circulo_h
#define circulo_h
#include <stdio.h>
#include "ponto.h"
typedef struct circulo Circulo ;

#define PI 3.14159

Circulo * circ_cria (Ponto* centro , float raio);
void circ_libera (Circulo* circ);
float circ_area (Circulo* circ);
int circ_interior (Circulo* circ , Ponto* pt);
#endif 
