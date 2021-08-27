//Nathann Zini dos Reis 19.2.4007
#include "jogoDaVelha.h"

void iniciarTabuleiro(Jogo* jogo){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            jogo->tabuleiro[i][j] = 0;
        }
        
    }
    
}

char menu(){
    char temp;
    printf("Deseja jogar continuar (c) ou parar (p)\n");
    getchar();
    scanf("%c", &temp);
    return temp;
}

void jogadaUser(Jogo* jogo){
    scanf("%d %d", &jogo->l, &jogo->c);
    jogo->tabuleiro[jogo->l][jogo->c] = 1;
}

void jogadaPC(Jogo* jogo){
    int linha = 0, coluna = 0, dPrincipal = 0, dSecundaria = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            linha += jogo->tabuleiro[i][j];
            coluna += jogo->tabuleiro[j][i];
        }
        if(linha == -2){
            for(int j = 0; j < 3; j++){
                if(jogo->tabuleiro[i][j] == 0){
                    jogo->tabuleiro[i][j] = -1;
                    return;
                }
                    
            }
        }
        if(coluna == -2){
            for(int j = 0; j < 3; j++){
                if(jogo->tabuleiro[j][i] == 0){
                    jogo->tabuleiro[j][i] = -1;
                    return;
                }
                    
            }
        }
        if(linha == 2){
            for(int j = 0; j < 3; j++){
                if(jogo->tabuleiro[i][j] == 0){
                    jogo->tabuleiro[i][j] = -1;
                    return;
                }
                    
            }
        }
        if(coluna == 2){
            for(int j = 0; j < 3; j++){
                if(jogo->tabuleiro[j][i] == 0){
                    jogo->tabuleiro[j][i] = -1;
                    return;
                }
                    
            }
        }
        dPrincipal += jogo->tabuleiro[i][i];
        dSecundaria += jogo-> tabuleiro[i][2-i];
    }

    if(dPrincipal == -2){
        for(int i = 0; i < 3; i++){
            if(jogo->tabuleiro[i][i] == 0){
                jogo->tabuleiro[i][i] = -1;
                return;
            }
                    
        }
    }
    if(dSecundaria == -2){
        for(int i = 0; i < 3; i++){
            if(jogo->tabuleiro[i][2 - i] == 0){
                jogo->tabuleiro[i][2 - i] = -1;
                return;
            }
                    
        }
    }
    if(dPrincipal == 2){
        for(int i = 0; i < 3; i++){
            if(jogo->tabuleiro[i][i] == 0){
                jogo->tabuleiro[i][i] = -1;
                return;
            }
                    
        }
    }
    if(dSecundaria == 2){
        for(int i = 0; i < 3; i++){
            if(jogo->tabuleiro[i][2 - i] == 0){
                jogo->tabuleiro[i][2 - i] = -1;
                return;
            }
                    
        }
    }
        
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(jogo->tabuleiro[i][j] == 0){
                jogo->tabuleiro[i][j] = -1;
                return;
            }     
        }
    }
        
}

void mostrarJogo(Jogo* jogo){
    printf("\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(jogo->tabuleiro[i][j] == -1)
                printf("x |");
            else if(jogo->tabuleiro[i][j] == 1)
                printf("o |");
            else if(jogo->tabuleiro[i][j] == 0)
                printf("  |");
        }
        printf("\n");
        printf("__ __ __\n\n");
    }
}

int verificarVitoria(Jogo* jogo){
    int linha = 0, coluna = 0, dPrincipal = 0, dSecundaria = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            linha += jogo->tabuleiro[i][j];
            coluna += jogo->tabuleiro[j][i];
        }
        if(linha == 3 || coluna == 3)
            return 3;
        else if(linha == -3 || coluna == -3)
            return -3;
        dPrincipal += jogo->tabuleiro[i][i];
        dSecundaria += jogo-> tabuleiro[i][2-i];
    }

    if(dPrincipal == 3 || dSecundaria ==3)
        return 3;
    else if(dPrincipal == -3 || dSecundaria == -3)
        return -3;
    else return 0;
}

int partida(Jogo* jogo){
    int flag;
    char temp;
    system("clear");
    printf("NOVO JOGO\n");
    for(int i = 0; i < 9; i++){
        mostrarJogo(jogo);
        jogadaUser(jogo);
        if(verificarVitoria(jogo) == 3){
            jogo->scoreUser++;
            break;
        }
        i++;
        if(i == 8){
            jogo->draw++;
            break;
        } 
        jogadaPC(jogo);
        if(verificarVitoria(jogo) == -3){
            jogo->scorePC++;
            break;
        }
    }
    jogo->MatchCounter--;       
    iniciarTabuleiro(jogo);

    if(!jogo->MatchCounter){
        temp = menu();
        if (temp == 'c'){
            jogo->MatchCounter = 2;
            return jogo->MatchCounter;
        }
        
    }
    return jogo->MatchCounter;
}