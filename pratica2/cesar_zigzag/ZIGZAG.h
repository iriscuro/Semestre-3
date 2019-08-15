#ifndef ZIGZAG_H
#define ZIGZAG_H
#include <string>

using namespace std;

class ZIGZAG
{
    public:
        ZIGZAG();
        ZIGZAG(int);

        int espac;
        int modulo(int,int);
        string cifrado(string );
        int espacio();
        string descifrado(string);
        string mensaje;

    private:
        int clave;
};

#endif // ZIGZAG_H#ifndef ZIGZAG_H

