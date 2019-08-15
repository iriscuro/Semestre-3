#include <iostream>
#include <string>
#include "cesar.h"

using namespace std;

int main()
{
    int clave;
    string cifrado;
    cesar emisor(3);
    cesar receptor(3);
    string mensaje;
    cout <<"Mensaje: \n";
    getline(cin,mensaje);

    cout <<"Cifrado: ";
    cifrado=emisor.cifrado(mensaje);
    cout <<cifrado<<endl;

    cout <<"Descifrado: ";
    cout <<receptor.descifrado(cifrado)<<endl;

    return 0;
}
