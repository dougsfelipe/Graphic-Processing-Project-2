#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

class Camera{
private:
    float C[3];
    float N[3];
    float V[3];
    float U[3];
    float d;
    float hx;
    float hy;
public:
    bool InicializarCam();
    float* GetC();
    float* GetN();
    float* GetU();
    float Getd();
    float Gethx();
    float Gethy();
};

#endif // CAMERA_H_INCLUDED
