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
    bool valido=true;

    cout<<"-=-=-=-=-=| UN JUGADOR |-=-=-=-=-="<<endl;
    cout<<"Aca vas a jugar una partida contra la computadora."<<endl;
    cout<<"Primero, como queres que te llame?"<<endl;
    cout<<">>> ";
    cin>>name;
    cout<<"Perfecto, "<<name<<"!"<<endl;
    cout<<"Ahora, deci de que tamano queres que sea tu tablero."<<endl;
    cout<<"Tiene que ser de por lo menos 9x9!"<<endl;
    cout<<">>> ";
    while(!valido){
        valido = true;
        try{
            cin>>dimension;
            if(cin.fail()){
                throw "NaN";
            }
            if(dimension<9){
                throw "Limite";
            }
        } catch (string error){
            valido = false;
            if(error=="NaN"){
                cout<<"Se debe ingresar un numero!"<<endl;
            }
            if(error=="Limite"){
                cout<<"El numero no puede ser menor a 9!"<<endl;
            }
        } 
    }
    jugador1 = new Jugador(name, dimension);
    jugador2 = new Bot(dimension);

    while(true){
        jugador1->getTablero()->poblar();
        jugador2->getTablero()->poblar();
    }
    
    

}

void dosJugadores(){

}

void reglas(){

}

int main(){
    cout<<"-=-=-=-=-=| BATALLA NAVAL |-=-=-=-=-="<<endl;
    cout<<"1. UN JUGADOR"<<endl<<endl;
    cout<<"2. DOS JUGADORES"<<endl<<endl;
    cout<<"3. REGLAS"<<endl<<endl;
    cout<<"X. SALIR"<<endl;
    cout<<">>> ";
    cin>>opcion;
    num = (int)opcion;
    switch(num){
        case 1:
            unJugador();
            break;
        case 2:
            dosJugadores();
            break;
        case 3:
            reglas();
            break;
        default:
            return 0;
    }
    
}