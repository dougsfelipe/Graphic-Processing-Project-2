#include "Camera.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

bool Camera :: InicializarCam(Functions* funct)
{
    FILE *camera=fopen("camera.cfg","rt");
    if(camera!=NULL)
    {
        //carrengando valores da camaera
        this->funct=funct;
        fscanf(camera,"%f",&this->C[0]);
        fscanf(camera,"%f",&this->C[1]);
        fscanf(camera,"%f",&this->C[2]);
        fscanf(camera,"%f",&this->N[0]);
        fscanf(camera,"%f",&this->N[1]);
        fscanf(camera,"%f",&this->N[2]);
        fscanf(camera,"%f",&this->V[0]);
        fscanf(camera,"%f",&this->V[1]);
        fscanf(camera,"%f",&this->V[2]);
        fscanf(camera,"%f",&this->d);
        fscanf(camera,"%f",&this->hx);
        fscanf(camera,"%f",&this->hy);
        fclose(camera);
        //

        float* aux=this->funct->GetRetorno();//auxiliar dos calculos

        //normalizar N
        this->funct->normalizar(this->N);
        this->N[0]=*(aux);this->N[1]=*(aux+1);this->N[2]=*(aux+2);
        //

        //ortogonalizar V
        this->funct->calcOrtogonal(this->N,this->V);
        this->V[0]=*aux;this->V[1]=*(aux+1);this->V[2]=*(aux+2);
        //

        //normalizar V
        this->funct->normalizar(this->V);
        this->V[0]=*(aux);this->V[1]=*(aux+1);this->V[2]=*(aux+2);
        //

        //calcaur U=NxV
        this->funct->calcVetorProdVet(this->N,this->V);
        this->U[0]=*aux;this->U[1]=*(aux+1);this->U[2]=*(aux+2);
        //

        this->funct->setAlpha(this->U,this->V,this->N,this->C);//colocando a matriz na area de calcular funções;


        return true;
    }
    else{
        fclose(camera);
        return false;
    }

}
    float* Camera::GetC()
    {
        return this->C;
    }
    float* Camera::GetV()
    {
        return this->V;
    }
    float* Camera::GetN()
    {
        return this->N;
    }
    float Camera::Getd()
    {
        return this->d;
    }
    float Camera::Gethx()
    {
        return this->hx;
    }
    float Camera::Gethy()
    {
        return this->hy;
    }
    void Camera::printCam(FILE* out)
    {
        fprintf(out,"U:(%f,%f,%f)\nV:(%f,%f,%f)\nN:(%f,%f,%f)\n",this->U[0],this->U[1],this->U[2],this->V[0],this->V[1],this->V[2],this->N[0],this->N[1],this->N[2]);
    }
