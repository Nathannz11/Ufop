#include "funcionario.h"

struct funcionario{
    char nome[20];
    char email[50];
    int idade;
};

char* getNomeF(Funcionario* funcionario){
    return funcionario->nome;
}

void setNomeF(Funcionario* funcionario, char* nome){
    strcpy(funcionario->nome, nome);
}

char* getEmail(Funcionario* funcionario){
    return funcionario->email;
}

void setEmail(Funcionario* funcionario, char* email){
    strcpy(funcionario->email, email);
}

int getIdade(Funcionario* funcionario){
    return funcionario->idade;
}

void setIdade(Funcionario* funcionario, int idade){
    funcionario->idade = idade;
}

Funcionario** new_funciorarios_array(int qtd_max_funcionarios){
    Funcionario** aux = malloc(qtd_max_funcionarios * sizeof(Funcionario));
    return aux;
}

Funcionario* new_funcionario(char* nome, char* email, int idade){
    Funcionario* aux = malloc(sizeof(Funcionario));
    strcpy(aux->nome,nome);
    strcpy(aux->email,email);
    aux->idade = idade;
    return aux;
}

void liberar_funcionarios(Funcionario*** funcionario){
    free(**funcionario);
    **funcionario = NULL;
}