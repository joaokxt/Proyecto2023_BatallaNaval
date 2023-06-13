#ifndef CODIGO_BARCO_H
#define CODIGO_BARCO_H
#include <string>
class Barco{
private:
    char tipo;
    int tamanio;
    int vida;
    int posX;
    int posY;
    bool esHorizontal;
    bool hundido;
public:
    Barco();
    Barco(char type, int x, int y, bool isHorizontal);
    ~Barco();
    char getTipo();
    int getTamanio();
    int getVida();
    bool getHundido();
    bool consultarPosicion(int x, int y);
    void acierto();
    void resumen();
};

#endif