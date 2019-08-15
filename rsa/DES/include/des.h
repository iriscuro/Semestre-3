#ifndef DES_H
#define DES_H

#include<bits/stdc++.h>
#include"matedes.h"
using namespace std;
struct hexadecimal
{
 vector<string> hexadecimal={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
 int find(string n)
 {
   for(int i=0;i<hexadecimal.size();i++)
   {
      if(hexadecimal[i]==n)return i;
   }
 }
};

class des
{
    public:
        des(string);
        void generador_clave(string);
         ZZ  aleatorio();
         string permutacion1(string k);
         string permutacion2(string k);
        string permutacionIP(string);
        string permutacion_expan(string);
        string corrimiento_Iz(string numero, int x);
        string corrimiento_der(string numero, int x);
        string f(string R,string K);
        string cifrar(string mensaje);//mensaje de 64 bits
        ZZ bin_to_ZZ(string bin);///
        string XOR(string A,string B);


    protected:
       /*vector<int> tablero1;
       vector<int> tablero2;*/
       vector<int>  ronda;
    public:
       vector<string>  key;
       hexadecimal  hexa;


    private:
};

des::des(string n)
{
    //tablero1={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
    //tablero2={14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
    ronda={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

    generador_clave(n);


}


void des::generador_clave(string s)
{
int t;
string k,ax;
    for(int i=0;i<s.size();i++)
        {
            ax=s.at(i);
            t=hexa.find(ax);
           k=k+num_en_base(t,4);
        }
string K;
    K=permutacion1(k);

    string I1,D1,I,D,concatenarID,keys;

    I1=K.substr(0,K.size()/2);
    D1=K.substr(K.size()/2,K.size());

    for(int i=0;i<16;i++)
        { I=corrimiento_Iz(I1,ronda[i]);
          I1=I;
          D=corrimiento_der(D1,ronda[i]);
          D1=D;
          concatenarID=I+D;
          keys=permutacion2(concatenarID);
          key.push_back(keys);}
}

ZZ des::aleatorio()
{
   ZZ p;
   for(int i=0;i<16;i++)
   {
        p=p+bin_to_ZZ(key[i]);
   }
   return p;
}
string des::permutacionIP(string k)
{  vector<int> IP;
       IP={58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,13,5,63,55,47,39,31,23,15,7};
   string K;
    for(int i=0;i<IP.size();i++)
    {
     K=K+k[IP[i]-1];
    }
return K;
}
string des::permutacion_expan(string numero)
{

vector<int>  expancion;
expancion={32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1};
string resultado;
 for(int i=0;i<expancion.size();i++)
 {
    resultado=resultado+numero[expancion[i]-1];
 }
 return resultado;

}
string des::f(string R,string k1)
{
int box1[16][4]={{14,0,4,15},{4,15,1,12},{13,7,14,8},{1,4,8,2},{2,14,13,4},{15,2,6,9},{11,13,2,1},{8,1,11,7},{3,10,15,5},{10,6,12,11},{6,12,9,3},{12,11,7,14},{5,9,3,10},{9,5,10,0},{0,3,5,6},{7,8,0,13}};

int box2[16][4]={{15,3,0,13},{1,13,14,8},{8,4,7,10},{14,7,11,1},{6,15,10,3},{11,2,4,15},{3,8,13,4},{4,14,1,2},{9,12,5,11},{7,0,8,6},{2,1,12,7},{13,10,6,12},{12,6,9,0},{0,9,3,5},{5,11,2,14},{10,5,15,9}};
int box3[16][4]={{10,13,13,1},{0,7,6,10},{9,0,4,13},{14,9,9,0},{6,3,8,6},{3,4,15,9},{15,6,3,8},{5,10,0,7},{1,2,11,4},{13,8,1,15},{12,5,2,14},{7,14,12,3},{11,12,5,11},{4,11,10,5},{2,15,14,2},{8,1,7,12}};
int box4[16][4]={{7,13,10,3},{13,8,6,15},{14,11,9,0},{3,5,0,6},{0,6,12,10},{6,15,11,1},{9,0,7,13},{10,3,13,8},{1,4,15,9},{2,7,1,4},{8,2,3,5},{5,12,14,11},{11,1,5,12},{12,10,2,7},{4,14,8,2},{15,9,4,14}};
int box5[16][4]={{2,14,4,11},{12,11,2,8},{4,2,1,12},{1,12,11,7},{7,4,10,1},{10,7,13,14},{11,13,7,2},{6,1,8,13},{8,5,15,6},{5,0,9,15},{3,15,12,0},{15,10,5,9},{13,3,6,10},{0,9,3,4},{14,8,0,5},{9,6,14,3}};
int box6[16][4]={{12,101,9,4},{1,15,14,3},{10,4,15,2},{15,2,5,12},{9,7,2,9},{2,12,8,5},{6,9,12,15},{8,5,3,10},{0,6,7,11},{13,1,0,14},{3,13,4,1},{4,14,10,7},{14,0,1,6},{7,11,13,0},{5,3,11,8},{11,8,6,13}};
int box7[16][4]={{4,13,1,6},{11,0,4,11},{2,11,11,13},{14,7,13,8},{15,4,12,1},{0,9,3,4},{8,1,7,10},{13,10,14,7},{3,14,10,9},{12,3,15,5},{9,5,6,0},{7,12,8,15},{5,2,0,14},{10,15,5,2},{6,8,9,3},{1,6,2,12}};
int box8[16][4]={{13,1,7,2},{2,15,11,1},{8,13,4,14},{4,8,1,7},{6,10,9,4},{15,3,12,10},{11,7,14,8},{1,4,2,13},{10,12,0,15},{9,5,6,12},{3,6,10,9},{14,11,13,0},{5,0,15,3},{0,14,3,5},{12,9,5,6},{7,2,8,11}};
  string E_R=permutacion_expan(R);
  string resultado;
 resultado=XOR(k1,E_R);
 string bloque,fil,column;
 int fila,colummna;
 int contador=0;
 int valor;
 string resultado_t;
 for(int i=0;i<resultado.size();i=i+6)
 {
     bloque=resultado.substr(i,6);
     reverse(bloque.begin(),bloque.end());
     fil=bloque[0]+bloque[bloque.size()-1];
     column=bloque.substr(1,4);
     fila=bin_to_decimal(fil);
     colummna=bin_to_decimal(column);
     contador++;
     if(contador==1){valor=box1[fila][colummna];resultado_t=resultado_t+binario(valor);}
     if(contador==2){valor=box2[fila][colummna];resultado_t=resultado_t+binario(valor);}
     if(contador==3){valor=box3[fila][colummna];resultado_t=resultado_t+binario(valor);}
     if(contador==4){valor=box4[fila][colummna];resultado_t=resultado_t+binario(valor);}
     if(contador==5){valor=box5[fila][colummna];resultado_t=resultado_t+binario(valor);}
     if(contador==6){valor=box6[fila][colummna];resultado_t=resultado_t+binario(valor);}
     if(contador==7){valor=box7[fila][colummna];resultado_t=resultado_t+binario(valor);}
     if(contador==8){valor=box8[fila][colummna];resultado_t=resultado_t+binario(valor);}
 }
 //resultado_t=permutacionP(resultado_t);


 return resultado_t;
}
string des::permutacion1(string k)
{
  vector<int> tablero1;
  tablero1={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
  string K;
    for(int i=0;i<tablero1.size();i++)
    {
     K=K+k[tablero1[i]-1];
    }
return K;
}
string des::corrimiento_Iz(string numero, int x)
{ string devolver,numero1;
    numero1=numero;
  while(x>0)
  {

     devolver=numero1.substr(1,numero1.size())+numero1[0];
     numero1=devolver;
     x--;
  }
  return numero1;
}
string des::corrimiento_der(string numero, int x)
{
   string devolver,numero1;
    numero1=numero;
  while(x>0)
  {

     devolver=numero1[numero1.size()-1]+numero1.substr(0,numero1.size()-1);
     numero1=devolver;
     x--;
  }
  return numero1;
}
string des::permutacion2(string k)
{vector<int> tablero2;
tablero2={14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
string K;
    for(int i=0;i<tablero2.size();i++)
    {
     K=K+k[tablero2[i]-1];
    }
return K;
}
string des::XOR(string A,string B)
{
    bitset<48> foo(A);
    bitset<48> bar(B);
    bitset<48> result;
    result=foo^bar;
    string result_Sr=result.to_string();
    return result_Sr;
}
ZZ des::bin_to_ZZ(string bin)/// Conversion de Binario a Decimal
{
    ZZ numero(0);
    long tam=bin.length();
    for(long i=0;i<tam;i++){
        numero<<=1;
        numero|=(bin[i]&1)?1:0;///or binario
    }
    return numero;
}

string des::cifrar(string mensaje)
{ string PI,LO,RO;
   int t;
string k,ax;
    for(int i=0;i<mensaje.size();i++)
        {
            ax=mensaje.at(i);
            t=hexa.find(ax);
           k=k+num_en_base(t,4);
        }
  PI=permutacionIP(k);
  LO=PI.substr(0,PI.size()/2);
  RO=PI.substr(PI.size()/2,PI.size());
  string r;
  /*for(int i=1;i<16;i++)
    {
    }
 r=f(LO,key[0]);*/


  return mensaje;

}

#endif // DES_H
