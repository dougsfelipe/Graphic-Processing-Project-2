#include "Camera.h"
#include "Ponto.h"
#include "PontoLuz.h"
#include "Iluminacao.h"
#include "Triangulo.h"
#include "Objeto.h"
#include "Tela.h"
#include <iostream>
using namespace std;

void Tela::iniciate(Objeto* obj,Iluminacao* ilumin,Camera* Cam)
{
    for(int i=0;i<720;i++){
        for(int j=0;j<720;j++){
            this->zbufer[i][j]=340282300000000000000000000000000000000;
        }
    }
    int x=obj->getQtriangulos();
    Triangulo* triangulo=obj->getTriangulos();
    Ponto** pontos;
        Ponto* p1;
        Ponto* p2;
        Ponto* p3;
        int y1;
        int y2;
        int x1;
        int x2;
        int alpha;
        int xmax;
    for(int i=0;i<x;i++)
    {
         pontos=(triangulo+i)->getPontos();
         p1=*pontos;
         p2=*(pontos+1);
         p3=*(pontos+2);
         y1=*(p1->GetPtela()+1);
         y2=*(p2->GetPtela()+1);
         x1=*(p1->GetPtela());
         x2=*(p2->GetPtela());
        cout<<x1<<","<<y1<<" "<<x2<<","<<y2<<endl;
        alpha=(y2-y1)/(x2-x1);
         //xmax=(1/alpha)+1;

    }
}
