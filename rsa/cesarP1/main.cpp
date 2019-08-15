#include <iostream>
#include<bits/stdc++.h>
#include <NTL/ZZ.h>
#include "rsa.h"
#include <sstream>
#include "formula.h"
using namespace std;
using namespace NTL;

int main(){
    ZZ e(3);
    ZZ n(4);
    rsa emisor(8);
    //rsa receptor(8);
    //rsa emisor1(e,n);
    //rsa receptor1(e,n);
    string a,b,c,d;
    a=emisor.cifrar("montecristo");
    cout<<a<<endl;
     emisor.mostrar();
    //b=receptor.decifrar(a);
    //cout<<b<<endl;

}
