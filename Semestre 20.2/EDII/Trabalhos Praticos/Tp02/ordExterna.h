#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "heap.h"
#include "dado.h"

typedef struct{
    TipoDado vetorPivo[N];
}TipoArea;

typedef TipoDado TipoRegistro;



void quicksortExterno(FILE **, FILE **, FILE **, FILE ** , int, int);
void leSup(FILE **, TipoRegistro *, int *, short *);
void leInf(FILE **, TipoRegistro *, int *, short *);
void inserirArea(TipoArea *, TipoRegistro *, int *);
void escreverMax(FILE **, TipoRegistro , int *);
void escreverMin(FILE **, TipoRegistro , int *){
void retiraMax(TipoArea *, TipoRegistro *, int *);
void retiraMin(TipoArea *, TipoRegistro *, int *);
void particao(FILE **, FILE **, FILE **, TipoArea , int , int , int *, int *);
void faVazia(TipoArea *);
int obterNumCelOcupadas(TipoArea *);
void retiraUltimo(TipoArea *, TipoRegistro *);

