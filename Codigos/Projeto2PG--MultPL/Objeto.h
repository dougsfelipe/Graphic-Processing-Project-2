#ifndef OBJETO_H_INCLUDED
#define OBJETO_H_INCLUDED
#include "Ponto.h"
#include "Triangulo.h"
#include "Functions.h"
#include <stdio.h>
class Objeto
{
private:
    Ponto* pontos;
    Triangulo* triangulos;
    int qtPontos;
    int qtTriangulos;
    Functions* funct;
public:
    bool iniciarObj(Functions* funct,FILE* out);
    Ponto* getPontos();
    Triangulo* getTriangulos();
    void setCordsVista(float* U,float* V, float* N,float* C);
};


#endif // OBJETO_H_INCLUDED
