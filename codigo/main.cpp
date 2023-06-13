#include <iostream>
#include <stdlib.h>
#include "tablero.h"
#include "barco.h"
#include "jugador.h"
#include "bot.h"
using namespace std;

Jugador* jugadores[2];
Bot* bot;
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
    cout<<"Perfecto, "<<name<<"!"<<endl;
    cout<<"Ahora, deci de que tamano queres que sea tu tablero."<<endl;
    cout<<"Tiene que ser de por lo menos 9x9!"<<endl;
    do{
        cout<<">>> ";
        cin>>dimension;
        if(dimension<9){
            cout<<"Acordate, por lo menos 9x9!"<<endl;
        }
    }while(dimension<9);

    jugadores[0] = new Jugador(name, dimension);
    bot = new Bot(dimension);

    tableros[0] = jugadores[0]->getTablero();
    tableros[1] = bot->getTablero();
    tableros[0]->poblar();
    tableros[1]->poblar();

    jugadores[0]->ponerBarcos();
    bot->ponerBarcos();
    jugadores[0]->setTurno(true);
    jugadores[1]->setTurno(false);
    
    do{
        system("cls");
        cout<<"TU TABLERO "<<endl;
        tableros[0]->dibujar();
        cout<<"TABLERO DE "<<bot->getNombre()<<endl;
        tableros[1]->enemigoDibujar();
        /*
        cout<<"FLOTA DE "<<jugadores[0]->getNombre()<<endl;
        tableros[0]->resumenFlota();
        cout<<"FLOTA DE "<<jugadores[1]->getNombre()<<endl;
        tableros[1]->resumenFlota();*/
        if(jugadores[0]->getTurno()){
            cout<<"TURNO DE "<<jugadores[0]->getNombre()<<endl;
            cout<<"\nATACA!"<<endl;
            jugadores[0]->disparar(tableros[1]);
            jugadores[0]->setTurno(false);
            bot->setTurno(true);
            cout<<"Ingresa algo para seguir: ";
            cin>>ing;

        }else{
            cout<<"TURNO DE "<<bot->getNombre()<<endl;
            cout<<"TU TABLERO "<<endl;
            tableros[1]->dibujar();
            cout<<"TABLERO DE "<<jugadores[0]->getNombre()<<endl;
            tableros[0]->enemigoDibujar();
            cout<<"\nLA CPU ATACA!"<<endl;
            cout<<"RESULTADOS: "<<endl;
            bot->disparar(tableros[0]);
            jugadores[0]->setTurno(true);
            bot->setTurno(false);
            cout<<"Ingresa algo para seguir: ";
            cin>>ing;
        }
        if(tableros[0]->flotaOperante()==false){
            cout<<"GANO "<<bot->getNombre()<<endl;
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
    cin>>name2;
    cout<<"Hola, "<<name2<<"!"<<endl;
    cout<<"Ahora, deci de que tamano queres que sea tu tablero."<<endl;
    cout<<"Tiene que ser de por lo menos 9x9!"<<endl;
    do{
        cout<<">>> ";
        cin>>dimension;
        if(dimension<9){
            cout<<"Acordate, por lo menos 9x9!"<<endl;
        }
    }while(dimension<9);

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
        /*
        cout<<"FLOTA DE "<<jugadores[0]->getNombre()<<endl;
        tableros[0]->resumenFlota();
        cout<<"FLOTA DE "<<jugadores[1]->getNombre()<<endl;
        tableros[1]->resumenFlota();*/
        if(jugadores[0]->getTurno()){
            cout<<"TURNO DE "<<jugadores[0]->getNombre()<<endl;
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
            cout<<"TURNO DE "<<jugadores[1]->getNombre()<<endl;
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

}

int main(){
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
    
}