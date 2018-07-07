#ifndef TRIANGULO_H_INCLUDED
#define TRIANGULO_H_INCLUDED
#include "Ponto.h"
class Triangulo
{
private:
    Ponto* pontos[3];
    float tnormal[3] ;
public:
    void CriarTriangulo(Ponto* p1,Ponto* p2, Ponto* p3);
    Ponto* getPontos();
    float* getTnormal();
};


#endif // TRIANGULO_H_INCLUDED
