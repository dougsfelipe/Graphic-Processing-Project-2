#ifndef ILUMINACAO_H_INCLUDED
#define ILUMINACAO_H_INCLUDED
#include"PontoLuz.h"
#include"Functions.h"
#include<stdio.h>
class Iluminacao
{
private:
    PontoLuz* pontos;
    int qtPontosluz;
    float ka;
    float Ia[3];
    float kd;
    float Od[3];
    float ks;
    Functions* funct;
public:
    bool inicarIluminacao(Functions* funct,FILE* out);
    PontoLuz* getPontosLuz();
    int getQtpontosluz();
    float getKa();
    float* getIa();
    float getKd();
    float* getOd();
    float getks();
};


#endif // ILUMINACAO_H_INCLUDED
