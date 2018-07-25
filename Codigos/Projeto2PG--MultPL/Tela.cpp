#include "Camera.h"
#include "Ponto.h"
#include "PontoLuz.h"
#include "Iluminacao.h"
#include "Triangulo.h"
#include "Objeto.h"
#include "Tela.h"
#include <iostream>
using namespace std;
void calcColor(int x,int y,float* N,float* V,Iluminacao* Ilumin){

}
void calcCordVistaP(int x,int y, Triangulo* t)
{
    int i,j;
    float sistema[3][4];
    float solucao[3];
    float coef_10, coef_20, coef_21;
    Ponto** pontos=t.getPontos();
    Ponto* p1 =*pontos;
    Ponto* p2 =*(pontos+1);
    Ponto* p3 = *(pontos+2);
    sistema[0][0]=(float)*p1.GetPtela();sistema[0][1]=(float)*p2.GetPtela();sistema[0][2]=(float)*p3.GetPtela();sistema[0][3]=x;
    sistema[1][0]=(float)*(p1.GetPtela()+1);sistema[1][1]=(float)*(p2.GetPtela()+1);sistema[1][2]=(float)*(p3.GetPtela()+1);sistema[0][3]=y;
    sistema[2][0]=(float)1=(float)1;sistema[2][2]=(float)1();sistema[2][3]=1;
    coef_10 = -1.0 * sistema[1][0] / sistema[0][0];
    coef_20 = -1.0 * sistema[2][0] / sistema[0][0];
    for (j = 0; j < 4; j++) {
    sistema[1][j] += coef_10 * sistema[0][j];
    sistema[2][j] += coef_20 * sistema[0][j];
}
    coef_21 = -1.0 * sistema[2][1] / sistema [1][1];
    for (j = 1; j < 4; j++) {
    sistema[2][j] += coef_21 * sistema[1][j];
    }
    solucao[2] = (sistema[2][3]) / sistema[2][2];
    solucao[1] = (sistema[1][3] - (solucao[2] * sistema[1][2])) / sistema[1][1];
    solucao[0] = (sistema[0][3] - (solucao[2] * sistema[0][2]) - (solucao[1] * sistema[0][1])) / sistema[0][0];
    float ponto3d[3];
    ponto3d[0]=(*p1->GetPvista()*solucao[0])+(*p2->GetPvista()*solucao[1])+(*p3->GetPonto()*solucao[2]);
    ponto3d[1]=(*(p1->GetPvista()+1)*solucao[0])+(*(p2->GetPvista()+1)*solucao[1])+(*(p3->GetPonto()+1)*solucao[2]);
    ponto3d[2]=(*(p1->GetPvista()+2)*solucao[0])+(*(p2->GetPvista()+2)*solucao[1])+(*(p3->GetPonto()+2)*solucao[2]);
    if(ponto3d[3]<this->zbufer[x][y]){
        this->zbufer[x][y]=ponto3d[3];
        float nponto3d[3];
        nponto3d[0]=(*p1->GetPnormal()*solucao[0])+(*p2->GetPnormal()*solucao[1])+(*p3->GetPnormal()*solucao[2]);
        nponto3d[1]=(*(p1->GetPnormal()+1)*solucao[0])+(*(p2->GetPnormal()+1)*solucao[1])+(*(p3->pnormal()+1)*solucao[2]);
        nponto3d[2]=(*(p1->GetPnormal()+2)*solucao[0])+(*(p2->GetPnormal()+2)*solucao[1])+(*(p3->GetPnormal()+2)*solucao[2]);

    }
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
