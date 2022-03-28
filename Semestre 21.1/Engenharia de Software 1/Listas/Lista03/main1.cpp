#define EXERC1

#include <cstdlib>
#include <iostream>

using namespace std;
            
#if defined(EXERC1)
// QUEST�O 1: Critique o c�digo abaixo e aponte seus problemas com rela��o:
//          a) � flexibilidade da implementa��o: altera��es em pequenos trechos 
//             do c�digo n�o deveriam exigir recodifica��o de outras partes
//          b) � legibilidade do c�digo: lendo o c�digo � f�cil entrender os 
//             objetos e processos que ele representa. Qual � seu objetivo?
class Casa {
      float orc;
      int a;
public:
       Casa( float o ):orc(o){ cout << "Casa criada..." << endl; }
       void setOrc( float o ) { orc = o; }
       float getOrc( void ) { return orc; }
};

#else
// QUESTAO 2: Corrija os problemas identificado na quest�o 1.
class Casa {
      // Coloque suas corre��es aqui...
};
// ...e aqui se necess�rio.
#endif

// QUESTAO 3: Explique o c�digo abaixo e cada uma das linhas de texto que 
// formam sua sa�da.
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
