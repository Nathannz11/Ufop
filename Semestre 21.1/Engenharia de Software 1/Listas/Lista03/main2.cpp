#include <cstdlib>
#include <iostream>

using namespace std;
            
// QUEST�O 1: O c�digo desse exerc�cio � id�ntico ao do exerc�cio anterior. 
//          Por�m o operador "<<" foi sobrecarregado para permitir que 
//          programador implemente de maneira mais f�cil a sa�da do programa.
//          Desta maneira, o codigo a seguir pode ser utilizado para imprimir
//          na tela um objeto "Casa": Casa c1; cout << c1; 
//
//          a) Explique porque o m�todo que sobrecarrega o operador "<<" precisou
//          ser declarado como amigo ("friend") da classe Casa? 
//          b) Explique o funcionamento do novo operador "<<".
class Casa {
      float orc;
public:
		// Casa( float o ):orc(o){ printf("Casa criada..."); }
       Casa( float o ):orc(o){ cout << "Casa criada..." << endl; }
       void setOrc( float o ) { orc = o; }
       float getOrc( void ) { return orc; }
       friend ostream& operator<<( ostream& s, Casa& c) {  s << c.orc; return s; }
};

// QUEST�O 2: Explique o c�digo abaixo e cada uma das linhas de texto que 
// formam sua sa�da.
int main(int argc, char *argv[])
{
    Casa c1(7), &c2 = c1;
    
    cout << "C1: " << c1.getOrc() << ", C2: " << c2.getOrc() << endl;
    c2.setOrc(3);
    cout << "C1: " << c1 << ", C2: " << c2 << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}

