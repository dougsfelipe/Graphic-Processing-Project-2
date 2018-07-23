#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED
#include <stdio.h>
#include "Functions.h"
class Ponto
{
private:
    float ponto[3];
    float pnormal[3];
    float sTnomal[3];
    float PVista [3];
    int Ptela [2];
    int nTincidentes;
public:
    void addPonto(float x,float y,float z);
    float* GetPonto();
    float* GetPnormal();
    float* GetPvista();
    void addTnormal(float x,float y,float z);
    void addPvista(float* v);
    void normalizaNormal(Functions* funct);
    void addPontoTela(int x, int y);
    int* GetPtela();
};
#endif // PONTO_H_INCLUDED
