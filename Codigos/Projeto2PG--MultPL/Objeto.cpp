#include<iostream>
#include<stdio.h>
#include"Ponto.h"
#include"Triangulo.h"
#include"Objeto.h"
#include"Functions.h"
using namespace std;
bool Objeto::iniciarObj(Functions* funct)
{
    FILE* objeto=fopen("objeto.byu","rt");
    if(objeto!=NULL)
    {
        this->funct=funct;
        fscanf(objeto,"%d",&this->qtPontos);
        fscanf(objeto,"%d",&this->qtTriangulos);
        this->pontos=new Ponto[qtPontos];
        this->triangulos=new Triangulo[qtTriangulos];
        int i=0;
        ;

        for(i=0;i<qtPontos;i++)
        {
            float x,y,z;
            fscanf(objeto,"%f",&x);fscanf(objeto,"%f",&y);fscanf(objeto,"%f",&z);
            Ponto aux;
            aux.addPonto(x,y,z,out);
            this->pontos[i]=aux;
        }
       ;

        for(i=0;i<qtTriangulos;i++)
        {
            int p1,p2,p3;
            fscanf(objeto,"%d",&p1);fscanf(objeto,"%d",&p2);fscanf(objeto,"%d",&p3);
            Triangulo aux;
            aux.CriarTriangulo(&this->pontos[p1],&this->pontos[p2],&this->pontos[p3],out);
            this->triangulos[i]= aux;
            this->triangulos[i].normalizarTnormal(this->funct);

        }


        for(i=0;i<qtPontos;i++)
        {
            this->pontos[i]->normalizaNormal(this->funct);

        }
        return true;
    }
}
Ponto* Objeto::getPontos()
{
    return this->pontos;
}
Triangulo* Objeto::getTriangulos()
{
    return this->triangulos;
}

