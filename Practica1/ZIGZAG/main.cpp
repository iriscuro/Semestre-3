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
    ZIGZAG emisor(3);
    ZIGZAG receptor(3);
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
