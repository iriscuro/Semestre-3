#include <iostream>
#include <string>
#include "ZIGZAG.h"
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_CTYPE,"Spanish");
    int clave;
    string cifrado;
    ZIGZAG emisor(7);
    ZIGZAG receptor(7);
    string mensaje;
    cout <<"Mensaje: \n";
    getline(cin,mensaje);

    cout <<"Cifrado: \n";
    cifrado=emisor.cifrado(mensaje);
    cout <<cifrado<<endl;

    cout <<"Descifrado: \n";
    cout <<receptor.descifrado(cifrado)<<endl;

    return 0;
}
