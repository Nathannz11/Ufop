/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

double funcao(double x) {
    return pow(x,3) + cos(x);
}

double funcIteracao(double a, double b) {
    return (a+b)/2;
}

int main()
{
    double fa, fb, xk, fxk, aux;
    int interval = 9;
    double a = -1, b = 0;
    printf("k  |ak        |bk        | |bk-ak|  |xk        |f(xk)      \n");
    for(int i = 0; i < interval; i++) {
        xk = funcIteracao(a, b);
        fxk = funcao(xk);
        aux = b - a;
        printf("%d  |  %.5lf|  %.5lf|   %.5lf|  %.5lf|  %.5lf \n", i, a, b, aux, xk, fxk);
        if((fa * fxk) < 0) {
            b = xk;
        } else {
            a = xk;
        }
    }
    
    return 0;
}
