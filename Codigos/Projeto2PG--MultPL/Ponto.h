#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED
class Ponto
{
private:
    float ponto[3];
    float pnormal[3];
    float sTnomal[3];
    int nTincidentes;
public:
    void addPonto(float x,float y,float z);
    float* GetPonto();
    float* GetPnormal();
    void addTnormal(float x,float y,float z);
};
#endif // PONTO_H_INCLUDED
