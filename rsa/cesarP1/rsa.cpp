#include "rsa.h"
#include "rsa.h"
#include"formula.h"
#include <NTL/ZZ.h>
using namespace NTL;
using namespace std;
rsa::rsa(int n_b)
{
    this->n_b=n_b;
    generar_clave();

}

rsa::~rsa()
{
    //dtor
}
rsa::rsa(ZZ e,ZZ n){
    this->e=e;
    this->n=n;
}
string rsa::ZZ_a_string(ZZ n)
{
    stringstream  ss;
    ss<<n;
    string  numero;
    ss>>numero;
return numero;
}
ZZ rsa::string_a_ZZ(string algo)///verdadero funciona a
{   stringstream sst(algo);
    ZZ Num;
    sst>>Num;
 return Num;
}


void rsa::generar_clave(){
    this->p=GenPrime_ZZ(n_b);
    this->q=GenPrime_ZZ(n_b);
    this->n=p*q;
    this->fi_n=(p-1)*(q-1);
    this->e=f.generar_aleatorio(n_b);
    while(f.euclides(e,fi_n)!=1){
        this->e=f.generar_aleatorio(n_b);
    }
    cout<<"\n [K-pub,N]  <"<<e<<" , "<<n<<" >"<<endl;
}
string rsa::cifrar(string m){
    string cipher;
    ZZ cipherp,pos;
    for(int i=0;i<m.size();i++){
    int posi=alfabeto.find(m[i]);
    pos=conv<ZZ>(posi);
    cipherp=f.exp(pos,e,n);
    cipher=ZZ_a_string(cipherp);
    guardar.push_back(cipher);
    }
    return cipher;
}
string rsa::decifrar(string cipher){
    this->d=f.mod(f.eExtendido(e,fi_n),fi_n);
    string mensaje;
    ZZ mensajeP;
    for(int i=0;i<cipher.size();i++){
    mensajeP=f.exp(string_a_ZZ(cipher),d,n);

    mensaje=alfabeto[f.modulo(conv<int>(mensajeP),alfabeto.size())];
    }
    return mensaje;

}
void rsa::mostrar(){

    for(int i=0;i<guardar.size();i++){
        cout<<"num: "<<guardar[i] <<" ->"<< decifrar(guardar[i])<<endl;
    }
}
