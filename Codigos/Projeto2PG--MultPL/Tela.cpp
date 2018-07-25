#include "Camera.h"
#include "Ponto.h"
#include "PontoLuz.h"
#include "Iluminacao.h"
#include "Triangulo.h"
#include "Objeto.h"
#include "Tela.h"
#include <iostream>
using namespace std;
void calcCordVistaP(int x,int y, Triangulo* t)
{

}
void preencherTrianguloRetaBaixo(Ponto* v1, Ponto* v2, Ponto* v3,Triangulo* t){
    int* p1;
    int* p2;
    int* p3;
    p1=v1->GetPtela();p2=v2->GetPtela();p3=v3->GetPtela();
    float alpha1 = (float)(*(p2) - *(p1)) / (*(p2+1) - *(p1+1));
    float alpha2 = (float)(*(p3) - *(p1)) / (*(p3+1) - *(p1+1));
    float cx1 = (float)*p1;
    float cx2 = (float)*p1;

    for (int y = *(p1+1); y <= *(p2+1); y++)
  {

    int x1,x2;
    x1=(int)cx1;
    x2=(int)cx2;
    if(y>=0&&y<=720){
        if(x1<=x2){
        for(;x1<=x2;x1++){
            if(x1<=720&&x1>=0){
                calcCordVistaP(x1,y,t);
            }
        }
    }
    else{
       for(;x2<=x1;x2++){
            if(x2<=720&&x2>=0){
                calcCordVistaP(x2,y,t);
            }
        }
    }
    }
    cx1 += alpha1;
    cx2 += alpha2;
  }

}
void preencherTrianguloRetaCima(Ponto* v1,Ponto* v2,Ponto* v3,Triangulo* t){
     int* p1;
     int* p2;
     int* p3;
    p1=v1->GetPtela();p2=v2->GetPtela();p2=v2->GetPtela();
    float alpha1 = (float)(*(p3) - *(p1)) / (*(p3+1) - *(p1+1));
    float alpha2 = (float)(*(p3) - *(p2)) / (*(p2+1) - *(p1+1));
    float cx1 = (float)*p3;
    float cx2 = (float)*p3;

    for (int y = *(p1+1); y > *(p1+1); y--)
  {

    int x1,x2;
    x1=(int)cx1;
    x2=(int)cx2;
    if(y>=0&&y<=720){
        if(x1<=x2){
        for(;x1<=x2;x1++){
            if(x1<=720&&x1>=0){
                calcCordVistaP(x1,y,t);
            }
        }
    }
    else{
       for(;x2<=x1;x2++){
            if(x2<=720&&x2>=0){
                calcCordVistaP(x2,y,t);
            }
        }
    }
    }
    cx1 -= alpha1;
    cx2 -= alpha2;
  }

}
void scanline(Triangulo* triangulo){
    Ponto** aux=triangulo->getPontos();
    Ponto* p1=*aux;
    Ponto* p2=*(aux+1);
    Ponto* p3=*(aux+2);
    if((*p1->GetPtela()!=*p2->GetPtela())||(*p1->GetPtela()!=*p3->GetPtela())){
        if(*(p1->GetPtela()+1)!=*(p2->GetPtela()+1)||*(p1->GetPtela()+1)!=*(p3->GetPtela()+1)){
            Ponto* pmin;Ponto*pmed;Ponto* pmax;
            if(*(p1->GetPtela()+1)<*(p2->GetPtela()+1)){
                if(*(p1->GetPtela()+1)<*(p3->GetPtela()+1)){
                    pmin=p1;
                    if(*(p2->GetPtela()+1)<*(p3->GetPtela()+1)){
                        pmed=p2;
                        pmax=p3;
                    }
                    else{
                         pmed=p3;
                        pmax=p2;
                    }
                }
                else{
                    pmin=p3;
                    pmed=p1;
                    pmax=p2;
                }
            }else{
                if(*(p2->GetPtela()+1)>*(p3->GetPtela()+1)){
                    pmin=p3;
                    pmed=p2;
                    pmax=p1;
                }
                else{
                     pmin=p2;
                    if(*(p1->GetPtela()+1)>*(p3->GetPtela()+1)){
                        pmed=p3;
                        pmax=p1;
                    }
                    else{
                    pmed=p1;
                    pmax=p3;
                    }
                }
            }
            if(*(pmed->GetPtela()+1)==*(pmax->GetPtela()+1)){
            preencherTrianguloRetaBaixo(pmin,pmed,pmax,triangulo);
        }
        else if(*(pmin->GetPtela()+1)==*(pmed->GetPtela()+1)){
            preencherTrianguloRetaCima(pmin,pmed,pmax,triangulo);
        }
        else{
            Ponto p4;
            float aux=(*(pmin->GetPtela())+(float)((*(pmed->GetPtela()+1) - *(pmin->GetPtela()+1)) /(float)(*(pmax->GetPtela()+1) - *(pmin->GetPtela()+1))) * (*(pmax->GetPtela()) - *(pmin->GetPtela())));
            p4.addPontoTela((int)aux,*(pmed->GetPtela()+1));
           preencherTrianguloRetaBaixo(pmin,pmed,&p4,triangulo);
            preencherTrianguloRetaCima(pmed,&p4,pmax,triangulo);

        }
        }


                 else{
            int xmax=0;
            int xmin=0;
        if(*(p2->GetPtela())>*(p1->GetPtela())){
                    if(*(p3->GetPtela()+1)>*(p2->GetPtela()))
                    {
                        xmax=*(p3->GetPtela());
                        xmin=*(p1->GetPtela());

                    }
                    else{
                        xmax=*(p2->GetPtela());
                        if(*(p3->GetPtela())>*(p1->GetPtela())){
                            xmin=*(p1->GetPtela());

                        }
                        else{
                            xmin=*(p3->GetPtela());
                        }
                    }
                }
                 else{
                    if(*(p1->GetPtela())<*(p3->GetPtela())){
                        xmax=*(p3->GetPtela());
                        xmin=*(p2->GetPtela());
                    }
                    else{
                        xmax=*(p1->GetPtela());
                        if(*(p2->GetPtela())<*(p2->GetPtela())){
                            xmin=*(p2->GetPtela());
                        }
                        else{
                            xmin=*(p3->GetPtela());
                        }
                    }
                }
                if(*(p1->GetPtela()+1)>=0&&*(p1->GetPtela()+1)<=720)
                {
                for(;xmin<=xmax;xmin++){
                    if(xmin<=720&&xmin>=0){
                        calcCordVistaP(xmin,*(p1->GetPtela()+1),triangulo);
                    }

                }
                }

            }
        }
        else{
            if((*(p1->GetPtela()+1)!=*(p2->GetPtela()+1))||(*(p1->GetPtela()+1)!=*(p3->GetPtela()+1))){
                int ymax=0;
                int ymin=0;

                if(*(p2->GetPtela()+1)>*(p1->GetPtela()+1)){
                    if(*(p3->GetPtela()+1)>*(p2->GetPtela()+1))
                    {
                        ymax=*(p3->GetPtela()+1);
                        ymin=*(p1->GetPtela()+1);

                    }
                    else{
                        ymax=*(p2->GetPtela()+1);
                        if(*(p3->GetPtela()+1)>*(p1->GetPtela()+1)){
                            ymin=*(p1->GetPtela()+1);

                        }
                        else{
                            ymin=*(p3->GetPtela()+1);

                        }
                    }
                }
                else{
                    if(*(p1->GetPtela()+1)<*(p1->GetPtela()+1)){
                        ymax=*(p3->GetPtela()+1);
                        ymin=*(p2->GetPtela()+1);
                    }
                    else{
                        ymax=*(p1->GetPtela()+1);
                        if(*(p2->GetPtela()+1)<*(p3->GetPtela()+1)){
                            ymin=*(p2->GetPtela()+1);
                        }
                        else{
                            ymin=*(p3->GetPtela()+1);
                        }
                    }
                }
                if(*(p1->GetPtela())>=0&&*(p1->GetPtela())<=720)
                {
                    for(;ymin<=ymax;ymin++){
                    if(ymin>=0&&ymin<=720){
                       calcCordVistaP(*(p1->GetPtela()),ymin,triangulo);
                    }
                }
                }

            }
            else{
                if(*(p1->GetPtela())>=0&&*(p1->GetPtela())<=720){
                    if(*(p1->GetPtela()+1)>=0&&*(p1->GetPtela()+1)<=720){
                        calcCordVistaP(*(p1->GetPtela()),*(p1->GetPtela()+1),triangulo);
                    }
                }
            }
        }

}
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
        if(x2==x1)
        {

        }
        else{

        }



    }
}
