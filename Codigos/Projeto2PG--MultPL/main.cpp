#include <iostream>
#include "Ponto.h"
using namespace std;

int main()
{
    Ponto p;
    float x= 3;
    float y=6;
    float z= 12;
    p.addPonto(x,y,z);
    //cout <<p.GetPonto()<<" " <<p.GetPonto()<<" "<<p.GetPonto()<< endl;
    return 0;
}
