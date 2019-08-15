#include "ZIGZAG.h"
#include <iostream>

using namespace std;

ZIGZAG::ZIGZAG()
{
    this->clave=3;
    //alfabeto = "abcdefghijklmnñopqrstuvwxyz ";
    //tam=alfabeto.size();
}
ZIGZAG::ZIGZAG(int num){
    int esp=2;
    this->clave = num;
    if(clave>2){
        for(int i=0;i<clave;i++)
            esp+=2;
        esp=2;
        }
}

int ZIGZAG:: modulo(int a,int tam){//numero , modulo
    int c;
    c=a-tam*(a/tam);
    if(c<0)
        c=c+tam;
    //cout<<"m: "<< c<<endl;;
    return c;
}
string ZIGZAG::cifrado(string palabra)
{
    mensaje=palabra;
    int tam=palabra.size();
    //cout<<tam<<endl;
    int esp=4;
    int i=0;
    int p=0;
    int pos=0;
    while(p<clave){
        pos=p;
        while(pos<tam){
            //cout<<mensaje<<endl;
            mensaje[i]=palabra[pos];
            //cout<<mensaje<<endl;
            i++;
            if(p==0 ||p==2)
                pos+=esp;
            if(p==1)
                pos+=2;
        }
        p++;
    }

    return mensaje;
}
string ZIGZAG::descifrado(string palabra)
{
    mensaje=palabra;
    int tam=palabra.size();
    int esp=4;
    int i=0;
    int p=0;
    int pos=0;
    while(p<clave){
        pos=p;
        while(pos<tam){
            //cout<<mensaje<<endl;
            mensaje[pos]=palabra[i];
            //cout<<mensaje<<endl;
            i++;
            if(p==0 ||p==2){
                pos+=esp;
            }

            if(p==1){
                pos+=2;
            }

        }
        p++;
    }

    return mensaje;
}
