#include "bot.h"
#include <time.h>

Bot::Bot(int dimension):Jugador("CPU", dimension){

}
Bot::~Bot(){

}
void Bot::ponerBarcos(){
    int x, y, dim;
    bool horizontal, valido=true;
    dim = tablero->getDimension();
    do{
        x=rand()%dim;
        y=rand()%dim;
        horizontal = rand()%2;
        valido = tablero->posicionarBarco(x, y, 1, 'P', horizontal); 
    }while(!valido);
    do{
        x=rand()%dim;
        y=rand()%dim;
        horizontal = rand()%2;
        valido = tablero->posicionarBarco(x, y, 2, 'D', horizontal); 
    }while(!valido);
    do{
        x=rand()%dim;
        y=rand()%dim;
        horizontal = rand()%2;
        valido = tablero->posicionarBarco(x, y, 2, 'D', horizontal);
    }while(!valido);
    do{
        x=rand()%dim;
        y=rand()%dim;
        horizontal = rand()%2;
        valido = tablero->posicionarBarco(x, y, 3, 'S', horizontal);
    }while(!valido);;
    do{
        x=rand()%dim;
        y=rand()%dim;
        horizontal = rand()%2;
        valido = tablero->posicionarBarco(x, y, 3, 'S', horizontal);
    }while(!valido);
    do{
        x=rand()%dim;
        y=rand()%dim;
        horizontal = rand()%2;
        valido = tablero->posicionarBarco(x, y, 4, 'C', horizontal);
    }while(!valido);
    do{
        x=rand()%dim;
        y=rand()%dim;
        horizontal = rand()%2;
        valido = tablero->posicionarBarco(x, y, 5, 'A', horizontal);
    }while(!valido);
}
void Bot::disparar(Tablero *tableroEnemigo){
    int x, y, dim;
    bool valido;
    dim = tablero->getDimension();
    do{
        x=rand()%dim;
        y=rand()%dim;
        tableroEnemigo->atacar(x,y);
    }while(!valido);
    
}