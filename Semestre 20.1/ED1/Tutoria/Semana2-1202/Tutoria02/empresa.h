#ifndef empresa_h
#define empresa_h

#include "funcionario.h"

typedef struct empresa Empresa;

char* getNomeE(Empresa* empresa);

void setNomeE(Empresa* empresa, char* nome);

char* getCidade_sede(Empresa* empresa);

void setCidade_sede(Empresa* empresa, char* cidade);

int getQtd_max_funcionarios(Empresa* empresa);

void setQtd_max_funcionarios(Empresa* empresa, int qtd_max_funcionarios);

int getQtd_funcionarios(Empresa* empresa);

void setQtd_funcionarios(Empresa* empresa, int qtd_funcionarios);

Empresa* new_empresa_array(char* nome, char* cidade,int qtd_max_funcionario);

void new_funcionario_empresa(Empresa* empresa, char* nome, char* email, int idade);

void remove_funcionario_empresa(Empresa* empresa, int i);

char* getNomeF_empresa(Empresa* empresa, int i);

void setNomeF_empresa(Empresa* empresa, int i, char* novoNome);

char* getEmail_empresa(Empresa* empresa, int i);

void setEmail_empresa(Empresa* empresa, int i, char* novoEmail);

int getIdade_empresa(Empresa* empresa, int i);

void setIdade_empresa(Empresa* empresa, int i, int novaIdade);

void liberar_empresa(Empresa** empresa);


#endif