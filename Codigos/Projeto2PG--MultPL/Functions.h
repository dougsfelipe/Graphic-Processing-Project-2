#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
class Functions
{
private:
    //alfa; [I]e,alfa;
    float* U;
    float* V;
    float* N;
    float* C;//cordenadas no mundo da camera
    float retorno[3];
    //
public:
    void setAlpha(float* U,float* V,float* N,float* C);
    float calcNorma(float* vetor);
    void normalizar(float* vetor);
    float* calcProj(float* N,float* V);
    float* calcOrtogonal(float* N, float* V);
    float* calcVetorProdVet(float* v1,float* v2);
    float* calcCord_vista(float* v);
    float* CorProdutoComponenteComponente(float* cor1,float* cor2);
    float* CorProdutoComponenteConstante(float* cor, float k);
};
#endif // FUNCTIONS_H_INCLUDED
