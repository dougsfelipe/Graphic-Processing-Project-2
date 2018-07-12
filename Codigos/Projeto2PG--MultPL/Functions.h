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
    void calcProj(float* N,float* V);
    void calcOrtogonal(float* N, float* V);
    void calcVetorProdVet(float* v1,float* v2);
    void calcCord_vista(float* v);
    void CorProdutoComponenteComponente(float* cor1,float* cor2);
    void CorProdutoComponenteConstante(float* cor, float k);
    float* GetRetorno();
};
#endif // FUNCTIONS_H_INCLUDED
