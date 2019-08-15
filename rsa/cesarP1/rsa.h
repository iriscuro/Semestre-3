#ifndef RSA_H
#define RSA_H
#include "formula.h"
#include"formula.h"
#include <NTL/ZZ.h>
using namespace NTL;


class rsa
{
    public:
        formula f;
        vector<string>guardar;
        rsa(int n_b);
        rsa(ZZ A,ZZ b);
        string ZZ_a_string(string cipherP);
        void generar_clave();
        ZZ string_a_ZZ(string algo);
        string ZZ_a_string(ZZ n);
        string cifrar(string);
        string decifrar(string);
        void mostrar();
        virtual ~rsa();

    protected:
        ZZ e,n,p,q,fi_n,d;
        int n_b;
        string alfabeto="abcdefghijklmnopqrstuvwxyzABCDEFGHIFKLMNOPQRSTUVWXYZ .,;";

    private:
};

#endif // RSA_H
