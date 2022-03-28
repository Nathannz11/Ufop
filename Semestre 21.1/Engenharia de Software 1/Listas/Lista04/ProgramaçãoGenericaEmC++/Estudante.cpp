#include "Estudante.hpp"

static int _id = 0;

Estudante::Estudante(string nome, string matricula, float nota) : nome(nome), matricula(matricula), nota(nota){
    setId();
}

void Estudante::setId(){
    this->id = _id++;
}

int Estudante::getId() const{
    return this->id;
}

void Estudante::setNome(string nome){
    this->nome = nome;
}

string Estudante::getNome() const{
    return this->nome;
}
void setMatricula(string matricula){
    this->matricula = matricula;
}

string getMatricula(){
    return this->matricula;
}

void Estudante::setNota(float nota){
    this->nota = nota;
}
float Estudante::getNota(){
    return this->nota;
}

ostream& operator<<(ostream& os, const Estudante& e){
    os << "Nome     : " << e.nome << endl;
    os << "Matricula: " << e.matricula << endl;
    os << "Nota: " << e.nota << endl;

    return os;
}
bool Estudante::operator<(const Estudante& e) const{
    return this->nota < e.nota;
}
bool Estudante::operator>(const Estudante& e) const{
    return this->nota > e.nota;
}
bool Estudante::operator<=(const Estudante& e) const{
    return this->nota <= e.nota;
}
bool Estudante::operator>=(const Estudante& e) const{
    return this->nota >= e.nota;
}
bool Estudante::operator==(const Estudante& e) const{
    return this->nota == e.nota;
}
bool Estudante::operator==(int x) const{
    return this->nota == x;
}
bool Estudante::operator==(float x) const{
    return this->nota == x;
}
bool Estudante::operator==(double x) const{
    return this->nota == x;
}
int Estudante::operator+(int x) {
    return this->nota + x;
}
float Estudante::operator+(float x) {
    return this->nota + x;
}
double Estudante::operator+(double x) {
    return this->nota + x;
}