#ifndef CESAR_H
#define CESAR_H
#include <string>
using namespace std;
class cesar
{
    public:
        cesar(int num);
        cesar();
        int moduloR(int);
        int modulo(int);
        string cifrado(string );
        string descifrado(string);
        string alfabeto = "abcdefghijklmn�opqrstuvwxyz";

    private:
        int clave;

};

#endif // CESAR_H
