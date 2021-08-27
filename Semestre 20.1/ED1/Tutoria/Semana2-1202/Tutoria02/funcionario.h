#ifndef funcionario_h
#define funcionario_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct funcionario Funcionario;

char* getNomeF(Funcionario* funcionario);

void setNomeF(Funcionario* funcionario, char* nome);

char* getEmail(Funcionario* funcionario);

void setEmail(Funcionario* funcionario, char* email);

int getIdade(Funcionario* funcionario);

void setIdade(Funcionario* funcionario, int idade);

Funcionario** new_funciorarios_array(int qtd_max_funcionarios);

Funcionario* new_funcionario(char* nome, char* email, int idade);

void liberar_funcionarios(Funcionario*** funcionario);

#endif