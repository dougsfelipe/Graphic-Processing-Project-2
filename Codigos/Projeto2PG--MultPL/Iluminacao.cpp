#include"PontoLuz.h"
#include"Functions.h"
#include <iostream>
#include <stdio.h>
#include "Iluminacao.h"
using namespace std;

bool Iluminacao::inicarIluminacao(Functions* funct)
{
    FILE* ilumin=fopen("multi_iluminacao.txt","rt");
    if(ilumin!=NULL)
    {
        this->funct=funct;
        float* aux=this->funct->GetRetorno();
        // carregando iluminação
        fscanf(ilumin,"%f",&this->ka);
        fscanf(ilumin,"%f",&this->Ia[0]);fscanf(ilumin,"%f",&this->Ia[1]);fscanf(ilumin,"%f",&this->Ia[2]);
        fscanf(ilumin,"%f",&this->kd);
        fscanf(ilumin,"%f",&this->Od[0]);fscanf(ilumin,"%f",&this->Od[1]);fscanf(ilumin,"%f",&this->Od[2]);
        fscanf(ilumin,"%f",&this->ks);
        fscanf(ilumin,"%d",&this->qtPontosluz);
        this->pontos=new PontoLuz[qtPontosluz];
        //

        //salvando todos os pontos de luz
        int i=0;
        for(i=0;i<this->qtPontosluz;i++)
        {
            float x,y,z,r,g,b;
            fscanf(ilumin,"%f",&x);fscanf(ilumin,"%f",&y);fscanf(ilumin,"%f",&z);
            fscanf(ilumin,"%f",&r);fscanf(ilumin,"%f",&g);fscanf(ilumin,"%f",&b);
            this->pontos[i].addPontoLuz(x,y,z,r,g,b);
            //calculando cordenadas de vista
            this->funct->calcCord_vista(this->pontos[i].getCordMundo());
            this->pontos[i].addCortdVista(aux);
            //
        }
        //

        fclose(ilumin);
        return true;
    }
    else
    {
        fclose(ilumin);
        return false;
    }
}
PontoLuz* Iluminacao:: getPontosLuz()
{
    return this->pontos;
}
int Iluminacao::  getQtpontosluz()
{
    return this->qtPontosluz;
}
float Iluminacao::  getKa()
{
    return this->ka;
}
float* Iluminacao::  getIa()
{
    return this->Ia;
}
float Iluminacao::  getKd()
{
    return this->kd;
}
float* Iluminacao::  getOd()
{
    return this->Od;
}
float Iluminacao::  getks()
{
    return this->ks;
}
