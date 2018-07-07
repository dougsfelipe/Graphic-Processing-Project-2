#include<iostream>
#include"Ponto.h"
#include <math.h>
using namespace std;

    void Ponto::addPonto(float x,float y, float z)
    {
        this->ponto[0]=x;this->ponto[1]=y;this->ponto[2]=z;
        this->pnormal[0]=0;this->pnormal[1]=0;this->pnormal[2]=0;
        this->sTnomal[0]=0;this->sTnomal[1]=0;this->sTnomal[2]=0;
        this->nTincidentes=0;
    }

    float* Ponto::GetPonto()
    {
        return this->ponto;
    }
    float* Ponto::GetPnormal()
    {
        return this->pnormal;
    }
    void Ponto::addTnormal(float x,float y,float z)
    {
        this->sTnomal[0]=this->sTnomal[0]+x;
        this->sTnomal[1]=this->sTnomal[1]+y;
        this->sTnomal[2]=this->sTnomal[2]+z;
        this->nTincidentes++;
        this->pnormal[0]=sTnomal[0]/this->nTincidentes;
        this->pnormal[1]=sTnomal[1]/this->nTincidentes;
        this->pnormal[2]=sTnomal[2]/this->nTincidentes;
    }
