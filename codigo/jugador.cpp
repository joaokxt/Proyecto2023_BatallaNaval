#include <iostream>
#include <stdlib.h>
#include <limits>
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
void Jugador::validarIngresoXY(int* ingresado) {
    bool val;
    do{
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Entrada invalida. Debes ingresar un numero."<<endl;
        cout<<"Intente nuevamente >>> ";
        cin>>*ingresado;
        val=false;
    }
    else if (cin.peek() != '\n') {
        cout<<"Entrada invalida. Debes ingresar un numero."<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Intente nuevamente >>> ";
        cin>>*ingresado;
        val=false;
    }
    else if(*ingresado<0){
        cout<<"Posicion invalida, el barco esta fuera de alcance!"<<endl;
        cout<<"Intente nuevamente >>> ";
        cin>>*ingresado;
        val=false;
    }
    else {
        val=true;
    }
    }while(!val);
}
void Jugador::validarIngresoDir(int *ingresado) {
    bool val;
    do{
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Entrada invalida. Debes ingresar un numero."<<endl;
            cout<<"Intente nuevamente >>> ";
            cin>>*ingresado;
            val=false;
        }
        else if (cin.peek() != '\n') {
            cout<<"Entrada invalida. Debes ingresar un numero."<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Intente nuevamente >>> ";
            cin>>*ingresado;
            val=false;
        }
        else if(*ingresado!=0 && *ingresado!=1){
            cout<<"Opcion invalida. Vertical[0] u Horizontal[1] ?"<<endl;
            cout<<"Intente nuevamente >>> ";
            cin>>*ingresado;
            val=false;
        }
        else {
            val=true;
        }
    }while(!val);
}
Tablero* Jugador::getTablero(){
    return tablero;
}
void Jugador::ponerBarcos(){
    int x, y, ing;
    bool horizontal, valido=true;
    cout<<"Posicionemos tus barcos"<<endl;
    tablero->dibujar();
    cout<<"PATRULLERO (Tamanio: 1)"<<endl;
    do{
        cout<<"X >> ";
        cin>>x;
        validarIngresoXY(&x);
        cout<<"Y >> ";
        cin>>y;
        validarIngresoXY(&y);
        cout<<"Vertical[0] u Horizontal[1]?"<<endl;
        cout<<">> ";
        cin>>ing;
        validarIngresoDir(&ing);
        if(ing==0){
            horizontal=false;
        }else{
            horizontal=true;
        }
        valido = tablero->posicionarBarco(x, y, 1, 'P', horizontal); 
    }while(!valido);
    system("cls");
    tablero->dibujar();
    cout<<"PRIMER DESTRUCTOR (Tamanio: 2)"<<endl;
    do{
        cout<<"X >> ";
        cin>>x;
        validarIngresoXY(&x);
        cout<<"Y >> ";
        cin>>y;
        validarIngresoXY(&y);
        cout<<"Vertical[0] u Horizontal[1]?"<<endl;
        cout<<">> ";
        cin>>ing;
        validarIngresoDir(&ing);
        if(ing==0){
            horizontal=false;
        }else{
            horizontal=true;
        }
        valido = tablero->posicionarBarco(x, y, 2, 'D', horizontal); 
    }while(!valido);
    system("cls");
    tablero->dibujar();
    cout<<"SEGUNDO DESTRUCTOR (Tamanio: 2)"<<endl;
    do{
        cout<<"X >> ";
        cin>>x;
        validarIngresoXY(&x);
        cout<<"Y >> ";
        cin>>y;
        validarIngresoXY(&y);
        cout<<"Vertical[0] u Horizontal[1]?"<<endl;
        cout<<">> ";
        cin>>ing;
        validarIngresoDir(&ing);
        if(ing==0){
            horizontal=false;
        }else{
            horizontal=true;
        }
        valido = tablero->posicionarBarco(x, y, 2, 'D', horizontal);
    }while(!valido);
    system("cls");
    tablero->dibujar();
    cout<<"PRIMER SUBMARINO (Tamanio: 3)"<<endl;
    do{
        cout<<"X >> ";
        cin>>x;
        validarIngresoXY(&x);
        cout<<"Y >> ";
        cin>>y;
        validarIngresoXY(&y);
        cout<<"Vertical[0] u Horizontal[1]?"<<endl;
        cout<<">> ";
        cin>>ing;
        validarIngresoDir(&ing);
        if(ing==0){
            horizontal=false;
        }else{
            horizontal=true;
        }
        valido = tablero->posicionarBarco(x, y, 3, 'S', horizontal);
    }while(!valido);
    system("cls");
    tablero->dibujar();
    cout<<"SEGUNDO SUBMARINO (Tamanio: 3)"<<endl;
    do{
        cout<<"X >> ";
        cin>>x;
        validarIngresoXY(&x);
        cout<<"Y >> ";
        cin>>y;
        validarIngresoXY(&y);
        cout<<"Vertical[0] u Horizontal[1]?"<<endl;
        cout<<">> ";
        cin>>ing;
        validarIngresoDir(&ing);
        if(ing==0){
            horizontal=false;
        }else{
            horizontal=true;
        }
        valido = tablero->posicionarBarco(x, y, 3, 'S', horizontal);
    }while(!valido);
    system("cls");
    tablero->dibujar();
    cout<<"CRUCERO (Tamanio: 4)"<<endl;
    do{
        cout<<"X >> ";
        cin>>x;
        validarIngresoXY(&x);
        cout<<"Y >> ";
        cin>>y;
        validarIngresoXY(&y);
        cout<<"Vertical[0] u Horizontal[1]?"<<endl;
        cout<<">> ";
        cin>>ing;
        validarIngresoDir(&ing);
        if(ing==0){
            horizontal=false;
        }else{
            horizontal=true;
        }
        valido = tablero->posicionarBarco(x, y, 4, 'C', horizontal);
    }while(!valido);
    system("cls");
    tablero->dibujar();
    cout<<"ACORAZADO (Tamanio: 5)"<<endl;
    do{
        cout<<"X >> ";
        cin>>x;
        validarIngresoXY(&x);
        cout<<"Y >> ";
        cin>>y;
        validarIngresoXY(&y);
        cout<<"Vertical[0] u Horizontal[1]?"<<endl;
        cout<<">> ";
        cin>>ing;
        validarIngresoDir(&ing);
        if(ing==0){
            horizontal=false;
        }else{
            horizontal=true;
        }
        valido = tablero->posicionarBarco(x, y, 5, 'A', horizontal);
    }while(!valido);
    system("cls");
    tablero->dibujar();
}
void Jugador::disparar(Tablero *tableroEnemigo){
    int x, y;
    bool valido;
    do{
        cout<<"X >> ";
        cin>>x;
        validarIngresoXY(&x);
        cout<<"Y >> ";
        cin>>y;
        validarIngresoXY(&y);
        valido = tableroEnemigo->atacar(x,y);
    }while(!valido);
}
string Jugador::getNombre(){
    return nombre;
}
bool Jugador::getTurno(){
    return turno;
}
void Jugador::setTurno(bool turn){
    turno = turn;
}