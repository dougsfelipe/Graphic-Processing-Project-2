#ifndef TELA_H_INCLUDED
#define TELA_H_INCLUDED
#include "Camera.h"
#include "Ponto.h"
#include "PontoLuz.h"
#include "Iluminacao.h"
#include "Triangulo.h"
#include "Objeto.h"
class Tela
{
private:
    float zbufer[720][720];
public:
    void iniciate(Objeto* obj,Iluminacao* ilumin,Camera* cam);

};


#endif // TELA_H_INCLUDED
