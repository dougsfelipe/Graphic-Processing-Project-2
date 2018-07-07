#include "Camera.h"
#include <iostream>
#include <stdio.h>
using namespace std;

bool Camera::InicializarCam()
{
    FILE *camera=fopen("camera.cfg","rt");
    if(camera!=NULL)
    {
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

        cout<<this->C[0]<<" "<<this->C[1]<<" "<<this->C[2]<<endl;
        cout<<this->N[0]<<" "<<this->N[1]<<" "<<this->N[2]<<endl;
        cout<<this->V[0]<<" "<<this->V[1]<<" "<<this->V[2]<<endl;
        cout<<this->d<<" "<<this->hx<<" "<<this->hy<<endl;
        return true;
    }
    else{
        return false;
    }
}
