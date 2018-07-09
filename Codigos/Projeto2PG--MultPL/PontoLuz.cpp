#include"PontoLuz.h"
#include<iostream>
using namespace std;

void PontoLuz::addPontoLuz(float x,float y, float z, float r, float g,float b)
{
    this->cord_Mundo[0]=x;this->cord_Mundo[1]=y;this->cord_Mundo[2]=z;
    this->cor[0]=r;this->cor[1]=g;this->cor[2]=b;
}
void  PontoLuz::addCortdVista(float* v)
{
    this->cord_vista[0]=*v;this->cord_vista[1]=*(v+1);this->cord_vista[2]=*(v+2);
}
float* PontoLuz::getCordVista()
{
    return this->cord_vista;
}
float* PontoLuz::getCordMundo()
{
    return this->cord_Mundo;
}
float* PontoLuz::gerCor()
{
    return this->cor;
}
