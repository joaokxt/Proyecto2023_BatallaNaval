#ifndef CODIGO_TABLERO_H
#define CODIGO_TABLERO_H
#include "barco.h"

class Barco;
class Tablero{
private:
    int dimension;
    char** posiciones;
    Barco** barcos;
public:
    Tablero();
    Tablero(int dimension);
    ~Tablero();
    void posicionarBarcos(int** pos, bool* orientacion);
    void atacar(int* pos);
    int getDimension();
};

#endif