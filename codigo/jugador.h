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
public:
    Jugador();
    Jugador(std::string name, int dimension);
    ~Jugador();
    Tablero* getTablero();
    void ponerBarcos();
    bool getTurno();
    void setTurno(bool turn);
};

#endif