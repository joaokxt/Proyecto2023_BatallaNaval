#include <iostream>
#include <string>
#include "barco.h"
using namespace std;

Barco::Barco(){
    
}
Barco::Barco(string type, int x, int y, bool isHorizontal){
    tipo = type;
    if(tipo == "Patrullero"){
        tamanio = 1;
    }else if(tipo == "Destructor"){
        tamanio = 2;
    }else if(tipo == "Submarino"){
        tamanio = 3;
    }else if(tipo == "Crcuero"){
        tamanio = 3;
    }else if(tipo == "Acorazado"){
        tamanio = 4;
    }
    vida = tamanio;
    posX = x;
    posY = y;
    esHorizontal = isHorizontal;
    hundido = false;
}
Barco::~Barco(){

}
string Barco::getTipo(){
    return tipo;
}
int Barco::getTamanio(){
    return tamanio;
}
int Barco::getVida(){
    return vida;
}
bool Barco::getHundido(){
    return hundido;
}
bool Barco::consultarPosicion(int x, int y){
    int i;
    if(esHorizontal){
        for(i=0; i<tamanio; i++){
            if(posX+i == x && posY == y){
                return true;
            }
        }
        return false;
    }else{
        for(i=0; i<tamanio; i++){
            if(posX == x && posY+i == y){
                return true;
            }
        }
        return false;
    }
}