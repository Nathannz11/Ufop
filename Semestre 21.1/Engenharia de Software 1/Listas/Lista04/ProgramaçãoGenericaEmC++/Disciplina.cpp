#include "Disciplina.hpp"

static int _id = 0;

Disciplina::Disciplina(string nome, int cargaHoraria) : nome(nome), cargaHoraria(cargaHoraria){
    setId();
}

void Disciplina::setId(){
    this->id = _id++;
}

int Disciplina::getId() const{
    return this->id;
}

void Disciplina::setNome(string nome){
    this->nome = nome;
}

string Disciplina::getNome() const{
    return this->nome;
}

void Disciplina::setCargaHoraria(int cargaHoraria){
    this->cargaHoraria = cargaHoraria;
}

int Disciplina::getCargaHoraria() const{
    return this->cargaHoraria;
}

bool Disciplina::operator<(const Disciplina& d) const{
    return this->cargaHoraria < d.cargaHoraria;
}
bool Disciplina::operator>(const Disciplina& d) const{
    return this->cargaHoraria > d.cargaHoraria;
}
bool Disciplina::operator<=(const Disciplina& d) const{
    return this->cargaHoraria <= d.cargaHoraria;
}
bool Disciplina::operator>=(const Disciplina& d) const{
    return this->cargaHoraria >= d.cargaHoraria;
}
bool Disciplina::operator==(const Disciplina& d) const{
    return this->cargaHoraria == d.cargaHoraria;
}
bool Disciplina::operator==(int x) const{
    return this->cargaHoraria == x;
}
bool Disciplina::operator==(float x) const{
    return this->cargaHoraria == x;
}
bool Disciplina::operator==(double x) const{
    return this->cargaHoraria == x;
}
int Disciplina::operator+(int x) {
    return this->cargaHoraria + x;
}
float Disciplina::operator+(float x) {
    return this->cargaHoraria + x;
}
double Disciplina::operator+(double x) {
    return this->cargaHoraria + x;
}