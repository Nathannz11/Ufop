#include <stdio.h>
#include "circulo.h"

int main(){
    int x, y;
    printf("Informe o valor do ponto: ");
    printf("x = ");
    scanf("%d", &x);
    printf("y = ");
    scanf("%d", &y);

    Ponto* p1 = pto_cria(x, y);
    Circulo* circ = circ_cria(p1, 1000);

    printf("Área(circ): %f\n", circ_area(circ));

    if(circ_interior(circ,p1))
        printf("P1 pertence ao círculo\n");
    else 
        printf("p1 não pertence ao círculo\n");

    circ_libera(circ);
    return 0;
}