#ifndef CODIGO_JUGADOR_H
#define CODIGO_JUGADOR_H
#include "tablero.h"
#include <string>

class Tablero;
class Jugador{
protected:
    std::string nombre;
    bool turno;
    Tablero* tablero;
    void validarIngresoXY(int* ingresado);
    void validarIngresoDir(int* ingresado);
public:
    Jugador();
    Jugador(std::string name, int dimension);
    ~Jugador();
    Tablero* getTablero();
    virtual void ponerBarcos();
    virtual void disparar(Tablero *tableroEnemigo);
    std::string getNombre();
    bool getTurno();
    void setTurno(bool turn);
};

#endif