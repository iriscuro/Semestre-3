#ifndef CESAR_H
#define CESAR_H
#include <string>

using namespace std;

class CESAR
{
    public:
        CESAR(int num);
        CESAR();
        int tam;
        int moduloR(int);
        int modulo(int);
        string cifrado(string );
        string descifrado(string);
        string alfabeto;
    private:
        int clave;
};

#endif // CESAR_H
