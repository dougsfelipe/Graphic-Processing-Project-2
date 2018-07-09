#include "Ponto.h"
#include "Triangulo.h"
#include<iostream>
#include"Camera.h"
#include"Functions.h"
#include"Objeto.h"
#include"Iluminacao.h"
#include <stdio.h>

using namespace std;

int main()
{
    FILE* out=fopen("out.txt","w");
    Functions funct;
    Camera cam;
    Objeto obj;
    Iluminacao Iluminacao;
    cam.InicializarCam(&funct,out);
    obj.iniciarObj(&funct,out);
    Iluminacao.inicarIluminacao(&funct,out);
    fclose(out);

    return 0;
}
