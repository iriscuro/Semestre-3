#include <iostream>
#include <cstring>
#include <cstdlib>

void invertidoS(){

}
using namespace std;
int main(){
    string cadena;
    cout <<" texto normal: \t";
    cin >>cadena;
//string cadena = "Hola mundo!";
    string aux_cadena = "";
    int t=cadena.size();
    for (int i = t; i >=0 ; i--)
     aux_cadena += cadena[i];

    cout<<"El texto normal es: "<<cadena<<endl;
    cout<<"El texto invertido es: "<<aux_cadena<<endl;
    return 0;
}


