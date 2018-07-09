#include<iostream>
#include"Functions.h"
#include<math.h>
using namespace std;

void Functions::setAlpha(float* U,float* V,float* N,float* C)
{
    this->U=U;this->V=V;this->N=N;this->C=C;
}
float Functions::calcNorma(float* vetor)
{
    return sqrt(pow(*(vetor),2)+pow(*(vetor+1),2)+pow(*(vetor+2),2));
}
void Functions::normalizar(float* vetor)
{
    float n=this->calcNorma(vetor);
    *vetor=*vetor/n;
    *(vetor+1)=*(vetor+1)/n;
    *(vetor+2)=*(vetor+2)/n;
}
float* Functions::calcProj(float* N,float* V)
{
    float n=(*N)*(*V)+*(N+1)**(V+1)+*(N+2)**(V+2);
    this->retorno[0]=(*V)*n;this->retorno[1]=(*(V+1))*n;this->retorno[2]=(*(V+2))*n;
    return this->retorno;
}
float* Functions::calcOrtogonal(float* N,float* V)
{
    float* proj=this->calcProj(N,V);
    this->retorno[0]=(*V)-(this->retorno[0]);
    this->retorno[1]=(*(V+1))-(this->retorno[1]);
    this->retorno[2]=(*(V+2))-(this->retorno[2]);
    return this->retorno;
}

float* Functions::calcVetorProdVet(float* v1,float *v2)
{

    this->retorno[0]=((*(v1+1))*(*(v2+2)))-((*(v1+2))*(*(v2+1)));
    this->retorno[1]=((*(v1+2))*(*(v2)))-((*(v1))*(*(v2+2)));
    this->retorno[2]=((*(v1))*(*(v2+1)))-((*(v1+1))*(*(v2)));
    return this->retorno;
}

float* Functions::calcCord_vista(float*v)
{
    this->retorno[0]=this->U[0]*((*(v))-this->C[1])+this->U[1]*((*(v+1))-this->C[1])+this->U[2]*((*(v+2))-this->C[2]);
    this->retorno[1]=this->V[0]*((*(v))-this->C[1])+this->V[1]*((*(v+1))-this->C[1])+this->V[2]*((*(v+2))-this->C[2]);
    this->retorno[2]=this->N[0]*((*(v))-this->C[1])+this->N[1]*((*(v+1))-this->C[1])+this->N[2]*((*(v+2))-this->C[2]);
    return this->retorno;
}
float* Functions::CorProdutoComponenteComponente(float* cor1,float* cor2)
{
    this->retorno[0]=(*cor1)*(*cor2);
    this->retorno[1]=(*(cor1+1))*(*(cor2+1));
    this->retorno[2]=(*(cor1+2))*(*(cor2+2));
    if(this->retorno[0]>255)this->retorno[0]=255;
    if(this->retorno[1]>255)this->retorno[1]=255;
    if(this->retorno[2]>255)this->retorno[2]=255;
    return this->retorno;
}

float* Functions::CorProdutoComponenteConstante(float* cor,float k)
{
    this->retorno[0]=(*cor)*k;
    this->retorno[1]=(*(cor+1))*k;
    this->retorno[2]=(*(cor+2))*k;
    if(this->retorno[0]>255)this->retorno[0]=255;
    if(this->retorno[1]>255)this->retorno[1]=255;
    if(this->retorno[2]>255)this->retorno[2]=255;
    return this->retorno;
}
