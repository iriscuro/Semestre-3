#include <iostream>
#include <string>
#include "ZIGZAG.h"
#include <clocale>
#include "CESAR.h"

using namespace std;

int main()
{
    setlocale(LC_CTYPE,"Spanish");
    int clave=3;
    CESAR emisorC(clave);
    CESAR receptorC(clave);
    ZIGZAG emisorZ(clave);
    ZIGZAG receptorZ(clave);
    string mensaje;
    string cifrado;
    string descifrado;
    cout <<"Mensaje: \n";
    getline(cin,mensaje);

    cout <<"Cifrado cesar: ";
    cifrado=emisorC.cifrado(mensaje);
    cout <<cifrado<<endl;

     cout <<"Cifrado zigzag: ";
    cifrado=emisorZ.cifrado(cifrado);
    cout <<cifrado<<endl;

    cout <<"Descifrado zigzag: ";
    descifrado=receptorZ.descifrado(cifrado);
    cout <<descifrado<<endl;


    cout <<"Descifrado cesar: ";
    descifrado=receptorC.descifrado(descifrado);
    cout <<descifrado<<endl;


    return 0;
}
