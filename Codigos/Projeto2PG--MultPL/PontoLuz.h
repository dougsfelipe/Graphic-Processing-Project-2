#ifndef PONTOLUZ_H_INCLUDED
#define PONTOLUZ_H_INCLUDED
#include"Functions.h"
class PontoLuz
{
    private:
        float cord_Mundo[3];
        float cord_vista[3];
        float cor[3];
        Functions* funct;
    public:
        void addPontoLuz(float x,float y,float z,float r,float g,float b);
        void addCortdVista(float* v);
        float* getCordMundo();
        float* getCordVista();
        float* gerCor();
};


#endif // PONTOLUZ_H_INCLUDED
