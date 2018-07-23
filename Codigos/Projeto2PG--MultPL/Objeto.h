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
    bool iniciarObj(Functions* funct);
    Ponto* getPontos();
    Triangulo* getTriangulos();
    void setCordsVista(float* U,float* V, float* N,float* C);
    void printNormalPontos(FILE* out);
    void printNormalTriangulos(FILE* out);
    void calPtela(float d, float hx, float hy,int width,int height);
    int getQtriangulos();
    int getQpontos();
};


#endif // OBJETO_H_INCLUDED
