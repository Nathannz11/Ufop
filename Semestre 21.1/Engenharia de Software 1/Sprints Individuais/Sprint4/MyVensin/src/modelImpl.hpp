//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#ifndef MODELIMPL_HPP
#define MODELIMPL_HPP

#include "model.hpp"

using namespace std;

//! Class ModelImpl
/**
* Essa classe representa um modelo de sistema do código.
*/  
class ModelImpl : public Model{
    

    string nome; /*!< Esse atributo contem um nome para o modelo.*/
    vector<System*> sistemas; /*!< Esse atributo um vetor de ponteiros de sistemas do modelo.*/
    vector<Flow*> flows; /*!< Esse atributo um vetor de flows de sistemas do modelo.*/
    

    public:
    
    /*!
        Construtor mais elaborado para a classe ModelImpl.
        \param nome nome para o modelo
        \return Model - Um objeto da classe ModelImpl.
    */
    ModelImpl(string nome = "" );
    
    /*!
        Esse é o destrutor padrão da classe ModelImpl;
    */
    virtual ~ModelImpl();

    /*!
        Retorna o atributo nome do objeto da classe ModelImpl.
        \return string - o conteúdo de atributo nome.
    */
    string getNome() const ;
    /*!
        Seta o atributo nome do objeto da classe ModelImpl.
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
        
    virtual systemIterator beginSystems(); /*!< Returns the iterator to the beginning of systems attribute. */
    virtual systemIterator endSystems(); /*!< Returns the iterator to the end of systems attribute. */
    virtual flowIterator beginFlows(); /*!< Returns the iterator to the beginning of flows attribute. */
    virtual flowIterator endFlows(); /*!< Returns the iterator to the end of flows attribute. */

    private:
    /*!
        Cria um novo modelo com base em outro existente. Contrutor de cópia.
        \param model Modelo a ser copiado.
    */ 
    ModelImpl(const ModelImpl& model);

    /*!
        Sobrecarga do operador = para a classe ModelImpl.
        \param model Modelo a ser atribuido.
    */
    void operator=(const ModelImpl& model);
};

#endif
