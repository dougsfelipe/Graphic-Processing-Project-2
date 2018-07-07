#include "Triangulo.h"
#include "Ponto.h"
#include <iostream>

using namespace std;

void Triangulo::CriarTriangulo(Ponto* p1,Ponto* p2,Ponto* p3)
{
    this->pontos[0]=p1;this->pontos[1]=p2;this->pontos[2]=p3;

    float vetorp1p2[3];
    vetorp1p2[0]=*this->pontos[1]->GetPonto()-*this->pontos[0]->GetPonto();
    vetorp1p2[1]=*(this->pontos[1]->GetPonto()+1)-*(this->pontos[0]->GetPonto()+1);
    vetorp1p2[2]=*(this->pontos[1]->GetPonto()+2)-*(this->pontos[0]->GetPonto()+2);
    //cout<<"p1p2: "<<vetorp1p2[0]<<" "<< vetorp1p2[1]<<" "<<vetorp1p2[2]<<endl;

    float vetorp1p3[3];
    vetorp1p3[0]=*this->pontos[2]->GetPonto()-*this->pontos[0]->GetPonto();
    vetorp1p3[1]=*(this->pontos[2]->GetPonto()+1)-*(this->pontos[0]->GetPonto()+1);
    vetorp1p3[2]=*(this->pontos[2]->GetPonto()+2)-*(this->pontos[0]->GetPonto()+2);
    //cout<<"p1p3: "<<vetorp1p3[0]<<" "<< vetorp1p3[1]<<" "<<vetorp1p3[2]<<endl;

    this->tnormal[0]=(vetorp1p2[1]*vetorp1p3[2])-(vetorp1p2[2]*vetorp1p3[1]);
    this->tnormal[1]=(vetorp1p2[2]*vetorp1p3[0])-(vetorp1p2[0]*vetorp1p3[2]);
    this->tnormal[2]=(vetorp1p2[0]*vetorp1p3[1])-(vetorp1p2[1]*vetorp1p3[0]);
    this->pontos[0]->addTnormal(this->tnormal[0],this->tnormal[1],this->tnormal[2]);
    this->pontos[1]->addTnormal(this->tnormal[0],this->tnormal[1],this->tnormal[2]);
    this->pontos[2]->addTnormal(this->tnormal[0],this->tnormal[1],this->tnormal[2]);
}
Ponto* Triangulo::getPontos()
{
    return *this->pontos;
}
float* Triangulo::getTnormal()
{
    return this->tnormal;
}