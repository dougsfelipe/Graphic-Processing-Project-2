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
            aux.addPonto(x,y,z);
            this->pontos[i]=aux;
        }
       ;

        for(i=0;i<qtTriangulos;i++)
        {
            int p1,p2,p3;
            fscanf(objeto,"%d",&p1);fscanf(objeto,"%d",&p2);fscanf(objeto,"%d",&p3);
            Triangulo aux;
            aux.CriarTriangulo(&this->pontos[p1],&this->pontos[p2],&this->pontos[p3]);
            this->triangulos[i]= aux;
            this->triangulos[i].normalizarTnormal(this->funct);

        }


        for(i=0;i<qtPontos;i++)
        {
            this->pontos[i].normalizaNormal(this->funct);

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

void Objeto::printNormalPontos(FILE* out)
{
    int i=0;
    float* aux;
    for(i=0;i<this->qtPontos;i++){
        aux=this->pontos[i].GetPonto();
        fprintf(out,"%d: (%f,%f,%f) -> ",i,*aux,*(aux+1),*(aux+2));
        aux=this->pontos[i].GetPnormal();
        fprintf(out,"(%f,%f,%f)\n",*aux,*(aux+1),*(aux+2));
    }
}
void Objeto::printNormalTriangulos(FILE* out)
{
    int i=0;
    float* aux;
    for(i=0;i<this->qtTriangulos;i++)
    {
        aux=this->triangulos[i].getTnormal();
        fprintf(out,"%d: (%f,%f,%f)\n",i,*aux,*(aux+1),*(aux+2));
    }
}
