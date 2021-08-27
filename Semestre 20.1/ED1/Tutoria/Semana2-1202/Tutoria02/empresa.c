#include "empresa.h"

struct empresa{
    char nome[20];
    char cidade_sede[20];
    int qtd_max_funcionarios;
    int qtd_funcionarios;
    Funcionario** funcionarios;
};

char* getNomeE(Empresa* empresa){
    return empresa->nome;
}

void setNomeE(Empresa* empresa, char* nome){
    strcpy(empresa->nome, nome);
}

char* getCidade_sede(Empresa* empresa){
    return empresa->cidade_sede;
}

void setCidade_sede(Empresa* empresa, char* cidade){
    strcpy(empresa->cidade_sede, cidade);
}

int getQtd_max_funcionarios(Empresa* empresa){
    return empresa->qtd_max_funcionarios;
}

void setQtd_max_funcionarios(Empresa* empresa, int qtd_max_funcionarios){
    empresa->qtd_max_funcionarios = qtd_max_funcionarios;
}

int getQtd_funcionarios(Empresa* empresa){
    return empresa->qtd_funcionarios;
}

void setQtd_funcionarios(Empresa* empresa, int qtd_funcionarios){
    empresa->qtd_funcionarios += qtd_funcionarios;
}

Empresa* new_empresa_array(char* nome, char* cidade,int qtd_max_funcionario){
    Empresa* aux = malloc(sizeof(Empresa));
    strcpy(aux->cidade_sede, cidade);
    strcpy(aux->nome, nome);
    aux->qtd_max_funcionarios = qtd_max_funcionario;
    aux->funcionarios = new_funciorarios_array(qtd_max_funcionario);
    aux->qtd_funcionarios = 0;
    return aux;
}

void new_funcionario_empresa(Empresa* empresa, char* nome, char* email, int idade){
    for(int i = 0; i < getQtd_max_funcionarios(empresa);i++){
        if(empresa->funcionarios[i] != NULL){
            empresa->funcionarios[i] = new_funcionario(nome, email, idade);
        }
    }
}

void remove_funcionario_empresa(Empresa* empresa, int i){
    empresa->funcionarios[i] = empresa->funcionarios[getQtd_funcionarios(empresa) - 1];
    empresa->funcionarios[getQtd_funcionarios(empresa) - 1] = NULL;
    setQtd_funcionarios(empresa, -1);
}


char* getNomeF_empresa(Empresa* empresa, int i){
    return getNomeF(empresa->funcionarios[i]);
}

void setNomeF_empresa(Empresa* empresa, int i, char* novoNome){
    setNomeF(empresa->funcionarios[i], novoNome);
}

char* getEmail_empresa(Empresa* empresa, int i){
    return getEmail(empresa->funcionarios[i]);
}

void setEmail_empresa(Empresa* empresa, int i, char* novoEmail){
    setEmail(empresa->funcionarios[i], novoEmail);
}

int getIdade_empresa(Empresa* empresa, int i){
    return getIdade(empresa->funcionarios[i]);
}

void setIdade_empresa(Empresa* empresa, int i, int novaIdade){
    setIdade(empresa->funcionarios[i], novaIdade);
}

void liberar_empresa(Empresa** empresa){
    liberar_funcionarios(&(*empresa)->funcionarios);
    free(*empresa);
}