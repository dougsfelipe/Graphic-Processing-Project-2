#include "Camera.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

bool Camera::InicializarCam(Functions* funct,FILE* out)
{
    FILE *camera=fopen("camera.cfg","rt");
    if(camera!=NULL)
    {
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
        this->funct->normalizar(this->N);
        float* aux=this->funct->calcOrtogonal(this->N,this->V);
        this->V[0]=*aux;this->V[1]=*(aux+1);this->V[2]=*(aux+2);
        this->funct->normalizar(this->V);
        float* u =this->funct->calcVetorProdVet(this->N,this->V);
        this->U[0]=*u;this->U[1]=*(u+1);this->U[2]=*(u+2);
        this->funct->setAlpha(this->U,this->V,this->N,this->C);
        fprintf(out,"CAMERA:\n");
        fprintf(out,"C: %f,%f,%f\n",this->C[0],this->C[1],this->C[2]);
        fprintf(out,"N: %f,%f,%f\n",this->N[0],this->N[1],this->N[2]);
        fprintf(out,"V: %f,%f,%f\n",this->V[0],this->V[1],this->V[2]);
        fprintf(out,"U: %f,%f,%f\n",this->U[0],this->U[1],this->U[2]);
         fprintf(out,"d: %f hx: %f hy: %f\n",this->d,this->hx,this->hy);
        cout<<"CAMERA:"<<endl;
        cout<<"C: "<<this->C[0]<<", "<<this->C[1]<<", "<<this->C[2]<<endl;
        cout<<"N: "<<this->N[0]<<", "<<this->N[1]<<", "<<this->N[2]<<endl;
        cout<<"V: "<<this->V[0]<<", "<<this->V[1]<<", "<<this->V[2]<<endl;
        cout<<"U: "<<this->U[0]<<", "<<this->U[1]<<", "<<this->U[2]<<endl;
        cout<<"d: "<<this->d<<" hx: "<<this->hx<<" hy: "<<this->hy<<endl;


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
