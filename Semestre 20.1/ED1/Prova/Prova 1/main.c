typedef struct {
    int x;
    int y;
}TPonto;

typedef struct 
{
    TPonto p1;
    TPonto p2;
    TPonto p3;
    TPonto p4;
}TRetangulo;







TRetangulo* criarRetangulo(Tponto p1, Tponto p2, Tponto p3, Tponto p4){
    TRetangulo* aux = (TRetangulo*) malloc (sizeof(TRetangulo));
    aux->p1 = p1;
    aux->p2 = p2;
    aux->p3 = p3;
    aux->p4 = p4;
    return aux;
}

int checaPonto(TRetangulo* retangulo, TPonto ponto){
    if(ponto.x >= retangulo->p1.x && ponto.y <= retangulo->p1.y){
        if(ponto.x <= retangulo->p2.x && ponto.y <= retangulo->p2.y){
            if(ponto.x >= retangulo->p3.x && ponto.y >= retangulo->p3.y){
                if(ponto.x <= retangulo->p4.x && ponto.y >= retangulo->p4.y)
                    return 1;
            }
        }
    }
    return 0;
}
//0 1 2 3
//[1 2 3 4]
//1
int checaPontoComNRetangulos(TRetangulo** retangulos, int nroRetangulos, TPonto ponto){
    if(!(nroRetangulos - 1))
        return checaPonto(retangulos[nroRetangulos-1], ponto);
    if(checaPonto(retangulos[nroRetangulos-1, ponto])
        return checaPontoComNRetangulos(retangulos, nroRetangulos-1, ponto);
    return 0;
}







