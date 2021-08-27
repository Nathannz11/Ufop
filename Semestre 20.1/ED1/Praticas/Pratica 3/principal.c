#include "diretorio.h"

int main(){
    Diretorio* diretorio;
    char nomeTemp[20];
    int qtd_max_arquivoDir;
    //printf("Informe o nome do diretório: ");
    scanf("%s", nomeTemp);
    //printf("Informe a quantidade máxima de arquivos: ");
    scanf("%d", &qtd_max_arquivoDir);
    diretorio = alocarDiretorio(nomeTemp, qtd_max_arquivoDir);

    int codigo, n;
    float tamanho;
    char nomeAtual[20], nomeNovo[20], extensao[20];
    
    do
    {   
        //printf("Informe o codigo: ");
        scanf("%d", &codigo);
        switch (codigo){
            case 2:
                liberarDiretorio(&diretorio);
                break;
            case 3:
                //printf("Informa a quantidade de arquivos a serem adicionados: ");
                scanf("%d", &n);
                setQtd_aqruivo(diretorio, n);
                
                for(int i = 0; i < n; i++){
                    //printf("Informe o nome do %dº arquivo: ", i+1);
                    scanf("%s",nomeTemp);
                    //printf("Informe a extensão do %dº arquivo: ", i+1);
                    scanf("%s", extensao);
                    //printf("Informe o tamanho do %dº arquivo: ", i+1);
                    scanf("%f", &tamanho);
                    alocarArquivoDir(diretorio, nomeTemp, extensao, tamanho);
                }
                break;
            case 4:
                //printf("Informe o nome do arquivo a ser removido: ");
                scanf("%s", nomeTemp);
                n = getQtd_arquivo(diretorio);
                for(int i = 0; i < n; i++){
                    if(!strcmp(nomeTemp, getNomeAdir(diretorio, i))){
                        setArquivo(diretorio, i);
                        setQtd_aqruivo(diretorio, -1);
                        //printf("%d", getQtd_arquivo(diretorio));
                    }
                }
                printf("%d\n", 1);
                break;
            case 5:
                tamanho = 0.0;
                n = getQtd_arquivo(diretorio);
                for(int i = 0; i < n; i++)
                    tamanho+= GetTamanho(*getArquivo(diretorio, i));
                setTamanho_total(diretorio, tamanho);
                //printf("Tamanho do diretório: %f\n", GetTamanho_total(diretorio));
                printf("%f\n", GetTamanho_total(diretorio));
                break;
            case 6:
                //printf("Nome do diretório: %s", getNomeD(diretorio));
                printf("%s\n", getNomeD(diretorio));
                break;
            case 7:
                //printf("Informe o novo nome para o diretório: ");
                scanf("%s", nomeTemp); 
                setNomeD(diretorio, nomeTemp);

                break;
            case 8:
                //printf("Informe o nome atual e o novo nome para o arquivo: ");
                scanf("%s",nomeAtual);
                scanf("%s", nomeNovo);
                n = getQtd_arquivo(diretorio);
                for(int i = 0; i < n; i++){
                    if(!strcmp(nomeAtual, getNomeAdir(diretorio, i))){
                        setNomeAdir(diretorio, nomeNovo, i);
                    }
                }
                printf("%d\n", 1);
                break;
            case 9:
                n = getQtd_arquivo(diretorio);
                for(int i = 0; i < n; i++){
                    //printf("Arquivo %d: %s\n", i+1, getNomeAdir(diretorio,i));
                    printf("%s\n", getNomeAdir(diretorio,i));
                }
                break;
            case 10:
                //printf("Programa encerrado!\n");
                break;
            default:
                //printf("Código inválido.\n");
                break;
        }
    } while (codigo != 10);
    

    return 0;
}