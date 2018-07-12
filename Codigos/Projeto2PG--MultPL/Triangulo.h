#ifndef TRIANGULO_H_INCLUDED
#define TRIANGULO_H_INCLUDED
#include "Ponto.h"
#include "Functions.h"
#include<stdio.h>
class Triangulo
{
private:
    Ponto* pontos[3];
    float tnormal[3];
public:
    void CriarTriangulo(Ponto* p1,Ponto* p2, Ponto* p3);
    Ponto* getPontos();
    float* getTnormal();
    void normalizarTnormal(Functions* funct);
};


#endif // TRIANGULO_H_INCLUDED
