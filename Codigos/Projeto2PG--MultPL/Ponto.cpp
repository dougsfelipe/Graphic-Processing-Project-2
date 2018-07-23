#include<iostream>
#include"Ponto.h"
#include <math.h>
#include <stdio.h>
#include "Functions.h"
using namespace std;

    void Ponto :: addPonto(float x,float y, float z)
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
    float* Ponto::GetPvista()
    {
        return this->PVista;
    }
    void Ponto::addPvista(float* v)
    {
        this->PVista[0]=*v;
        this->PVista[1]=*(v+1);
        this->PVista[2]=*(v+2);
        cout<<this->PVista[0]<<","<<this->PVista[1]<<","<<this->PVista[2]<<endl;
    }
    void Ponto::addTnormal(float x,float y,float z)
    {
        this->sTnomal[0]=this->sTnomal[0]+x;
        this->sTnomal[1]=this->sTnomal[1]+y;
        this->sTnomal[2]=this->sTnomal[2]+z;
        this->nTincidentes++;
        this->pnormal[0]=this->sTnomal[0]/this->nTincidentes;
        this->pnormal[1]=this->sTnomal[1]/this->nTincidentes;
        this->pnormal[2]=this->sTnomal[2]/this->nTincidentes;
    }
    void Ponto::normalizaNormal(Functions* funct)
    {
        float* aux=funct->GetRetorno();
        funct->calcNorma(this->pnormal);
        this->pnormal[0]=*(aux);this->pnormal[1]=*(aux+1);this->pnormal[2]=*(aux+2);
    }
void Ponto::addPontoTela(int x, int y)
{
    this->Ptela[0]=x;
    this->Ptela[1]=y;
}
int* Ponto::GetPtela()
{
    return this->Ptela;
}
