#ifndef CODIGO_BOT_H
#define CODIGO_BOT_H
#include "jugador.h"
#include <string>

class Bot: public Jugador{
private:
    int dificultad;
public:
    Bot(int difficulty);
    ~Bot();
};
#endif