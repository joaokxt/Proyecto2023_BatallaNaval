#ifndef CODIGO_TABLERO_H
#define CODIGO_TABLERO_H
#include "barco.h"
#include <string>

class Barco;
class Tablero{
private:
    int dimension;
    char** posiciones;
    Barco* barcos[7];
    int cantBarcos;
public:
    Tablero();
    Tablero(int dimension);
    ~Tablero();
    void poblar();
    void dibujar();
    void enemigoDibujar();
    bool posicionarBarco(int x, int y, int size, char tipo, bool horizontal);
    bool atacar(int x, int y);
    bool flotaOperante();
    int getDimension();
};

#endif