#include <iostream>
#include "jugador.h"
#include "tablero.h"
using namespace std;

Jugador::Jugador(){
    nombre = "Anonimo";
    turno = false;
}
Jugador::Jugador(string name, int dimension){
    nombre = name;
    turno = false;
    tablero = new Tablero(dimension);
}
Jugador::~Jugador(){
    delete tablero;
}
Tablero* Jugador::getTablero(){
    return tablero;
}
void Jugador::ponerBarcos(){
    
}
bool Jugador::getTurno(){
    return turno;
}
void Jugador::setTurno(bool turn){
    turno = turn;
}
