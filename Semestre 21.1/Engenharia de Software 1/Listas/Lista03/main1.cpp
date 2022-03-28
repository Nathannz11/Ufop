#define EXERC1

#include <cstdlib>
#include <iostream>

using namespace std;
            
#if defined(EXERC1)
// QUESTÃO 1: Critique o código abaixo e aponte seus problemas com relação:
//          a) à flexibilidade da implementação: alterações em pequenos trechos 
//             do código não deveriam exigir recodificação de outras partes
//          b) à legibilidade do código: lendo o código é fácil entrender os 
//             objetos e processos que ele representa. Qual é seu objetivo?
class Casa {
      float orc;
      int a;
public:
       Casa( float o ):orc(o){ cout << "Casa criada..." << endl; }
       void setOrc( float o ) { orc = o; }
       float getOrc( void ) { return orc; }
};

#else
// QUESTAO 2: Corrija os problemas identificado na questão 1.
class Casa {
      // Coloque suas correções aqui...
};
// ...e aqui se necessário.
#endif

// QUESTAO 3: Explique o código abaixo e cada uma das linhas de texto que 
// formam sua saída.
int main(int argc, char *argv[])
{
    Casa c1(7), *c2 = &c1, &c3 = c1;
    
    cout << "C1: " << c1.getOrc() << endl;
    c1.setOrc(3);
    cout << "C2: " << c2->getOrc() << ", ";
    cout << "C3: " << c3.getOrc() << endl;
    cout << "C2: " << c2 << ", C3: " << &c3 << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
// QUESTAO 4: Quantas vezes o construtor da classe foi invocado? Por que?
