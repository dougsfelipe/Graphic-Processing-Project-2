#include "Ponto.h"
#include "Triangulo.h"
#include<iostream>
#include"Camera.h"
using namespace std;

int main()
{
    Camera cam;
    cam.InicializarCam();
    Ponto p1,p2,p3;
    p1.addPonto(3,6,12);
    p2.addPonto(3,12,24);
    p3.addPonto(6,9,12);
    cout <<*p1.GetPonto()<<" " <<*(p1.GetPonto()+1)<<" "<<*(p1.GetPonto()+2)<< endl;
    cout <<*p1.GetPnormal()<<" " <<*(p1.GetPnormal()+1)<<" "<<*(p1.GetPnormal()+2)<< endl;
    cout <<*p2.GetPonto()<<" " <<*(p2.GetPonto()+1)<<" "<<*(p2.GetPonto()+2)<< endl;
    cout <<*p2.GetPnormal()<<" " <<*(p2.GetPnormal()+1)<<" "<<*(p2.GetPnormal()+2)<< endl;
    cout <<*p3.GetPonto()<<" " <<*(p3.GetPonto()+1)<<" "<<*(p3.GetPonto()+2)<< endl;
    cout <<*p3.GetPnormal()<<" " <<*(p3.GetPnormal()+1)<<" "<<*(p3.GetPnormal()+2)<< endl;
    Triangulo t1;
    t1.CriarTriangulo(&p1,&p2,&p3);
    cout<<*t1.getTnormal()<<" "<<*(t1.getTnormal()+1)<<" "<<*(t1.getTnormal()+2)<<endl;
    cout <<*p1.GetPonto()<<" " <<*(p1.GetPonto()+1)<<" "<<*(p1.GetPonto()+2)<< endl;
    cout <<*p1.GetPnormal()<<" " <<*(p1.GetPnormal()+1)<<" "<<*(p1.GetPnormal()+2)<< endl;
    cout <<*p2.GetPonto()<<" " <<*(p2.GetPonto()+1)<<" "<<*(p2.GetPonto()+2)<< endl;
    cout <<*p2.GetPnormal()<<" " <<*(p2.GetPnormal()+1)<<" "<<*(p2.GetPnormal()+2)<< endl;
    cout <<*p3.GetPonto()<<" " <<*(p3.GetPonto()+1)<<" "<<*(p3.GetPonto()+2)<< endl;
    cout <<*p3.GetPnormal()<<" " <<*(p3.GetPnormal()+1)<<" "<<*(p3.GetPnormal()+2)<< endl;
    return 0;
}
