//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#ifndef MODEL_HPP
#define MODEL_HPP

#include "flow.hpp"
#include <vector>

using namespace std;

//! Class Model
/**
* Essa classe representa um modelo de sistema do código.
*/  
class Model{
    private:

    string nome; /*!< Esse atributo contem um nome para o modelo.*/
    vector<System*> sistemas; /*!< Esse atributo um vetor de ponteiros de sistemas do modelo.*/
    vector<Flow*> flows; /*!< Esse atributo um vetor de flows de sistemas do modelo.*/
    

    public:
    
    /*!
        Construtor mais elaborado para a classe Model.
        \param nome nome para o modelo
        \return Model - Um objeto da classe Model.
    */
    Model(string nome = "" );

    virtual ~Model();

    /*!
        Retorna o atributo nome do objeto da classe Model.
        \return string - o conteúdo de atributo nome.
    */
    string getNome() const ;

    /*!
        Seta o atributo nome do objeto da classe Model.
        \param nome que será setado ao Modelo atual.
    */
    void setNome(string nome);

    /*!< Responsável por executar o sistema de acordo com o tipo de flow contido (variando a equacao).*/    
    void run(double inicio = 0.0, double fim = 0.0);
    
    /*!< Adiciona um sistema ao modelo*/
    void add(System* system);

    /*!< Adiciona um flow ao modelo*/
    void add(Flow* flow);

    /*!< Remove um sistema do modelo*/
    void remove(System* sistema);
    /*!< Remove um flow do modelo*/
    void remove(Flow* flow);

    private: 
    Model(const Model& model);

    /*! Sobrecarga do operador = para a classe Sistema */
    Model& operator=(const Model& model);
};

#endif
