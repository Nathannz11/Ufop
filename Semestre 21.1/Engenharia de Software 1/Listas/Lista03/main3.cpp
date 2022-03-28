// Sistema: Gerenciamento de Concessionaria de Automoveis - AutoMananger
// Modulo: Principal
// Autor: Tiago Garcia de Senna Carneiro
// Ultima alteracao:15/12/2006
// Responsavel: Tiago G. S. Carneiro
//
// Descrição: Este eh o modulo principal do sistema para gerenciamento 
// de uma agencia de automoveis: motos, caminhoes e veículos de passeio. Ele
// mantem o cadastro de automoveis a venda, a lista de cliente com os quais a 
// concessionaria se relaciona, e a lista de funcionarios da empresa, e uma 
// lista de carros que estão na oficina com o nome do funcinário que reponsável 
// pelo conserto. Motos nunca sao enviadas para oficina, pois os mecanicos só 
// consertam carros. Uma nova funcionalidade foi implementada para o 
// departamento de marketing, os veiculos na concessionaria sao classificados
// automaticamente classificados em veiculos de duas ou quatro rodas.
//
// Serviços (API): 
//           - Gerencia cadastro de veiculos e funcionarios (RUIM: Realiza a entrada e saída de dados)
//           - Calcula o reajuste de salarial para todos os funcionarios.
//           - Imprime a lista de carros com o nome do funcionario
//           responsavel pelo conserto.
//           - Lista de veiculos classificados pelo numero de rodas.
//
// Requisitos:
//           - Nenhuma informação deve ser persistida.
//           - Fornecer a qualquer momento o numero de automoveis carregados 
//           na memoria.

#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

#include "veiculo.h"            
#include "cliente.h"
#include "funcionario.h"

// QUESTAO 1: A funcao abaixo cria nomes com base em um prefixo escolhido pelo
// pelo programador. Por exemplo, para o parametro "Cliente" ela cria os nomes:
// Cliente0, Cliente1, Cliente2,...
// Responda:
//          (a) Por que a variavel "cont" foi declarada static?
//          (b) Por que "sufixo" nao foi declarado como "char*" ao invez de 
//              "char[15]"? Tente fazer essa alteração, recompliar e executar
//              o codigo para entender o porque.
//          (c) Por que e somado 1(uma) unidade ao tamanho do nome?
//          (d) Qual a vantagem obtida ao se declarar a variavel "cont" local
//              a rotina "criaNome" ao invez de declara-la global ao modulo?
//          (e) Porque é necessário alocar memoria para variavel 
//              "str" através do operador "new"? Altere codigo para "char *str", 
//              e deixe de alocar memoria. Então, execute o programa e veja o 
//              que acontece. 
char* criaNome( const char *prefixo )
{
      static unsigned int cont = 0;
        
      // converte inteiro (int) para string (array) utilizando a base 10
      // e cria o sufixo do nome
      char sufixo[15];
      itoa(cont, sufixo, 10); 
      
      // calcula o tamanho do novo nome a partir dos tamanhos do prefixo e do 
      // sufixo 
      int size = strlen(prefixo) + strlen(sufixo) + 1;
      
      // incrementa gerador de sulfixo
      cont++;
      
      // char* str;
      char* str = new char[size]; 
      strcpy( str , prefixo ); // copia a segunda string para a primeira
      strcat( str , sufixo );  // anexa a segunda sring a primeira
      return  str;
      
}

#define MAIN_2
#if defined(  MAIN_1 )

// QUESTAO 2:  Antes de executar o codigo abaixo, pressione "ctrl+alt+del" e 
// ative o painel "desempenho" do gerenciador de tarefas do Windows. Execute o 
// o codigo e observe o consumo de memória registrado pelo sistema operacional.
// Explique porque a demanda por memória aumenta sempre que seu programa é 
// executado. Altere a classe "Cliente" para corrigir essa falha na 
// sua implementacao.
// Obs: Não se esqueça de recompilar todo o código para que sua correção tenha
// efeito.
unsigned int Veiculo::cont = 0;
int main(int argc, char *argv[])
{
    char* const PREFIXO = "Dr. Fulano";
    cout << "espere..." << endl;
    for( unsigned int i = 0; i < 10000; i++ ){
         for( unsigned int j = 0; j < 10000; j++ ){
              Cliente cli1("Dra. Beltrana"), cli2(criaNome(PREFIXO)), cli3(criaNome(PREFIXO));
			  
         }
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}

#elif defined( MAIN_2 )
// QUESTAO 3: Para resolver esta questao, antes, vc devera resolver a QUESTAO 2. 
// Antes de executar o codigo abaixo, pressione "ctrl+alt+del" e ative o painel 
// "desempenho" do gerenciador de tarefas do Windows. Então, execute o codigo e 
// observe que o erro de consumo indevido de memoria retournou. Entretanto,
// sua causa agora é outra. Ou então aconteceu o pior, seu programa está 
// abortando e não funciona mais devio ao erro gerado pela linha "cli1 = cli2".
// Comente esta linha e então observe o resultado do progrma. Explique a
// saída do programa e a causa do erro? Sobrecarregue o opeador "=" da classe 
// "Cliente" e corrija o problema.
// Garanta que sua correção passe sem problemas pelo codigo: "cli1 = cli1", onde
// um objeto "Cliente" é atribuido a ele mesmo.
unsigned int Veiculo::cont = 0;
int main(int argc, char *argv[])
{
    char* const PREFIXO = "Dr. Fulano";
  
    cout << "espere..." << endl;
    for( unsigned int i = 0; i < 100000; i++ ){
         for( unsigned int j = 0; j < 100; j++ ){
              Cliente cli1(criaNome(PREFIXO)), cli2(criaNome(PREFIXO)), cli3(criaNome(PREFIXO));
              cli1 = cli2;   // linha que esta gerando erro       
        }
    }
    system("PAUSE");
    
    Cliente cli1("Dra. Beltrana"), cli2(criaNome(PREFIXO)), cli3(criaNome(PREFIXO));
    cout << "Antes  -- Clientes: " << cli1.getNome() <<", "<< cli2.getNome();
    cout << ", "  << cli3.getNome() << endl;
    cout << "Antes  -- Clientes: " << (void*)cli1.getNome() <<", "<< (void*)cli2.getNome();
    cout << ", "  << (void*)cli3.getNome() << endl;
    cout << endl << endl;
    cli2 = cli1;
    cout << "Depois -- Clientes: " << cli1.getNome() <<", "<< cli2.getNome();  
    cout << ", "  << cli3.getNome() << endl;
    cout << "Depois -- Clientes: " << (void*)cli1.getNome() <<", "<< (void*)cli2.getNome();
    cout << ", "  << (void*)cli3.getNome() << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

#elif defined( MAIN_3 )

// QUESTAO 4: Ao invez de declararmos uma variável global para mantermos a 
// contagem do numero de objetos da classe "Veiculo" carregados na memória, 
// decidimos declarar a varíável "cont" na própria classe "Veiculo". Qual é
// a vantagem dessa abordagem? Por que essa variavel precisa ser declarada como
// "static" para que nosso codigo funcione? Experimente tirar o qualificador 
// "static" e executar a nova versão do codigo para entender, por completo,
// seu funcionamento. Ao retirar o qualificador "static" da variavel, vc 
// percebera que os metodos que fazem acesso a variavel "cont" tambem precisarao 
// deixar de ser "static".

// QUESTAO 5: Por que o metodo "getCont()" pode ser invocado por meio do nome
// da classe, "Veiculo::getCont()", e não é preciso um objeto para invoca-lo?
unsigned int Veiculo::cont = 0;
int main(int argc, char *argv[])
{
   
    Carro car1(10.0f), &car2 = car1;
    Caminhao cam1(100);

    cout << "Antes - Numero de veículos na memoria: " << car1.getCont() << endl;
    Carro car3(100);
    cout << "Depois - Numero de veículos na memoria: " << Veiculo::getCont() << endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

#elif defined( MAIN_4)

// QUESTAO 6: Na classe "Funcionario" o metodo "reajustaSalario" foi declarado
// como um metodo "virtual". Observe o codigo abaixo e explique o por que. Para
// entender melhor o funcionamento desse codigo, retire o qualificador "virtual"
// do metodo "reajustaSalario", execute o programa novamente e observe sua 
// saída.
unsigned int Veiculo::cont = 0;
int main(int argc, char *argv[])
{

    Funcionario* funcs[5]; 
    String r = "Ciclano";
    
    // alloca memoria para o cadastro de funcionarios, perceba que cada item
    // do cadastro é um tipo diferente de funcionario
    funcs[0] = new Mecanico(10.0f, r ); 
    funcs[1] = new Mecanico(10.0f, r );
    funcs[2] = new GerenteGeral(10.0f, r);
    funcs[3] = new Gerente(10.0f, r);
    funcs[4] = new Gerente(10.0f, r);
    
    for(int i = 0; i < 5; i++ ) {
            cout << "Funcionario[" << i << "]: " << funcs[i]->getSalario() << endl;
    }
    cout << endl << endl;
    for(int i = 0; i < 5; i++ ) {
            funcs[i]->reajustaSalario();
    }
    cout << endl << endl;
    for(int i = 0; i < 5; i++ ) {
            cout << "Funcionario[" << i << "]: " << funcs[i]->getSalario() << endl;
    }
   
    // libera a memoria ocupada pelo cadastro de funcionarios
    delete [] funcs;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

#elif defined( MAIN_5)
// QUESTAO 7: O codigo a seguir faz a listagem dos carros da concessionaria
// classificando-os como "biciclo" ou "quadriciclo". Repare que a constante
// "classe" que armazena a classificacao do veiculo, não foi declarada na classe
// "Veiculo", pois nao se sabe a essa altura se o objeto a ser instanciado tera
// 2(duas) ou 4(quatro) rodas. Desta maneira, somente a classe "Moto" e 
// "Automovel" possuiem a constante "classe" para a classificacao automatica do
// veiculo instaciado. Entretanto, e desejavel que se possa invocar o metodo 
// "getClasse()" a partir de objetos do tipo "Veiculo". Por esse motivo, a 
// classe "Veiculo" tambem possui esse método na  sua interface. Responda os 
// seguintes itens:
// (a) Tente declarar um objeto da classe "Veiculo" e explique por que nao 
//     foi possivel.
// (b) O metodo "Veiculo::getClasse()" foi declarado como um metodo "puramente
//     virtual". Por que?
// (c) O valor de retorno do metodo "Veiculo::getClasse()" foi declarado duas 
//     vezes como constante. Por que?
unsigned int Veiculo::cont = 0;
int main(int argc, char *argv[])
{

    Veiculo* veiculos[5];
        
    
    // alloca memoria para o cadastro de funcionarios, perceba que cada item
    // do cadastro é um tipo diferente de funcionario
    veiculos[0] = new Moto(10.0f); 
    veiculos[1] = new Moto(10.0f);
    veiculos[2] = new Caminhao(10.0f);
    veiculos[3] = new Carro(10.0f);
    veiculos[4] = new Moto(10.0f);
    
    for(int i = 0; i < 5; i++ ) {
            cout << "Veiculos[" << i << "]: " << veiculos[i]->getClasse() << endl;
    }
 
    // libera a memoria ocupada pelo cadastro de funcionarios
    delete [] veiculos;

    system("PAUSE");
    return EXIT_SUCCESS;
}

#elif defined( MAIN_6)
// QUESTAO 8: No codigo a seguir, a constante "MOTO" possui o tipo "Moto", assim
// como a variavel "moto". 
// Explique por que é possivel invocar o metodo "getClasse()" por meio  
// variavel e não e possivel invoca-lo atraves da constante. Corrija a definicao
// do metodo "getClasse()" para que seja possivel invoca-lo tanto por meio de 
// uma variavel quanto de uma constante.
           
unsigned int Veiculo::cont = 0;
int main(int argc, char *argv[])
{

    Moto moto(10);
    const Moto MOTO(10);
        
    cout << "Classe da moto: " << moto.getClasse() << endl;
    
    // Retire o comentario da linha a seguir para testar seu fucionamento
    //cout << "Classe da MOTO: " << MOTO.getClasse() << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
#endif
