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
    void poblarTablero();
    void dibujarTablero();
    void dibujarTableroEnemigo();
    bool posicionarBarco(int x, int y, int size, bool horizontal);
    bool atacar(int x, int y);
    int getDimension();
};

#endif