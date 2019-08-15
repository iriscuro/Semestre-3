#ifndef ZIGZAG_H
#define ZIGZAG_H
#include <string>

using namespace std;

class ZIGZAG
{
    public:
        ZIGZAG();
        ZIGZAG(int);
        //int tam;
        int modulo(int,int);
        string cifrado(string );
        string descifrado(string);
        string mensaje;
        //string alfabeto;

    private:
        int clave;
};

#endif // ZIGZAG_H

