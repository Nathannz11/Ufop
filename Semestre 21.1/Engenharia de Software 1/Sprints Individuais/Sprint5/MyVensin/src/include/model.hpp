//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#ifndef MODEL_HPP
#define MODEL_HPP

class Flow;
class System;
#include <vector>
#include <string>


using namespace std;

//! Class Model
/**
* Essa classe representa um modelo de sistema do código.
*/  
class Model{    

    public:

    virtual ~Model(){}

    /*!
        Retorna o atributo nome do objeto da classe Model.
        \return string - o conteúdo de atributo nome.
    */
    virtual string getNome() const = 0 ;
    /*!
        Seta o atributo nome do objeto da classe Model.
        \param nome que será setado ao Modelo atual.
    */
    virtual void setNome(string nome) = 0;

    /*!
        Responsável por executar o sistema de acordo com o tipo de flow contido (variando a equacao).
        \param inicio o tempo inicial.
        \param fim o tempo final.    
    */    
    virtual void run(double inicio = 0.0, double fim = 0.0) = 0;
    
    /*!
        Adiciona um sistema ao modelo
        \param system sistema a ser adicionado.
    */
    virtual void add(System* system) = 0;

    /*!
        Adiciona um flow ao modelo
        \param flow flow a ser adicionado.
    */
    virtual void add(Flow* flow) = 0;

    /*!
        Remove um sistema do modelo
        \param sistema Sistema a ser removido. 
    */
    virtual void remove(System* sistema) = 0;
    /*!
        Remove um flow do modelo
        \param flow flow a ser removido.
    */
    virtual void remove(Flow* flow) = 0;
    
    typedef vector<System*>::iterator systemIterator;
    typedef vector<Flow*>::iterator flowIterator;
        
    virtual systemIterator beginSystems() = 0; /*!< Returns the iterator to the beginning of systems attribute. */
    virtual systemIterator endSystems() = 0; /*!< Returns the iterator to the end of systems attribute. */
    virtual flowIterator beginFlows() = 0; /*!< Returns the iterator to the beginning of flows attribute. */
    virtual flowIterator endFlows() = 0; /*!< Returns the iterator to the end of flows attribute. */ 

    /*!
        Cria um model e retorna o ponteiro do model.
        \param nome nome do model.
    */
    static Model* createModel(string nome="");

    /*!
        Cria um flow e retorna o ponteiro do flow.
        \param nome nome do flow.
        \param origem ponteiro para o sistema de origem.
        \param destino ponteiro para o sistema de destino.
    */

    template<typename TYPE>
    Flow* createFlow(string nome, System* origem=NULL, System* destino=NULL){
        Flow* flow = new TYPE(nome, origem, destino);
        add(flow);
        return flow;
    } 

    /*!
        Cria um sistema e retorna o ponteiro do sistema.
        \param nome nome do sistema.
        \param valorInicial ponteiro para o valor incial do sistema.
    */
    virtual System* createSystem(string name = "", double value = 0.0) = 0;

};

#endif
