#ifndef TELA_H_INCLUDED
#define TELA_H_INCLUDED
#include "Camera.h"
#include "Ponto.h"
#include "PontoLuz.h"
#include "Iluminacao.h"
#include "Triangulo.h"
#include "Objeto.h"
#include "Functions.h"
class Tela
{
private:

public:
    void iniciate(Objeto* obj,Iluminacao* ilumin,Camera* cam,Functions* funct);


};


#endif // TELA_H_INCLUDED
