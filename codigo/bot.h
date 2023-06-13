#ifndef CODIGO_BOT_H
#define CODIGO_BOT_H
#include "jugador.h"
#include <string>

class Bot: public Jugador{
public:
    Bot(int dimension);
    ~Bot();
    void disparar(Tablero *tableroEnemigo);
    void ponerBarcos();
};
#endif