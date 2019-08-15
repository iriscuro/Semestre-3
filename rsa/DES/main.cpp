#include <windows.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <string>
#include <winsock2.h>
#include <fstream>
#include <bitset>
#include <sstream>

#include <iostream>
#include <string>
#include <NTL/ZZ.h>
#include <math.h>
#include <vector>
#include <ctime>

using namespace NTL;
using namespace std;

string genseed(int cambi){
    ifstream archivo;
    string texto;
    string texto2;
    string seed,seedfin;
    int w;

    archivo.open("SEED.txt",ios::in); //abrimos el archivo en modo lectura

    if(archivo.fail()){
        cout << "No se pudo abrir el archivo";
        exit(1);}

    while(!archivo.eof()){ //mientras no sea el fin del archivo
        getline(archivo,texto);
        texto2 = texto2 + texto;
    }
    while(seedfin.length()!=64){
        if(cambi%2==0){
            for(int i=0;i<3;i++)
                seed+=texto2[121+i];
            for(int i=0;i<3;i++)
                seed+=texto2[137+i];}
        else{
            for(int i=0;i<3;i++)
                seed+=texto2[137+i];
            for(int i=0;i<3;i++)
                seed+=texto2[121+i];}
        w=atoi(seed.c_str());
        bitset<16>sef(w);
        seedfin+=sef.to_string();
    }
    archivo.close();
    return seedfin;
}

ZZ modulo(ZZ a, ZZ b){
    if(a >= 0 || a%b == 0)
        return a-(a/b)*b;
    else
        return a-(a/b-1)*b;
}

ZZ Exponenciacion(ZZ a, ZZ b){
    ZZ exp,par;
    exp=1,par=2;
    ZZ x=a;
    while(b>0){
        if(modulo(b,par)!=0)
            exp=exp*x;
        x=(x*x);
        b=b/2;}
    return exp;
}

ZZ binary_to_number(string bit){
    ZZ res(0),dos(2),ind(0);
    for(unsigned int i=0; i<bit.size();i++){
        if(bit[bit.size()-i-1] == '1'){
            res += Exponenciacion(dos,ind);}
        ind++;}
    return res;
}

ZZ DES(string semilla,int nbit){
    int tabla1[56] = {
    57,49,41,33,25,17,9,
    1,58,50,42,34,26,18,
    10,2,59,51,43,35,27,
    19,11,3,60,52,44,36,
    63,55,47,39,31,23,15,
    7,62,54,46,38,30,22,
    14,6,61,53,45,37,29,
    21,13,5,28,20,12,4};

    int tabla2[48] = {
    14,17,11,24,1,5,
    3,28,15,6,21,10,
    23,19,12,4,26,8,
    16,7,27,20,13,2,
    41,52,31,37,47,55,
    30,40,51,45,33,48,
    44,49,39,56,34,53,
    46,42,50,36,29,32};

    int desplazamiento[16] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
    string perm1,perm2,C,D,CD,aleator;
    for(int i=0; i<56; i++){
        perm1 += semilla[tabla1[i]-1];
    }

    C = perm1.substr(0,28);
    D = perm1.substr(28,56);

    for(int i=0; i<16; i++){
        C += C.substr(0,desplazamiento[i]);
        C.erase(0,desplazamiento[i]);
        D += D.substr(0,desplazamiento[i]);
        D.erase(0,desplazamiento[i]);
        CD = C+D;
        for(int i=0; i<48; i++){
            perm2 += CD[tabla2[i]-1];
        }}
    for(int i=1;i<nbit+1;i++)
        aleator+=perm2[i];
    ZZ ale = binary_to_number(aleator);
    return ale;
}

int main()
{
    for(int i=0;i<30;i++){
    system("netstat -e > SEED.txt");
    string semilla=genseed(i);
    cout << DES(semilla,32)<<endl;
    Sleep(1000);}
return 0;
}
