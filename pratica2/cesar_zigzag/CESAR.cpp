#include "CESAR.h"
#include <iostream>

using namespace std;

CESAR::CESAR(){
    this->clave = 3;
    alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-";
    tam=alfabeto.size();
}
CESAR::CESAR(int num){
    this->clave = num;
    alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-";
    tam=alfabeto.size();
}
int CESAR:: moduloR(int a){//numero , modulo
    int m;
    if(a<0){
      m=a-(a/tam-1)*tam;
      if(m==tam)
        m=0;
    }
    else{
       m=a-(a/tam)*tam;
    }
    //cout<<"m: "<< m<<endl;;
    return m;
}
int CESAR:: modulo(int a){//numero , modulo
    int c;
    c=a-tam*(a/tam);
    if(c<0)
        c=c+tam;
    //cout<<"m: "<< c<<endl;;
    return c;
}
string CESAR::cifrado(string palabra)
{
    int i=0;
    int largo=palabra.size();
    int pos=0;
    string cor;
    while(i<largo)
    {
        cor=palabra[i];
        pos=alfabeto.find(cor);
        palabra[i]=alfabeto[pos+clave];
        //cout <<"letra c "<<cor<<endl;
        //cout <<"pos "<<pos<<endl;
        //cout <<"letra a "<<palabra[i]<<endl;
        if(pos+clave> alfabeto.size()){
             palabra[i]=alfabeto[modulo(pos+clave)];
             //cout <<"letra a"<<palabra[i]<<endl;
        }

        i++;
    }
    return palabra;
}
string CESAR::descifrado(string palabra)
{
    int largo=palabra.size();
    int i=0;
    int pos=0;
    string cor;
    while(i<largo)
    {
        cor=palabra[i];
        pos=alfabeto.find(cor);
        palabra[i]=alfabeto[pos-clave];
        //cout <<"letra c "<<cor<<endl;
        //cout <<"pos "<<pos<<endl;
        //cout <<"letra a "<<palabra[i]<<endl;
        if(pos-clave<0){
            palabra[i]=alfabeto[modulo(pos-clave)];
            //cout <<"letra a "<<palabra[i]<<endl;
        }

        i++;
    }
    return palabra;
}
