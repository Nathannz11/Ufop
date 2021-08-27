#include <stdio.h>
#include "carro.h"

int main(){
    int n;
    printf("Informe a quantidade de carros: ");
    scanf("%d", &n);

    Carro* carro = malloc(n * sizeof(Carro));

    printf("Digite as informações de cada carro: ");

    for(int i = 0; i < n; i++){
        printf("---- CARRO %d----\n", i+1);
        printf("Modelo: ");
        fgets(carro[i].modelo, 50, stdin);
        printf("Cor: ");
        fgets(carro[i].cor, 15, stdin);
        printf("Ano: ");
        scanf("%d", &carro[i].ano);
        printf("Preço: ");
        scanf("%f", &carro[i].preco);
        printf("Kilometragem: ");
        scanf("%f", &carro[i].KmRodado);
    }

    int flag;
    do
    {
        printf("MENU DE OPÇÃO\n");
        printf("1 - Create\n");
        printf("2 - Read\n");
        printf("3 - Update\n");
        printf("4 - Delete\n");
        printf("5 - Buscar Carro\n");
        printf("6 - Buscar Carro Específico\n");
        printf("0 - Sair\n");

        scanf("%d", &flag);

        switch (flag)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            printf("Informe o índice do carro que deseja modificar: ");
            int indice;
            scanf("%d", &indice);
                
            printf("Informe qual campo deseja atualizar: \n");
            printf("1 - modelo\n");
            printf("2 - cor\n");
            printf("3 - ano\n");
            printf("4 - preço\n");
            printf("5 - Km rodado\n");

            int escolha;
            scanf("%d", &escolha);

            switch (escolha)
            {
            case 1:
                printf("Informe o novo modelo: ");
                char novoModelo[50];
                fgets(novoModelo, 50, stdin);
                carro[indice].setModelo(&carro[indice], novoModelo);
                break;
            case 2:
                printf("Informe a nova cor: ");
                char novaCor[15];
                fgets(novaCor, 15, stdin);
                carro[indice].setCor(&carro[indice], novaCor);
                break;
            case 3:
                printf("Informe o novo ano: ");
                int novoAno;
                scanf("%d", &novoAno);
                carro[indice].setAno(&carro[indice], novoAno);
                break;
            case 4:
                printf("Informe o novo preço: ");
                float novoPreco;
                scanf("%f", &novoPreco);
                carro[indice].setPreco(&carro[indice], novoPreco);
                break;
            case 5:
                printf("Informe a nova Kilometragem: ");
                float novoKm;
                scanf("%f", &novoKm);
                carro[indice].setKmRodado(&carro[indice], novoKm);
                break;
            default:
                printf("Opção inválida!\n");
                break;
            }
            break;
        case 4:
            break;
        case 0:
            break;        
        default:
            break;
        }

    } while (flag);
    

    return 0;
}