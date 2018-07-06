#include<iostream>

using namespace std;

class Ponto
{
private:
    float ponto[3];
    float Pnormal[3];
public:
    void addPonto(float x,float y,float z);
    float GetPonto();
    float GetPnormal();
};
