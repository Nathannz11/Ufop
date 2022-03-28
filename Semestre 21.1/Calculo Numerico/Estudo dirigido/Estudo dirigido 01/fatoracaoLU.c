//Nathann Zin dos Reis 19.2.4007
#include <stdio.h>
#define n 6 // dimensão da matriz
int main(){
    float a[6][6] ={  { 1, 2, 0, 2, 1, 3},
                    { 5, 2, 2, 2,-1,-4},
                    {-5, 5, 3, 5, 1, 4},
                    { 3, 0,-1,-2, 3, 2},
                    {-2, 3, 5, 3,-1, 0},
                    {-1,-2, 4, 5, 2,-5}};

    float l[6][6]={ { 0, 0, 0, 0, 0, 0},
                    { 0, 0, 0, 0, 0, 0},
                    { 0, 0, 0, 0, 0, 0},
                    { 0, 0, 0, 0, 0, 0},
                    { 0, 0, 0, 0, 0, 0},
                    { 0, 0, 0, 0, 0, 0}};
    float u[6][6]={{0, 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0, 0}};

    float soma;
    //Fatoração LU
    for(int m = 0; m < n; m++){
        for(int j = m; j < n; j++){
            soma = 0.0;
            for(int k = 0; k < m - 1; k++){
                soma += l[m][k] * u[k][j];
            }
            u[m][j] = a[m][j] - soma;
        }
        l[m][m] = 1;
        for(int i = m + 1; i < n; i++){
            soma = 0.0;
            for(int k = 0; k < m - 1; k++){
                soma += l[i][k] * u[k][m];
            }
            l[i][m] = ( a[i][m] - soma) / u[m][m];
        }
    }
    //Impressão das matrizes resultantes
    printf("Matriz A: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%.2f\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\nMatriz L: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%.2f\t", l[i][j]);
        }
        printf("\n");
    }
    printf("\nMatriz U: \n");   
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%.2f\t", u[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;}