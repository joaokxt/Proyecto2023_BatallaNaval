#ifndef CODIGO_HUMANO_H
#define CODIGO_HUMANO_H
#include "jugador.h"
#include <string>

class Humano: public Jugador{
private:
    std::string nombre;
public:
    Humano(std::string name);
    ~Humano();
};
#endif