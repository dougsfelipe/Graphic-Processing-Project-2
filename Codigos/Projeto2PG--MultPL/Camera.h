#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED
#include "Functions.h"
#include <stdio.h>
class Camera{
private:
    float C[3];
    float N[3];
    float V[3];
    float U[3];
    float d;
    float hx;
    float hy;
    Functions* funct;
public:
    bool InicializarCam(Functions* funct,FILE* out);
    float* GetC();
    float* GetN();
    float* GetU();
    float* GetV();
    float Getd();
    float Gethx();
    float Gethy();

};

#endif // CAMERA_H_INCLUDED
