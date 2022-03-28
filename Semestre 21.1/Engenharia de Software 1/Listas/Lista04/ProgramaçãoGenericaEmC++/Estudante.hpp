#ifndef ESTUDANTE_HPP
#define ESTUDANTE_HPP

#include <iostream>
#include <string>


using namespace std;

class Estudante
{
    int id;
    string nome;
    string matricula;
    float nota;



public:
    Estudante(string = "", string = "", float = 0.0);

    void setId();
    int getId() const;

    void setNome(string nome);
    string getNome() const;

    void setMatricula(string matricula);
    string getMatricula();

    void setNota(float nota);
    float getNota();

    friend ostream& operator<<(ostream& os, const Estudante& e);

    bool operator<(const Estudante& e) const;
    bool operator>(const Estudante& e) const;
    bool operator<=(const Estudante& e) const;
    bool operator>=(const Estudante& e) const;
    bool operator==(const Estudante& e) const;

    bool operator==(int x) const;
    bool operator==(float x) const;
    bool operator==(double x) const;

    int operator+(int x);
    float operator+(float x);
    double operator+(double x);
};

#endif