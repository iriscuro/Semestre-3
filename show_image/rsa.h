#ifndef RSA_H
#define RSA_H
#include<formulario.h>
#include<bits/stdc++.h>
#include <NTL/ZZ.h>
#include "fstream"
using namespace std;
using namespace NTL;
class rsa
{
    public:
        formulario f;
        ZZ e;
        rsa(int n_b);
        rsa(ZZ e,ZZ n);
        string ZZ_a_string(string cipherP);
        void generar_clave();
        int valor_ascci(char );
        char letra_ascci(int);
        ZZ tRestoChino(ZZ);
        ZZ get_q_inicial(ZZ P,ZZ p_or_q);
        bool esprimo(ZZ );
        bool par(int );
        ZZ phi_euler(ZZ isp,ZZ exp);
        bool Fermt_Primate(ZZ n);
        ZZ string_a_ZZ(string algo);
        string Int_a_string(int a);
        string completar(string name,int a);
        int string_a_int(string n);

        string ZZ_a_string(ZZ n);
        string cifrar(string);
        string decifrar(string);
        string cifrarA(string );
        string decifrarA(string);



        ZZ n,p,q,fi_n,d;
        int n_b;
        string alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        int max_valor;
    private:
};

#endif // RSA_H
