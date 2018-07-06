#include<iostream>
#include"Ponto.h"
using namespace std;

    void Ponto::addPonto(float x,float y, float z)
    {
        this.ponto[0]=x;this.ponto[1]=y;this.ponto[2]=z;
        float n=sqrt(pow(this.ponto[0],2)+pow(this.ponto[1],2)+pow(this.ponto[3],2));
    }

    float Ponto::GetPonto()
    {
        return this.ponto;
    }
    float Ponto::GetPnormal()
    {
        return this.Pnormal;
    }
