#include <iostream>
#include "tablero.h"
using namespace std;

Tablero::Tablero(){
    dimension = 9;
    posiciones = new char*[9];
    for(int i=0; i<dimension; i++){
        posiciones[i] = new char(9);
    }
}
Tablero::Tablero(int dimension){
    dimension = dimension;
    posiciones = new char*[dimension];
    for(int i=0; i<dimension; i++){
        posiciones[i] = new char(dimension);
    }
    cantBarcos = 0;
}
Tablero::~Tablero(){
    int i;
    for(i=0; i<dimension; i++){
        delete posiciones[i];
    }
    delete posiciones;
    for(i=0; i<cantBarcos; i++){
        delete barcos[i];
    }
}
void Tablero::poblar(){
    for(int i=0; i<dimension; i++){
        for(int j=0; j<dimension; j++){
            posiciones[i][j] = 'O';
        }
    }
}
void Tablero::dibujar(){
    int i, j;
    cout<<"  ";
    for(i=0; i<dimension; i++){
        cout<<i<<" ";
    }
    cout<<endl;
    for(i=0; i<dimension; i++){
        cout<<i<<" ";
        for(j=0; j<dimension; j++){
            cout<<posiciones[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool Tablero::posicionarBarco(int x, int y, int tamanio, char tipo, bool esHorizontal){
    int i, j;
    if(esHorizontal){
        if(x+tamanio<dimension){
            barcos[cantBarcos]=new Barco(tipo, x, y, esHorizontal);
            cantBarcos++;
            for(i=x; i<tamanio; i++){
                posiciones[y][i] = tipo;
            }
            return true;
        }else{
            cout<<"Posicion invalida, el barco esta fuera de alcance!"<<endl;
            return false;
        }
    } else {
        if(y+tamanio<dimension){
            barcos[cantBarcos]=new Barco(tipo, x, y, esHorizontal);
            cantBarcos++;
            for(i=y; i<tamanio; i++){
                posiciones[i][x] = tipo;
            }
            return true;
        }else{
            cout<<"Posicion invalida, el barco esta fuera de alcance!"<<endl;
            return false;
        }
    }
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
                    posiciones[x][y]=='X';
                    barcos[i]->acierto();
                    if(barcos[i]->getVida()==0){
                        cout<<barcos[i]->getTipo()<<" hundido!"<<endl;
                    }
                    return true;
                }
            }
        }
    }else{
        cout<<"Disparo fuera de alcance!"<<endl;
        return false;
    }
    return false;
}
