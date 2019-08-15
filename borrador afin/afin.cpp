#include "afin.h"
#include "funciones.h"
#include <iostream>

using namespace std;

afin::afin()
{
    //alfabeto = "abcdefghijklmnopqrstuvwxyz ";
    //alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789-";
    alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-";

    tam=alfabeto.size();
    this -> clave_a = generar_clave_a(tam);
    this -> clave_b = generar_clave_b(tam);

    cout<<"clave_a: "<<clave_a<<endl;
    cout<<"clave_b: "<<clave_b<<endl;
}
afin::afin(int a, int b){

    //alfabeto = "abcdefghijklmnopqrstuvwxyz ";
    //alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789-";
    alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-";

    tam=alfabeto.size();
    this -> clave_x=la_inversa(a,tam,tam);
    cout<<"clave_x: "<<clave_x<<endl;
    if(b>tam){
            b=mod(b,tam);
    }
    this -> clave_b =b;
}

string afin::cifrar(string mensaje)
{

    for(int i=0;i<mensaje.size();i++)
    {
        int found = alfabeto.find(mensaje[i]);
        int cambio=(found*clave_a)+clave_b;
        cambio=mod(cambio,tam);
        mensaje[i]= alfabeto[cambio];
    }

    return mensaje;
}
string afin::descifrar(string mensaje)
{
    for(int i=0;i<mensaje.size();i++)
    {
        int found = alfabeto.find(mensaje[i]);
        int cambio=clave_x*(found-clave_b);
        cambio=mod(cambio,tam);
        mensaje[i]= alfabeto[cambio];
    }

    return mensaje;
}
