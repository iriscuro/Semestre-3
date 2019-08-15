#include "rsa.h"
#include<bits/stdc++.h>
#include <NTL/ZZ.h>
#include "fstream"
using namespace std;
using namespace NTL;
rsa::rsa(int n_b)
{
    this->n_b=n_b;
    generar_clave();
    string m=Int_a_string(255);
    max_valor=m.size();

}
rsa::rsa(ZZ e,ZZ n){
    this->e=e;
    this->n=n;
    string m=Int_a_string(255);
    max_valor=m.size();
}
string rsa::ZZ_a_string(ZZ n)
{
    stringstream  ss;
    ss<<n;
string  numero;
ss>>numero;
return numero;
}
ZZ rsa::string_a_ZZ(string algo)
{stringstream sst(algo);
 ZZ Num;
 sst>>Num;
 return Num;
}
string rsa::Int_a_string(int a)
{
    stringstream stream;
    stream<<a;
    string b=stream.str();
    return b;
}
string rsa::completar(string name,int a)
{while(a>0)
         {name.insert(0,"0");
         a=a-1;}
    return name;
}
int rsa::string_a_int(string n)
{
 stringstream ss(n);
 int numero;
 ss>>numero;
 return numero;
}

void rsa::generar_clave(){
    ofstream Directorio ;
	ofstream clavesPrivadas;
	Directorio.open("Directorio publico.txt");
	clavesPrivadas.open("claves Privadas.txt");
    this->p=GenPrime_ZZ(n_b);//59;
    this->q=GenPrime_ZZ(n_b);//17;
    this->n=p*q;//1003;
    this->fi_n=(p-1)*(q-1);
    this->e=f.generar_aleatorio(n_b);//3;
    while(f.euclides(e,fi_n)!=1){
        this->e=f.generar_aleatorio(n_b);
    }
    this->d=f.mod(f.eExtendido(e,fi_n),fi_n);
    Directorio << "Rocio... \nClave n: "<< n << "\nClave e: "<< e << endl;
	clavesPrivadas << "p: "<< p <<"\n"<< "q: "<< q <<"\n"<< "n: "<< n <<"\n"<< "fi_n: "<< fi_n <<"\n"<< "e: "<< e <<"\n"<< "d: "<< d << endl ;

	clavesPrivadas.close();
	Directorio.close();
	cout<<"valor de n:"<<n<<endl;
	cout<<"clave publica e:"<<e<<endl;
	cout<<"clave privada d:"<<d<<endl;
}
ZZ rsa::get_q_inicial(ZZ P,ZZ p_or_q)
{
	ZZ q_i =f.eExtendido(p_or_q , P);
	return q_i;
}
ZZ rsa::tRestoChino(ZZ posCifrado)
{
	ZZ d= ZZ(f.mod(f.eExtendido(e,fi_n),fi_n));
	ZZ dp = ZZ(f.mod(d, p-1));
	ZZ dq = ZZ(f.mod(d, q-1));

	ZZ P = ZZ(n) ; //n=p*q; => nos ahorramos una multiplicacion

	ZZ pi = ZZ(q); //P / p;
	ZZ qi = ZZ(p); //P / q;

	ZZ q_1 = get_q_inicial (pi , p);
	ZZ q_2 = get_q_inicial (qi , q);

	ZZ D_i = f.mod((f.exp(posCifrado,dp,P) * pi * q_1), P ) + f.mod( ( f.exp(posCifrado,dq,P) * qi * q_2),P);
	D_i = ZZ(f.mod (D_i,P));

	ZZ posD = ZZ(D_i);

	return posD;
}
bool rsa::esprimo(ZZ pos){
    if(f.eExtendido(pos,n)==1)
        return true;
    return false;
}
ZZ rsa:: phi_euler(ZZ pos,ZZ exp){
    if(esprimo(pos))
        return ZZ(1);
}
bool rsa::Fermt_Primate(ZZ n){
    ZZ i,x;
    ZZ iteracion;
    int a=(int)sqrt(conv<int>(n));
    iteracion=conv<ZZ>(a);
    if (n==2)
        return 1;

    for (i=0;i<iteracion;i++){
        x =f.mod(RandomBits_ZZ((n_b/3)),n);
        if (x==0||x==1)
            x++;
        if (f.exp(x,n-1,n)!=1)
            return 0;
    }

    return 1;
}

bool rsa::par(int n){
    if(n%2==0)
        return true;
    return false;
}
string rsa::cifrar(string m){
    ZZ cipherp,pos;
    string msm_en_numeros,str_pos,pos_tam=Int_a_string(alfabeto.size()-1);//tamaño del alfabeto
    int posi,dif_0;
    for(int i=0;i<m.size();i++){
        posi=alfabeto.find(m[i])+10;
        str_pos=Int_a_string(posi);//en string
        msm_en_numeros=msm_en_numeros+str_pos;}
         string tn=ZZ_a_string(n),bloque,pedaso,msm,msj;
        int tamanoN=tn.size();
        if(!par(tamanoN)){
            tamanoN+=1;
        }
        int dife;ZZ blok;
        cout<<msm_en_numeros<<endl;
        while(msm_en_numeros.size())
        {
            bloque=msm_en_numeros.substr(0,tamanoN);//devuelve bloque , pos,tam
            blok=string_a_ZZ(bloque);//no tomamos el cero
            if(blok<n){
                msm_en_numeros.erase(0,tamanoN);
            }
            else{
                bloque=msm_en_numeros.substr(0,tamanoN-2);
                blok=string_a_ZZ(bloque);
                msm_en_numeros.erase(0,tamanoN-2);
            }
            blok=f.exp(string_a_ZZ(bloque),e,n);
            pedaso=ZZ_a_string(blok);
            cout<<pedaso<<"pedaso  "<<endl;
            dife=tamanoN-pedaso.size();
            if(dife!=0)
            { pedaso=completar(pedaso,dife);}
            msm=msm+pedaso;
        }
    return msm;
}
string rsa::decifrar(string cipher){
    string tn=ZZ_a_string(n),bloque,pedasito,msm;
    int tamanoN=tn.size();
    ZZ evaluar;int tmp,tm1;
    if(!par(tamanoN)){
        tamanoN+=1;}
    while(cipher.size()){
        bloque=cipher.substr(0,tamanoN);
        evaluar=string_a_ZZ(bloque);
        evaluar=f.exp(evaluar,d,n);
        pedasito=ZZ_a_string(evaluar);
        tmp=tamanoN-pedasito.size();
        string letra_sig=Int_a_string(alfabeto.size()-1);
        tmp=tamanoN-pedasito.size();
        cipher.erase(0,tamanoN);
        msm=msm+pedasito;
    }cout<<msm<<endl;
    string letra_sig=Int_a_string(alfabeto.size()-1),sub_m,mensaje;
    int tmp1;
    while(msm.size())
    {
        sub_m=msm.substr(0,letra_sig.size());
        tmp1=string_a_int(sub_m)-10;
        mensaje+=alfabeto[tmp1];
        msm.erase(0,letra_sig.size());

    }
    return mensaje;
}
int rsa::valor_ascci(char m){
    int r=static_cast<int>(m);
        return r;
}
char rsa::letra_ascci(int mm){
    return static_cast<char>(mm);
}
string rsa::cifrarA(string mj){
    string valor,mjefinal,nstring=ZZ_a_string(n),parte,mjcifrado;
    int pos,dif,tn=nstring.size();
    for(int i=0;i<mj.size();i++){
      pos=valor_ascci(mj[i]);
      valor=Int_a_string(pos);
      dif=max_valor-valor.size();
      if(dif!=0){
        valor=completar(valor,dif);
      }
      mjefinal=mjefinal+valor;
      cout<<valor<<endl;
    }
    valor="";int dife=0;
    for(int i=0;i<mjefinal.size();i+=max_valor){
        ZZ c;c=0;parte="";valor="";
        while(c<n&&i<=mjefinal.size()){
            valor+=mjefinal.substr(i,max_valor);
            c=string_a_ZZ(valor);
            if(c<n){
                parte=valor;
            i+=max_valor;}
            if(c>n)i-=max_valor;
        }i=i;
        ZZ x=f.exp(string_a_ZZ(parte),e,n);
        string bloque=ZZ_a_string(x);
        dife=tn-bloque.size();
        if(dife!=0){
            bloque=completar(bloque,dife);}
        mjcifrado+=bloque;
    }
    return mjcifrado;
}
string rsa::decifrarA(string mc){
    ZZ coger;string parte,c,bloque,mjdecifrado, stn=ZZ_a_string(n);
    int tn=stn.size(),dif=0;string blok="";
    while(mc.size()){
        parte=mc.substr(0,tn);
        coger=string_a_ZZ(parte);
        coger=f.exp(coger,d,n);
        bloque=ZZ_a_string(coger);
        dif=tn-bloque.size();
         blok=blok+bloque;
         cout<<bloque<<endl;
         mc.erase(0,tn);
    }
    while(blok.size()){
        parte=blok.substr(0,max_valor);
        coger=string_a_ZZ(parte);
        if(coger<to_ZZ(255)){
            mjdecifrado=mjdecifrado+letra_ascci(conv<int>(coger));
            blok.erase(0,max_valor);
        }
        else{
            parte=blok.substr(0,max_valor-1);
            coger=string_a_ZZ(parte);
            mjdecifrado=mjdecifrado+letra_ascci(conv<int>(coger));
            blok.erase(0,max_valor-1);
        }
    }
    return mjdecifrado;
}
