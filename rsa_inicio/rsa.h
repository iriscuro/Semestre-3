#ifndef RSA_H
#define RSA_H
#include <iostream>
#include <vector>

using namespace std;

class rsa
{
    public:
        int e;     // clave publica
		string alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIFKLMNOPQRSTUVWXYZ .,;";
		int N;
		int phi_N;

		rsa(); // RECEPTOR
		rsa(int e, int N); // EMISOR

        int generar_clave_pub(int phi_N);
		int generar_clave_priv(int e,int N);

        int cifrar(string mensaje);
        string descifrar(int cifrado);



    private:
        int p,q;  // numeros primos
		int d;    // clave privada
};

#endif // RSA_H
