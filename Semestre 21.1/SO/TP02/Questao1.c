//Nathann Zini Dos Reis
//Matricula: 19.2.4007


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define READ  0
#define WRITE 1

void menu();

int main()
{
    //Menu de interação
    menu();
    
    int saldo[2];
    int opcao[2];
    int caractere = 0;
    
    
    if (pipe(saldo) < 0 || pipe(opcao) < 0) {
        printf("pipe creation error\n");
        exit(1);
    }
    
    int aux = 0;
    
    if(write(saldo[WRITE], &aux, sizeof(int)) == -1){
        printf("writing in pipe error\n");
    }
    
    
    pid_t pidPai = getpid();
    pid_t filho1 = fork();
    
    if(filho1 < 0){
        printf("fork creation error\n");
        exit(1);
    }
    fflush(stdin);
    
    pid_t filho2 = -1;
    
    if(getpid() == pidPai){
        filho2 = fork();
        if(filho2 < 0)
            exit(1);
        if(filho2 == 0)
            filho1 = -1;
    }
    
    
    pid_t filho3 = -1;
    
    if(getpid() == pidPai){
        filho3 = fork();
        if(filho3 < 0)
            exit(1);
        if(filho3 == 0){
            filho1 = -1;
            filho2 = -1;
        }
    }
    
    if (getpid() == pidPai){
        int x;
        // K & k (Finalizar execução)
        while(caractere != 107 || caractere != 75){

            // + S s k K -
            do{
                caractere = (int)getchar();
            }while((caractere != 43) && (caractere != 83) && (caractere != 115) && (caractere != 107) && (caractere != 75) && (caractere != 45));

            write(opcao[WRITE], &caractere, sizeof(int));

            // k K
            if (caractere == 107 ||caractere == 75){
                printf("-----------------------------\n");
                kill(filho1, SIGKILL);
                kill(filho2, SIGKILL);
                kill(filho3, SIGKILL);
                kill(getpid(), SIGKILL);
                exit(0);
            }
            
        }
    }

    else if (filho1 == 0){

        int operacao;
        int x;

        do{
            read(opcao[READ], &operacao, sizeof(int));

            // +
            if (operacao == 43){
                printf("-----------------------------\n");
                printf("Soma em PID  : %d\n", getpid());
                printf("-----------------------------\n");
                read(saldo[READ], &x, sizeof(int));
                x += 100;
                write(saldo[WRITE], &x, sizeof(int));
            }

            else{
                write(opcao[WRITE], &operacao, sizeof(int)); 
            }

        // k K
        }while(operacao != 107 ||operacao != 75 );
    }

    else if (filho2 == 0){

        int operacao;
        int x;

        do{
            read(opcao[READ], &operacao, sizeof(int));

            // -
            if(operacao == 45){
                printf("-----------------------------\n");
                printf("Remove em PID: %d\n", getpid());
                printf("-----------------------------\n");
                read(saldo[READ], &x, sizeof(int));
                x -= 100;
                write(saldo[WRITE], &x, sizeof(int));
            }

            else{
                write(opcao[WRITE], &operacao, sizeof(int)); 
            }

        // k K
        }while(operacao != 107 || operacao != 75);
    }

    else if (filho3 == 0){

        int caractere;
        int x;

        do{
            read(opcao[READ], &caractere, sizeof(int));

            // S s
            if (caractere == 83 || caractere == 115){
                read(saldo[READ], &x, sizeof(int));
                printf("-----------------------------\n");
                printf("Print em PID : %d\n", getpid());
                printf("Saldo        : %d\n", x);
                printf("-----------------------------\n");
                write(saldo[WRITE], &x, sizeof(int));
            }

            else{
                write(opcao[WRITE], &caractere, sizeof(int)); 
            }

        // k K
        }while(caractere != 107 || caractere != 75);
    }
    
    return 0;
   
}

void menu(){
    printf("\n");
    printf("Pressione [+] para somar 100 UD\n");
    printf("Pressione [-] para subtrair 100 UD\n");
    printf("Pressione [s] para imprimir o valor do saldo\n");
    printf("Pressione [k] para finalizar a execucao\n");
    printf("Pressione [ENTER] para confirmar as operacoes\n\n");
    printf("Valor inicial de saldo: 0\n");
}