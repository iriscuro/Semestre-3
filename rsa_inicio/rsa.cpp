#include "rsa.h"
#include "funciones.h"
#include <iostream>

using namespace std;
rsa::rsa() // receptor
{
    this->p=17;
    this->q=43;
    N=p*q;
    phi_N=(p-1)*(q-1);
    e=generar_clave_pub(phi_N);
    //e=101;
    this->d=generar_clave_priv(e,phi_N);
    cout<<"<K-priv, phi_N> "<<"<"<<d<<", "<<phi_N<<">"<<endl;
    cout<<" < K-pub, N > "<<" < "<<e<<" , "<<N<<" > "<<endl;

}
rsa::rsa(int e ,int N) // emisor
{
    this->e=e;
    this->N=N;
}
int rsa::generar_clave_pub(int phi_N){

    int a = 2; // el menor primo
    int i = 0;
    while (euclides(a,phi_N)!=1){
        a=ramdom(phi_N,i);
        i++;
    }
    if(a>=phi_N){mod(a,phi_N);}
    return a;
}
int rsa::generar_clave_priv(int e,int N){
    return la_inversa_modular(e,N,N);
}
int rsa::cifrar(string mensaje)
{
    int cifrado;
    int found = alfabeto.find(mensaje);
    cout <<"found: " <<found<<endl;
    cifrado=exp_modular(found,e,N);
    cout<<"\n Cifrado: "<<cifrado<<endl;
    return cifrado;
}

string rsa::descifrar(int cifrado)
{
    string descifrado;
    int original= exp_modular(cifrado,d,N);
    cout<< "original: "<<original<<endl;
    descifrado=alfabeto[original];
    cout<<"\n Descifrado: "<<descifrado<<endl;
    return descifrado;
}
