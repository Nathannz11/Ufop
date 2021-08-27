//Nathann Zini dos Reis 19.2.4007
#include "jokempo.h"

// 0 - pedra
// 1 - papel
// 2 - tesoura



int main(){
    srand(time(NULL));
    Jokempo* jokempo = alocarJokempo();
    
    int n, i;
    char flag = 'c';

    do{
        for(i = 0; i < getRodadas(jokempo); i++){
            scanf("%d", &n);
            setEscolhaPessoa(jokempo, n);
            setEscolhaComputadorJok(jokempo);

            printf("%d ", getEscolhaComputador(jokempo));

            if(getEscolhaPessoa(jokempo) == 0){
                if(getEscolhaComputador(jokempo) == 0){
                    setEmpates(jokempo, 1);
                    printf("0\n");
                }else if(getEscolhaComputador(jokempo) == 1){
                    setVitoriasComputador(jokempo, 1);
                    printf("-1\n");
                }else if(getEscolhaComputador(jokempo) == 2){
                    setVitoriasPessoa(jokempo, 1);
                    printf("1\n");
                }
            }else if(getEscolhaPessoa(jokempo) == 1){
                if(getEscolhaComputador(jokempo) == 0){
                    setVitoriasPessoa(jokempo, 1);
                    printf("1\n");
                }else if(getEscolhaComputador(jokempo) == 1){
                    setEmpates(jokempo, 1);
                    printf("0\n");
                }else if(getEscolhaComputador(jokempo) == 2){
                    setVitoriasComputador(jokempo, 1);
                    printf("-1\n");
                }
            }else if(getEscolhaPessoa(jokempo) == 2){
                if(getEscolhaComputador(jokempo) == 0){
                    setVitoriasComputador(jokempo, 1);
                    printf("-1\n");
                }else if(getEscolhaComputador(jokempo) == 1){
                    setVitoriasPessoa(jokempo, 1);
                    printf("1\n");
                }else if(getEscolhaComputador(jokempo) == 2){
                    setEmpates(jokempo, 1);
                    printf("0\n");
                }
            }

        }
        getchar();
        scanf("%c", &flag);
        setRodadas(jokempo, 2);
    }while (flag != 'p');
    
    printf("%d %d\n", getVitoriasPessoa(jokempo), getVitoriasComputador(jokempo));

    if(getVitoriasPessoa(jokempo) > getVitoriasComputador(jokempo))
        printf("Você ganhou!!\n");
    else if(getVitoriasPessoa(jokempo) < getVitoriasComputador(jokempo))
        printf("Voce perdeu!!\n");
    else printf("Empate!!\n");

    liberarJogadores(jokempo);
    return 0;
}