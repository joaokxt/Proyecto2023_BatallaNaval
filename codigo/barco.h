#ifndef CODIGO_BARCO_H
#define CODIGO_BARCO_H

class Barco{
private:
    int tamanio;
    int vida;
    int pos[2];
    bool horizontal;
public:
    Barco();
    Barco(int size, int* pos, bool horizontal);
    ~Barco();
    int getTamanio();
    int getVida();
    void bajarVida();
    bool estarHundido();
};

#endif