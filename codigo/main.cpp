#include <iostream>
#include "tablero.h"
#include "barco.h"
using namespace std;

int main(){
    Tablero* tablero;
    tablero = new Tablero();
    tablero->poblar();
    tablero->dibujar();
    delete tablero;
    return 0;
}