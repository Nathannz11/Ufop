// Nathann Zini dos Reis 19.2.4007
//
//

#include <stdio.h>
#include "ponto.h"

int main(){
    
    Ponto* p1 = pto_cria(-4.0,4.0);
    Ponto* p2 = pto_cria(0 , 0);

    float x, y;

    pto_acessa(p1, &x, &y);
    printf("Ponto P1 = (%f, %f)\n", x, y);

    pto_atribui(p2, 3.0, 4.0);

    pto_acessa(p2, &x, &y);
    printf("Ponto P2 = (%f, %f)\n", x, y);

    printf("Distancia entre os pontos é: %f\n", pto_distancia(p1, p2));

    
    return 0;
}
