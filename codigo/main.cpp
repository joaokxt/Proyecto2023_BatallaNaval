#include <iostream>
#include "tablero.h"
#include "barco.h"
#include "jugador.h"
#include "bot.h"
using namespace std;

Jugador* jugador1;
Jugador* jugador2;

char opcion;
int num;

void unJugador(){
    string name;
    int dimension;
    bool valido=false;

    cout<<"-=-=-=-=-=| UN JUGADOR |-=-=-=-=-="<<endl;
    cout<<"Aca vas a jugar una partida contra la computadora."<<endl;
    cout<<"Primero, como queres que te llame?"<<endl;
    cout<<">>> ";
    cin>>name;
    cout<<"Perfecto, "<<name<<"!"<<endl;
    cout<<"Ahora, deci de que tamano queres que sea tu tablero."<<endl;
    cout<<"Tiene que ser de por lo menos 9x9!"<<endl;
    cout<<">>> ";
    cin>>dimension;
    jugador1 = new Jugador(name, dimension);
    jugador2 = new Bot(dimension);

    while(true){
        Tablero* tablero1 = jugador1->getTablero();
        tablero1->poblar();
        tablero1->dibujar();
        break;
        //empezar juego
    }
    
    

}

void dosJugadores(){

}

void reglas(){

}

int main(){
    cout<<"-=-=-=-=-=| BATALLA NAVAL |-=-=-=-=-="<<endl;
    cout<<"1. UN JUGADOR"<<endl;
    cout<<"2. DOS JUGADORES"<<endl;
    cout<<"3. REGLAS"<<endl;
    cout<<"X. SALIR"<<endl;
    cout<<">>> ";
    cin>>opcion;
    switch(opcion){
        case 49:
            unJugador();
            break;
        case 50:
            dosJugadores();
            break;
        case 51:
            reglas();
            break;
        default:
            return 0;
    }
    
}