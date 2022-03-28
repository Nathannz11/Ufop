/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

double funcao(double x) {
    return pow(x,3) + (0.4201*pow(x,2)) - (3*x) - 1;
}

double funcIteracao(double a, double b, double fa, double fb) {
    return ((a*fb) - (b*fa)) / (fb-fa);
}

int main()
{
    double fa, fb, xk, fxk;
    int interval = 5;
    double a = 1, b = 2;
    printf("k  |ak       |f(ak)     |bk       |f(bk)    |xk       |f(xk)   \n");
    for(int i = 0; i < interval; i++) {
        fa = funcao(a);
        fb = funcao(b);
        xk = funcIteracao(a, b, fa, fb);
        fxk = funcao(xk);
        printf("%d  |  %.5lf|  %.5lf|  %.5lf|  %.5lf|  %.5lf|  %.5lf \n", i, a, fa, b, fb, xk, fxk);
        if((fa * fxk) < 0) {
            b = xk;
        } else {
            a = xk;
        }
    }
    
    return 0;
}
