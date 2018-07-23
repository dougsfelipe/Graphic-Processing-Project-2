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

        this->pontos=new Ponto[this->qtPontos];
        this->triangulos=new Triangulo[this->qtTriangulos];
        int i=0;
        float * auxilio=this->funct->GetRetorno();

        for(i=0;i<this->qtPontos;i++)
        {
            float x,y,z;
            fscanf(objeto,"%f",&x);fscanf(objeto,"%f",&y);fscanf(objeto,"%f",&z);
            Ponto aux;
            aux.addPonto(x,y,z);
            this->pontos[i]=aux;
            this->funct->calcCord_vista(this->pontos[i].GetPonto());
            this->pontos[i].addPvista(auxilio);

        }


        for(i=0;i<this->qtTriangulos;i++)
        {
            int p1,p2,p3;
            fscanf(objeto,"%d",&p1);fscanf(objeto,"%d",&p2);fscanf(objeto,"%d",&p3);
            Triangulo aux;

            aux.CriarTriangulo(&this->pontos[p1-1],&this->pontos[p2-1],&this->pontos[p3-1]);
            this->triangulos[i]= aux;
            Ponto** x1= this->triangulos[i].getPontos();
            this->triangulos[i].normalizarTnormal(this->funct);

        }


        for(i=0;i<this->qtPontos;i++)
        {
            //this->pontos[i].normalizaNormal(this->funct);

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
        fprintf(out,"(%f,%f,%f) -> ",*aux,*(aux+1),*(aux+2));
        aux=this->pontos[i].GetPvista();
        fprintf(out,"(%f,%f,%f) -> ",*aux,*(aux+1),*(aux+2));
        int* aux1=this->pontos[i].GetPtela();
        fprintf(out,"(%d,%d)\n",*aux1,*(aux1+1));
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
void Objeto::calPtela(float d,float hx, float hy,int width,int height)
{
    float x1=0;
    float y1=0;
    float x2=0;
    float y2=0;
    int x=0;
    int y=0;
    for(int i=0;i<this->qtPontos;i++)
    {
        float* aux= this->pontos[i].GetPvista();
        x1=(d/hx)*(*aux/(*(aux+2)));
        y1=(d/hy)*(*(aux+1)/(*(aux+2)));
        x2=(x1+1)*(width/2);
        y2=(1-y1)*(height/2);
        x=(int)x2;
        y=(int)y2;
        this->pontos[i].addPontoTela(x,y);

    }
}
int Objeto::getQpontos(){
    return this->qtPontos;
}
int Objeto::getQtriangulos(){
    return this->qtTriangulos;
}
