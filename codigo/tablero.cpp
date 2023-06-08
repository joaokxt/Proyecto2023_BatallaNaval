#include <iostream>
#include "tablero.h"
using namespace std;

Tablero::Tablero(){
    dimension = 9;
    posiciones = new char*[9];
    for(int i=0; i<dimension; i++){
        posiciones[i] = new char[9];
    }
    barcos = new Barco*[7];
}
Tablero::Tablero(int dimension){
    dimension = dimension;
    posiciones = new char*[dimension];
    for(int i=0; i<dimension; i++){
        posiciones[i] = new char[dimension];
    }
    barcos = new Barco*[7];
}
Tablero::~Tablero(){
    int i;
    for(i=0; i<dimension; i++){
        delete posiciones[i];
    }
    delete posiciones;
    delete barcos;
}
void Tablero::poblarTablero(){
    for(int i=0; i<dimension; i++){
        for(int j=0; j<dimension; j++){
            posiciones[i][j] = 'O';
        }
    }
}
bool Tablero::posicionarBarco(int x, int y, int tamanio, bool esHorizontal){
    int i, j;
    char identificador;
    switch(tamanio){
        case 1:
            identificador = 'P';
            break;
        case 2:
            identificador = 'D';
            break;
        case 3:
            identificador = 'C';
            break;
        case 4:
            identificador = 'B';
            break;
    }
    if(esHorizontal){
        if(x+tamanio<dimension){
            for(i=x; i<tamanio; i++){
                posiciones[i][y] = identificador;
            }
            return true;
        }else{
            cout<<"Posicion invalida, el barco esta fuera de alcance!"<<endl;
            return false;
        }
    } else {
        if(y+tamanio<dimension){
            for(i=y; i<tamanio; i++){
                posiciones[x][i] = identificador;
            }
            return true;
        }else{
            cout<<"Posicion invalida, el barco esta fuera de alcance!"<<endl;
            return false;
        }
    }
    //construir barcos
}
bool Tablero::atacar(int x, int y){
    if(x<dimension && y<dimension){
        if(posiciones[x][y]=='O'){
            cout<<"AGUA!"<<endl;
            posiciones[x][y]=='0';
        } else if(posiciones[x][y]=='X' || posiciones[x][y]=='0'){
            cout<<"Ya has disparado ahi!"<<endl;
            return false;
        } else {
            for(int i=0; i<7; i++){
                if(barcos[i]->consultarPosicion(x,y)){
                    cout<<"ACIERTO!"<<endl;
                    cout<<"Has acertado un "<<barcos[i]->getTipo()<<"! Vida: "<<barcos[i]->getTipo()<<endl;
                    return true;
                }
            }
        }
    }else{
        cout<<"Disparo fuera de alcance!"<<endl;
        return false;
    }
}
