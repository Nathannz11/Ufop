//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#ifndef MODELIMPL_HPP
#define MODELIMPL_HPP

#include "model.hpp"
#include "handleBodySemDebug.h"

class SystemImpl;
class FlowImpl;


using namespace std;

//! Class ModelBody
/**
* Essa classe representa um modelo de sistema do código.
*/  
class ModelBody : public Body{
    

    string nome; /*!< Esse atributo contem um nome para o modelo.*/
    vector<System*> sistemas; /*!< Esse atributo um vetor de ponteiros de sistemas do modelo.*/
    vector<Flow*> flows; /*!< Esse atributo um vetor de flows de sistemas do modelo.*/
    static vector<Model *> models;

    private:

    /*!
        Cria um novo modelo com base em outro existente. Contrutor de cópia.
        \param model Modelo a ser copiado.
    */ 
    ModelBody(const ModelBody& model);

    /*!
        Sobrecarga do operador = para a classe ModelBody.
        \param model Modelo a ser atribuido.
    */
    void operator=(const ModelBody& model);

    public:
    
    /*!
        Construtor mais elaborado para a classe ModelBody.
        \param nome nome para o modelo
        \return Model - Um objeto da classe ModelBody.
    */
    ModelBody(string nome = "" );
    
    /*!
        Esse é o destrutor padrão da classe ModelBody;
    */
    virtual ~ModelBody();

    /*!
        Retorna o atributo nome do objeto da classe ModelBody.
        \return string - o conteúdo de atributo nome.
    */
    string getNome() const ;
    /*!
        Seta o atributo nome do objeto da classe ModelBody.
        \param nome que será setado ao Modelo atual.
    */
    void setNome(string nome);

    /*!
        Responsável por executar o sistema de acordo com o tipo de flow contido (variando a equacao).
        \param inicio o tempo inicial.
        \param fim o tempo final.    
    */    
    void run(double inicio = 0.0, double fim = 0.0);
    
    /*!
        Adiciona um sistema ao modelo
        \param system sistema a ser adicionado.
    */
    void add(System* system);

    /*!
        Adiciona um flow ao modelo
        \param flow flow a ser adicionado.
    */
    void add(Flow* flow);

    /*!
        Remove um sistema do modelo
        \param sistema Sistema a ser removido. 
    */
    void remove(System* sistema);
    /*!
        Remove um flow do modelo
        \param flow flow a ser removido.
    */
    void remove(Flow* flow);

    typedef vector<System*>::iterator systemIterator;
    typedef vector<Flow*>::iterator flowIterator;
        
    systemIterator beginSystems(); /*!< Returns the iterator to the beginning of systems attribute. */
    systemIterator endSystems(); /*!< Returns the iterator to the end of systems attribute. */
    flowIterator beginFlows(); /*!< Returns the iterator to the beginning of flows attribute. */
    flowIterator endFlows(); /*!< Returns the iterator to the end of flows attribute. */

    /*!
        Cria um model e retorna o ponteiro do model.
        \param nome nome do model.
    */
    static Model* createModel(string nome);

    /*!
        Cria um sistema e retorna o ponteiro do sistema.
        \param nome nome do sistema.
        \param valorInicial ponteiro para o valor incial do sistema.
    */
    System* createSystem(string nome, double valorInicial);


};

//! Class ModelHandle
/**
* Essa classe representa um modelo de sistema do código.
*/  
class ModelHandle : public Handle<ModelBody>, public Model{

    public:
    
    /*!
        Construtor mais elaborado para a classe ModelHandle.
        \param nome nome para o modelo
        \return Model - Um objeto da classe ModelHandle.
    */
    ModelHandle(string nome = "" ){
        pImpl_->setNome(nome);
    }
    
    /*!
        Esse é o destrutor padrão da classe ModelHandle;
    */
    virtual ~ModelHandle(){};

    /*!
        Retorna o atributo nome do objeto da classe ModelHandle.
        \return string - o conteúdo de atributo nome.
    */
    string getNome() const{
        return pImpl_->getNome();
    }
    /*!
        Seta o atributo nome do objeto da classe ModelHandle.
        \param nome que será setado ao Modelo atual.
    */
    void setNome(string nome){
        pImpl_->setNome(nome);
    }

    /*!
        Responsável por executar o sistema de acordo com o tipo de flow contido (variando a equacao).
        \param inicio o tempo inicial.
        \param fim o tempo final.    
    */    
    void run(double inicio = 0.0, double fim = 0.0){
        pImpl_->run(inicio, fim);
    }
    
    /*!
        Adiciona um sistema ao modelo
        \param system sistema a ser adicionado.
    */
    void add(System* system){
        pImpl_->add(system);
    }

    /*!
        Adiciona um flow ao modelo
        \param flow flow a ser adicionado.
    */
    void add(Flow* flow){
        pImpl_->add(flow);
    }

    /*!
        Remove um sistema do modelo
        \param sistema Sistema a ser removido. 
    */
    void remove(System* sistema){
        pImpl_->remove(sistema);
    }
    /*!
        Remove um flow do modelo
        \param flow flow a ser removido.
    */
    void remove(Flow* flow){
        pImpl_->remove(flow);
    }

    typedef vector<System*>::iterator systemIterator;
    typedef vector<Flow*>::iterator flowIterator;
        
    virtual systemIterator beginSystems(){return pImpl_->beginSystems();} /*!< Returns the iterator to the beginning of systems attribute. */
    virtual systemIterator endSystems(){return pImpl_->endSystems();} /*!< Returns the iterator to the end of systems attribute. */
    virtual flowIterator beginFlows(){return pImpl_->beginFlows();} /*!< Returns the iterator to the beginning of flows attribute. */
    virtual flowIterator endFlows(){return pImpl_->endFlows();} /*!< Returns the iterator to the end of flows attribute. */

    /*!
        Cria um model e retorna o ponteiro do model.
        \param nome nome do model.
    */
    static Model* createModel(string nome){
        return ModelBody::createModel(nome);
    }

    /*!
        Cria um sistema e retorna o ponteiro do sistema.
        \param nome nome do sistema.
        \param valorInicial ponteiro para o valor incial do sistema.
    */
    System* createSystem(string nome, double valorInicial){
        return pImpl_->createSystem(nome, valorInicial);
    }
};
#endif
