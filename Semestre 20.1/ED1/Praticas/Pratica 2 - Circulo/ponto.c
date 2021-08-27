// Nathann Zini dos Reis 19.2.4007
//
//  Created by Amanda Savio Nascimento e Silva on 26/01/21.
//

#include "ponto.h"
#include <stdlib.h>
#include <stdio.h>

struct ponto{
    float x, y;
    
};

float raiz_quadrada(float numero)
{
    int n;
    float recorre = numero;

    for (n = 0; n < 10; ++n)
          recorre = recorre/2 + numero/(2*recorre);

    return(recorre);
}
Ponto* pto_cria(float x, float y){
    Ponto* aux = (Ponto*) malloc(sizeof(Ponto));
    if(aux==NULL)
    {
        printf("Memoria eh insuficiente");
        exit(1);
    }
    aux->x= x;
    aux->y = y;
    return aux;
    
    
    
}
void pto_libera(Ponto* p){
    free(p);
    
}
void pto_acessa(Ponto* p, float *x, float* y){
    *x = p->x;
    *y = p->y;
}
void pto_atribui(Ponto* p, float x, float y){
    p->x = x;
    p->y = y;
}
float pto_distancia(Ponto* p1, Ponto *p2){
    float dx = (p2->x - p1->x);
    float dy = (p2->y - p1->y);
    return raiz_quadrada((dx*dx) + (dy*dy));
}

void pto_imprime(Ponto* p1){
    printf("x = %f; y = %f\n", p1->x, p1->y);
}
