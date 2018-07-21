#include<iostream>
#include"Functions.h"
#include<math.h>
using namespace std;

void Functions::setAlpha(float* U,float* V,float* N,float* C)
{
    this->U=U;this->V=V;this->N=N;this->C=C;//guardando os ponteiro de alpha
}
float Functions::calcNorma(float* vetor)
{
    return sqrt(pow(*(vetor),2)+pow(*(vetor+1),2)+pow(*(vetor+2),2));
}
void Functions::normalizar(float* vetor)
{
    float n=this->calcNorma(vetor);
    this->retorno[0]=*vetor/n;
    this->retorno[1]=*(vetor+1)/n;
    this->retorno[2]=*(vetor+2)/n;
}
void Functions::calcProj(float* N,float* V)
{
    float n=(*N)*(*V)+*(N+1)**(V+1)+*(N+2)**(V+2);
    this->retorno[0]=(*V)*n;this->retorno[1]=(*(V+1))*n;this->retorno[2]=(*(V+2))*n;

}
void Functions::calcOrtogonal(float* N,float* V)
{
    this->calcProj(N,V);
    this->retorno[0]=(*V)-(this->retorno[0]);
    this->retorno[1]=(*(V+1))-(this->retorno[1]);
    this->retorno[2]=(*(V+2))-(this->retorno[2]);

}

void Functions::calcVetorProdVet(float* v1,float *v2)
{

    this->retorno[0]=((*(v1+1))*(*(v2+2)))-((*(v1+2))*(*(v2+1)));
    this->retorno[1]=((*(v1+2))*(*(v2)))-((*(v1))*(*(v2+2)));
    this->retorno[2]=((*(v1))*(*(v2+1)))-((*(v1+1))*(*(v2)));

}

void Functions::calcCord_vista(float *v)
{
    this->retorno[0]=this->U[0]*((*(v))-this->C[0])+this->U[1]*((*(v+1))-this->C[1])+this->U[2]*((*(v+2))-this->C[2]);
    this->retorno[1]=this->V[0]*((*(v))-this->C[0])+this->V[1]*((*(v+1))-this->C[1])+this->V[2]*((*(v+2))-this->C[2]);
    this->retorno[2]=this->N[0]*((*(v))-this->C[0])+this->N[1]*((*(v+1))-this->C[1])+this->N[2]*((*(v+2))-this->C[2]);

}

float* Functions::GetRetorno()
{
    return this->retorno;
}
