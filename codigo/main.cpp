#include <iostream>
#include <limits>
#include <stdlib.h>
#include "tablero.h"
#include "barco.h"
#include "jugador.h"
#include "bot.h"
using namespace std;

Jugador* jugadores[2];
Tablero* tableros[2];

char opcion;
int num;

void unJugador(){
    string name;
    int dimension;
    bool valido=false, gameOver=false;
    char ing;

    system("cls");
    cout<<"-=-=-=-=-=| UN JUGADOR |-=-=-=-=-="<<endl;
    cout<<"Aca vas a jugar una partida contra la computadora."<<endl;
    cout<<"Primero, como queres que te llame?"<<endl;
    cout<<">>> ";
    cin>>name;
    cin.ignore();
    cout<<"Perfecto, "<<name<<"!"<<endl;
    cout<<"Ahora, deci de que tamano queres que sea tu tablero."<<endl;
    cout<<"Tiene que ser de por lo menos 9x9!"<<endl;
    do {
        cout<<"Ingresa un numero >>> ";
        cin>>dimension;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Dimension no valida. Debes ingresar un numero."<<endl;
            valido=false;
        }
        else if (cin.peek() != '\n') {
            cout<<"Dimension no valida. Debes ingresar un numero."<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            valido = false;
        }
        else if (dimension<9){
            cout<<"Acordate, por lo menos 9x9!"<<endl;
            valido=false;
        }
        else {
            valido = true;
        }
    } while (!valido);

    system("cls");

    jugadores[0] = new Jugador(name, dimension);
    jugadores[1] = new Bot(dimension);

    tableros[0] = jugadores[0]->getTablero();
    tableros[1] = jugadores[1]->getTablero();
    tableros[0]->poblar();
    tableros[1]->poblar();

    jugadores[0]->ponerBarcos();
    jugadores[1]->ponerBarcos();
    jugadores[0]->setTurno(true);
    jugadores[1]->setTurno(false);
    
    do{
        system("cls");
        cout<<"TU TABLERO "<<endl;
        tableros[0]->dibujar();
        cout<<"TABLERO DE "<<jugadores[1]->getNombre()<<endl;
        tableros[1]->enemigoDibujar();
        if(jugadores[0]->getTurno()){
            cout<<"\n-=-=-=-=-=|TURNO DE "<<jugadores[0]->getNombre()<<"|=-=-=-=-=-"<<endl;
            cout<<"ATACA!"<<endl;
            jugadores[0]->disparar(tableros[1]);
            cout<<"\n-=-=-=-=-=|RESULTADOS|=-=-=-=-=-"<<endl;
            cout<<"TABLERO DE "<<jugadores[1]->getNombre()<<endl;
            tableros[1]->enemigoDibujar();
            jugadores[0]->setTurno(false);
            jugadores[1]->setTurno(true);
            cout<<"Ingresa algo para seguir: ";
            cin>>ing;

        }else{
            system("cls");
            cout<<"\n-=-=-=-=-=|TURNO DE "<<jugadores[1]->getNombre()<<"|=-=-=-=-=-"<<endl;
            cout<<"LA CPU ATACA!"<<endl;
            cout<<"RESULTADO: ";
            jugadores[1]->disparar(tableros[0]);
            cout<<"\n-=-=-=-=-=|RESULTADOS|=-=-=-=-=-"<<endl;
            cout<<"TU TABLERO "<<endl;
            tableros[0]->dibujar();
            jugadores[0]->setTurno(true);
            jugadores[1]->setTurno(false);
            cout<<"Ingresa algo para seguir: ";
            cin>>ing;
        }
        if(tableros[0]->flotaOperante()==false){
            cout<<"GANO "<<jugadores[1]->getNombre()<<endl;
            gameOver = true;
        }
        if(tableros[1]->flotaOperante()==false){
            cout<<"GANO "<<jugadores[0]->getNombre()<<endl;
            gameOver = true;
        }
    }while(!gameOver);

}

void dosJugadores(){
    string name1, name2;
    int dimension;
    bool valido=false, gameOver=false;
    char ing;

    system("cls");
    cout<<"-=-=-=-=-=| DOS JUGADORES |-=-=-=-=-="<<endl;
    cout<<"Aca vas a jugar una partida contra un amigo."<<endl;
    cout<<"Primero, como queres que llame al primer jugador?"<<endl;
    cout<<">>> ";
    cin>>name1;
    cout<<"Perfecto, "<<name1<<"!"<<endl;
    cout<<"Ahora, como queres que llame al segundo jugador?"<<endl;
    cout<<">>> ";
    cin.ignore();
    cin>>name2;
    cout<<"Hola, "<<name2<<"!"<<endl;
    cout<<"Ahora, deci de que tamano queres que sea tu tablero."<<endl;
    cout<<"Tiene que ser de por lo menos 9x9!"<<endl;
    cin.ignore();
    do {
        cout<<">>> ";
        cin>>dimension;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Dimension no valida. Debes ingresar un numero."<<endl;
            valido=false;
        }
        else if (cin.peek() != '\n') {
            cout<<"Dimension no valida. Debes ingresar un numero."<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            valido = false;
        }
        else if (dimension<9){
            cout<<"Acordate, por lo menos 9x9!"<<endl;
            valido=false;
        }
        else {
            valido = true;
        }
    } while (!valido);

    jugadores[0] = new Jugador(name1, dimension);
    jugadores[1] = new Jugador(name2, dimension);

    tableros[0] = jugadores[0]->getTablero();
    tableros[1] = jugadores[1]->getTablero();
    tableros[0]->poblar();
    tableros[1]->poblar();

    system("cls");
    cout<<jugadores[0]->getNombre()<<endl;
    jugadores[0]->ponerBarcos();
    system("cls");
    cout<<jugadores[1]->getNombre()<<endl;
    jugadores[1]->ponerBarcos();
    jugadores[0]->setTurno(true);
    jugadores[1]->setTurno(false);

    do{
        system("cls");
        if(jugadores[0]->getTurno()){
            cout<<"\n-=-=-=-=-=|TURNO DE "<<jugadores[0]->getNombre()<<"|=-=-=-=-=-"<<endl;
            cout<<"TU TABLERO "<<endl;
            tableros[0]->dibujar();
            cout<<"TABLERO DE "<<jugadores[1]->getNombre()<<endl;
            tableros[1]->enemigoDibujar();
            cout<<"\nATACA!"<<endl;
            jugadores[0]->disparar(tableros[1]);
            jugadores[0]->setTurno(false);
            jugadores[1]->setTurno(true);
            cout<<"Ingresa algo para seguir: ";
            cin>>ing;

        }else{
            cout<<"\n-=-=-=-=-=|TURNO DE "<<jugadores[1]->getNombre()<<"|=-=-=-=-=-"<<endl;
            cout<<"TU TABLERO "<<endl;
            tableros[1]->dibujar();
            cout<<"TABLERO DE "<<jugadores[0]->getNombre()<<endl;
            tableros[0]->enemigoDibujar();
            cout<<"\nATACA!"<<endl;
            jugadores[1]->disparar(tableros[0]);
            jugadores[0]->setTurno(true);
            jugadores[1]->setTurno(false);
            cout<<"Ingresa algo para seguir: ";
            cin>>ing;
        }
        if(tableros[0]->flotaOperante()==false){
            cout<<"GANO "<<jugadores[1]->getNombre()<<endl;
            gameOver = true;
        }
        if(tableros[1]->flotaOperante()==false){
            cout<<"GANO "<<jugadores[0]->getNombre()<<endl;
            gameOver = true;
        }
    }while(!gameOver);

}

void reglas(){
    char ing;
    cout<<"-=-=-=-=-=| REGLAS BASICAS |-=-=-=-=-="<<endl;
    cout<<"1- Objetivo: El objetivo del juego es hundir los barcos del oponente antes de que el hunda los tuyos. "
          "El primer jugador en hundir todos los barcos enemigos gana."<<endl;
    cout<<"2- Tablero: Cada jugador tiene su propio tablero en el que coloca sus barcos y marca los disparos realizados. "
          "Las casillas del tablero se identifican mediante coordenadas."<<endl;
    cout<<"3- Barcos: Cada jugador tiene una flota de barcos de diferentes tamanios. Los barcos no se superponen ni se "
          "colocan en diagonales. Los barcos pueden ser colocados vertical u horizontalmente en el tablero."<<endl;
    cout<<"4- Tamanios de barcos: Puedes tener diferentes tamanios de barcos en tu juego."<<endl;
        cout<<"*Patrullero -> 1 casilla"<<endl;
        cout<<"*Destructor -> 2 casillas"<<endl;
        cout<<"*Submarino -> 3 casillas"<<endl;
        cout<<"*Crucero -> 3 casillas"<<endl;
        cout<<"*Acorazado -> 4 casillas"<<endl;
    cout<<"5- Disparos: Los jugadores se turnan para realizar disparos. El objetivo es adivinar la ubicacion de los "
          "barcos enemigos y marcar esa casilla como \"impactada\" o \"agua\" si se falla el disparo."<<endl;
    cout<<"6- Hundimiento de barcos: Un barco se considera hundido cuando todas las casillas que ocupa han sido impactadas por el oponente."<<endl;
    cout<<"7- Estrategia: Los jugadores deben usar la logica y la deduccion para determinar la ubicacion de los barcos enemigos. "
          "Basandose en los resultados de los disparos anteriores, pueden hacer suposiciones y adaptar su estrategia para maximizar sus posibilidades de exito."<<endl;
    cout<<"8- Ganador: El juego continua hasta que todos los barcos de un jugador hayan sido hundidos. El primer jugador en hundir todos los barcos enemigos es el ganador."<<endl;
    cout<<endl;
    cout<<"Ingresa algo para volver al menu: ";
    cin>>ing;
}

int main(){
    do{
    system("cls");
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
    }while(opcion==51);
    
}