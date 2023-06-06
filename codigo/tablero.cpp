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
void Tablero::posicionarBarcos(int** pos, bool* orientacion){
    int i;
    barcos[0] = new Barco(4, pos[0], orientacion[0]);
    for(i=1;i<4; i++){
        barcos[i] = new Barco(3, pos[i], orientacion[i]);
    }
    for(i=4; i<6; i++){
        barcos[i] = new Barco(2, pos[i], orientacion[i]);
    }
    barcos[6] = new Barco(1, pos[6], orientacion[6]);
}
void Tablero::atacar(int* pos){
    int i, j;
    for(i=0; i<dimension; i++){
        if(pos[0]==i){
            for(j=0; j<dimension; j++){
                if(pos[1]==j){
                    if(posiciones[i][j]=='*'){
                        cout<<"ACIERTO"<<endl;
                        posiciones[i][j]='X';
                    }else if(posiciones[i][j]=='O'){
                        cout<<"AGUA"<<endl;
                        posiciones[i][j]='0';
                    }
                }
            }  
        }
        
    }
}
