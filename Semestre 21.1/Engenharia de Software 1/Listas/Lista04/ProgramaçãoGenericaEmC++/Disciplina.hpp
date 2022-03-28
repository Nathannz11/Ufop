#ifndef DISCIPLINA_HPP
#define DISCIPLINA_HPP

#include <iostream>
#include <string>

using namespace std;

class Disciplina
{
    int id;
    string nome;
    int cargaHoraria;


public:
    Disciplina(string = "", int = 0);

    void setId();
    int getId() const;

    void setNome(string nome);
    string getNome() const;

    void setCargaHoraria(int cargaHoraria);

    int getCargaHoraria() const;

    bool operator<(const Disciplina& e) const;
    bool operator>(const Disciplina& e) const;
    bool operator<=(const Disciplina& e) const;
    bool operator>=(const Disciplina& e) const;
    bool operator==(const Disciplina& e) const;

    bool operator==(int x) const;
    bool operator==(float x) const;
    bool operator==(double x) const;

    int operator+(int x);
    float operator+(float x);
    double operator+(double x);
};

#endif