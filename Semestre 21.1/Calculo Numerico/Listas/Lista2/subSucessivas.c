#include <stdio.h>
#define n 4

void substituicoesSucessivas(int l[n][n], int*c, int **x){
    int soma = 0;
    for(int i = 0; i < n; i++){
        *x[i] = 0;
    }

    *x[0] = c[0] / l[0][0];


    for(int i = 1; i < n; i++){
        soma = 0;

        for(int j = 0; j < i; j++){
            soma += l[i][j] * (*x[j]);
        }
        *x[i] = (c[i] - soma)/l[i][i];
    }
}

int main(){
    int a[n][n] = {{2, 0, 0, 0}, {3, 5, 0, 0}, {1, -6, 8, 0}, {1, 4, -3, 9}};
    int b[n] = {4, 1, 48, 6};
    int *resposta[n];
    substituicoesSucessivas(a, b, resposta);
    printf("Resposta: [");
    for(int i = 0; i < n; i++){
        printf("%d ", *resposta[i]);
    }
    printf("]\n");
    return 0;
}