#ifndef CODIGO_JUGADOR_H
#define CODIGO_JUGADOR_H
#include "tablero.h"
#include <string>

class Tablero;
class Jugador{
protected:
    int puntaje;
    bool turno;
    Tablero* tablero;
public:
    Jugador(std::string name, Tablero* board);
    ~Jugador();
    int getPuntaje();
    Tablero* getTablero();
    bool esTurno();
    void setTurno(bool turn);
};

#endif