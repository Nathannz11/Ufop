#include <stdlib.h> 
#include <stdio.h> 
#include "circulo.h"
struct circulo {
    Ponto* centro ;
    float raio ;
};


Circulo* circ_cria ( Ponto * centro , float raio ){
    Circulo * circ = ( Circulo *) malloc ( sizeof ( Circulo ));
    if ( circ == NULL ) {
        printf (" Memória insuficiente !\n");
        exit (1) ;
    }
    circ -> centro = centro ;
    circ -> raio = raio ;
    return circ ;
}

void circ_libera ( Circulo * circ ){
    pto_libera(circ->centro);
    free(circ);
}

float circ_area ( Circulo * circ ){
    return PI * circ -> raio * circ -> raio ;
}

int circ_interior ( Circulo * circ , Ponto * pt ){
    float d = pto_distancia ( circ -> centro , pt );
    return (d < circ->raio);
}
