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
Tablero::Tablero(int dim){
    dimension = dim;
    try
    {
        posiciones = new char*[dim];
    }
    catch (exception& e)
    {
        cout << "Excepcion: " << e.what() << endl;
    }
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
            posiciones[i][j] = '*';
        }
    }
}
void Tablero::dibujar(){
    int i, j;
    cout<<"  ";
    for(i=0; i<dimension; i++){
        cout<<i<<" ";
    }
    cout<<"X"<<endl;
    for(i=0; i<dimension; i++){
        cout<<i<<" ";
        for(j=0; j<dimension; j++){
            if(j<10){
                cout<<posiciones[i][j]<<" ";
            }else{
                cout<<posiciones[i][j]<<"  ";
            }
        }
        cout<<endl;
    }
    cout<<"Y"<<endl;
}
void Tablero::enemigoDibujar(){
    int i, j;
    cout<<"  ";
    for(i=0; i<dimension; i++){
        cout<<i<<" ";
    }
    cout<<"X"<<endl;
    for(i=0; i<dimension; i++){
        cout<<i<<" ";
        for(j=0; j<dimension; j++){
            if(posiciones[i][j]=='0'|| posiciones[i][j]=='X' || posiciones[i][j]=='*'){
                cout<<posiciones[i][j]<<" ";
            }else{
                cout<<"* ";
            }
        }
        cout<<endl;
    }
    cout<<"Y"<<endl;
}
bool Tablero::posicionarBarco(int x, int y, int tamanio, char tipo, bool esHorizontal){
    int i, j;
    if(esHorizontal){
        if(x+tamanio<=dimension){
            for(i=x; i<x+tamanio; i++){
                if(posiciones[y][i]!='*'){
                    cout<<"El barco se sobrepone con otro!"<<endl;
                    return false;
                }  
            }
            for(i=x; i<x+tamanio; i++){
                posiciones[y][i] = tipo;
            }
            barcos[cantBarcos]=new Barco(tipo, x, y, esHorizontal);
            cantBarcos++;
            return true;
        }else{
            cout<<"Posicion invalida, el barco esta fuera de alcance!"<<endl;
            return false;
        }
    } else {
        if(y+tamanio<=dimension){
            for(i=y; i<y+tamanio; i++){
                if(posiciones[i][x]!='*'){
                    cout<<"El barco se sobrepone con otro!"<<endl;
                    return false;
                }
            }
            for(i=y; i<y+tamanio; i++){
                posiciones[i][x] = tipo;
            }
            barcos[cantBarcos]=new Barco(tipo, x, y, esHorizontal);
            cantBarcos++;
            return true;
        }else{
            cout<<"Posicion invalida, el barco esta fuera de alcance!"<<endl;
            return false;
        }
    }
}
bool Tablero::atacar(int x, int y){
    if(x<dimension && y<dimension){
        if(posiciones[y][x]=='*'){
            cout<<"AGUA!"<<endl;
            posiciones[y][x]='0';
            return true;
        } else if(posiciones[y][x]=='X' || posiciones[y][x]=='0'){
            cout<<"Ya has disparado ahi!"<<endl;
            return false;
        } else {
            for(int i=0; i<7; i++){
                if(barcos[i]->consultarPosicion(x,y)){
                    posiciones[y][x]='X';
                    barcos[i]->acierto();
                    return true;
                }
            }
        }
    }else{
        cout<<"Disparo fuera de alcance!"<<endl;
        return false;
    }
}
bool Tablero::flotaOperante(){
    int i, j=0;
    for(i=0; i<7; i++){
        if(barcos[i]->getHundido()==true){
            j++;
        }
    }
    if(j==7){
        return false;
    }
    return true;
}
int Tablero::getDimension(){
    return dimension;
}
