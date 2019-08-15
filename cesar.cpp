#include "cesar.h"
#include <iostream>

using namespace std;

cesar::cesar(){
    this->clave = 3;
}
cesar::cesar(int num){
    this->clave = num;

}
int cesar:: moduloR(int a){//numero , modulo
    int m;
    if(a<0){
      m=a-(a/26-1)*26;
      if(m==26)
        m=0;
    }
    else{
       m=a-(a/26)*26;
    }
    //cout<<"m: "<< m<<endl;;
    return m;
}
int cesar:: modulo(int a){//numero , modulo
    int c;
    c=a-26*(a/26);
    if(c<0)
        c=c+26;
    //cout<<"m: "<< c<<endl;;
    return c;
}
string cesar::cifrado(string palabra)
{
    int i=0;
    while(palabra[i]!='\0')
    {
        palabra[i] = palabra[i]+ clave;
        //cout <<"letra "<<(int)palabra[i]<<endl;
        //cout <<"letra a"<<palabra[i]<<endl;
        if(palabra[i]-97 > alfabeto.size())
            palabra[i]=modulo(palabra[i]-97)+97;
        //cout <<"letra a"<<palabra[i]<<endl;
        i++;
    }
    return palabra;
}
string cesar::descifrado(string palabra)
{
    int i=0;
    int aux;
    while(palabra[i]!='\0')
    {
        palabra[i]=palabra[i]-clave;
        //cout <<"letra "<<(int)palabra[i]<<endl;
        //aux=palabra[i]-97;
        //palabra[i]=palabra[i]-97;
        //cout <<"letra a"<<aux<<endl;
        if(palabra[i]> alfabeto.size()){
            palabra[i]=modulo(palabra[i]-97)+97;
            //cout <<"letra a"<<palabra[i]<<endl;
        }

        i++;
    }
    return palabra;
}
