#include <iostream>
#include <string>
#include "barco.h"
using namespace std;

Barco::Barco(){
    tipo = 'O';
    nombre = "Inexistente";
    tamanio = 0;
    vida = 0;
    posX = -1;
    posY = -1;
    esHorizontal = true;
    hundido = true;
}
Barco::Barco(char type, int x, int y, bool isHorizontal){
    tipo = type;
    if(tipo == 'P'){//Patrullero
        tamanio = 1;
        nombre = "Patrullero";
    }else if(tipo == 'D'){//Destructor
        tamanio = 2;
        nombre = "Destructor";
    }else if(tipo == 'S'){//Submarino
        tamanio = 3;
        nombre = "Submarino";
    }else if(tipo == 'C'){//Crucero
        tamanio = 3;
        nombre = "Crucero";
    }else if(tipo == 'A'){//Acorazado
        tamanio = 4;
        nombre = "Acorazado";
    }
    vida = tamanio;
    posX = x;
    posY = y;
    esHorizontal = isHorizontal;
    hundido = false;
}
Barco::~Barco(){

}
char Barco::getTipo(){
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
void Barco::acierto(){
    vida--;
    cout<<"ACIERTO!"<<endl;
    cout<<"Has acertado un "<<tipo<<"! Vida: "<<vida<<endl;
    if(vida==0){
        hundido=true;
        cout<<tipo<<" hundido!"<<endl;
    }
}
void Barco::resumen(){
    cout<<nombre<<" ";
    if(hundido){
        cout<<"HUNDIDO"<<endl;
    }else{
        cout<<"OPERANTE || Vida: "<<vida<<endl;
    }
}