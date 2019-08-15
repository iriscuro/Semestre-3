#include "ZIGZAG.h"
#include <iostream>

using namespace std;

ZIGZAG::ZIGZAG()
{
    this->clave=3;
    espac=4;

}
ZIGZAG::ZIGZAG(int num){
    this->clave = num;
    espac=espacio();

}

int ZIGZAG:: modulo(int a,int tam){//numero , modulo
    int c;
    c=a-tam*(a/tam);
    if(c<0)
        c=c+tam;
    return c;
}
int ZIGZAG:: espacio(){
    int esp=0;

    if(clave>1){
        for(int i=1;i<clave;i++)
            esp+=2;
        return esp;
    }
    return esp;
}
string ZIGZAG::cifrado(string mensaje)
{
    string palabra1;
    int tam=mensaje.size();
    int esp=espacio();
    int p=0;
    int pos=0;
    int tem=esp;
    while(p<clave){
        pos=p;
        int temp1;
        int temp2;
        temp1 = espac- pos * 2;
        temp2 = espac - temp1;
        while(pos<tam){
            palabra1 += mensaje[pos];
            if(p==0 || p == clave-1){
                pos+=tem;
            }
            else{
                pos+=temp1;//ACTUALIZO ESPACIO recien actual. + el nuevo espaciado
                swap(temp1,temp2);
            }
        }
        esp-=2;
        p++;
    }
    return palabra1;
}
string ZIGZAG::descifrado(string mensaje)
{
    string palabra=mensaje;
    int tam=mensaje.size();
    int esp=espacio();
    int p=0;
    int i = 0;
    int pos=0;
    int tem=esp;
    while(p<clave){
        pos=p;
        int temp1;
        int temp2;
        temp1 = espac- pos * 2;
        temp2 = espac - temp1;
        while(pos<tam){
            palabra[pos] = mensaje[i];
            if(p==0 || p == clave-1){
                pos+=tem;
            }
            else{
                pos+=temp1;//ACTUALIZO ESPACIO recien actual. + el nuevo espaciado
                swap(temp1,temp2);
            }
            i++;
        }
        esp-=2;
        p++;
    }
    return palabra;
}
