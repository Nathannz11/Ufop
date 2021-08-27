#include "empresa.h"

int main(){
    char nomeEmpresa[20];
    char cidadeEmpresa[20];
    int qtd_max_funcionario_Empresa;

    scanf("%[^\n]s", nomeEmpresa);
    scanf("\n%[^\n]s", cidadeEmpresa);
    scanf("%d", &qtd_max_funcionario_Empresa);

    Empresa* empresa = new_empresa_array(nomeEmpresa, cidadeEmpresa, qtd_max_funcionario_Empresa);
    
    char temp[20];
    char nomeFuncionario[20];
    char emailFuncionario[50];
    int idadeFuncionario;
    int i, n, codigo;
    do
    {   
        //printf("Informe o codigo: ");
        scanf("%d", &codigo);
        switch (codigo){
            case 1:
                
                for(i = 0; i < getQtd_funcionarios(empresa); i++){
                    printf("%s %s %d\n", getNomeF_empresa(empresa, i), getEmail_empresa(empresa, i), getIdade_empresa(empresa, i));
                }
                break;
            case 2:
                liberar_empresa(&empresa);
                break;
            case 3:
                scanf("%d", &n);
                setQtd_funcionarios(empresa, n);
                
                for(i = 0; i < n; i++){
                    scanf("%s", nomeFuncionario);
                    scanf("%s", emailFuncionario);
                    scanf("%d", &idadeFuncionario);
                    new_funcionario_empresa(empresa, nomeFuncionario, emailFuncionario, idadeFuncionario);
                }
                break;
            case 4:
                scanf("%s", nomeFuncionario);
                for(i = 0; i < getQtd_funcionarios(empresa); i++){
                    if(!strcmp(nomeFuncionario, getNomeF_empresa(empresa, i))){
                        remove_funcionario_empresa(empresa, i);
                    }
                }
                break;
            case 5:
                printf("%s", getNomeE(empresa));
                break;
            case 6:
                printf("%s", getCidade_sede(empresa));
                break;
            case 7:
                scanf("%[^\n]s", nomeEmpresa);
                setNomeE(empresa, nomeEmpresa);
                scanf(" ");
                break;
            case 8:
                scanf("%s %s", nomeFuncionario, temp);
                for(i = 0; i < getQtd_funcionarios(empresa); i++){
                    if(!strcmp(temp, getNomeF_empresa(empresa, i))){
                        setNomeF_empresa(empresa, i, temp);
                    }
                }
                break;
            case 0:
                break;
            default:
                break;
        }
    } while (codigo != 10);
    

    return 0;
}