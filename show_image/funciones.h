#include<iostream>
#include <cstdlib>
#include <sstream> // std::stringstream conversion
#include <NTL/ZZ.h>
#include <ctime>
#include <string.h>
using namespace std;
using namespace NTL;

int mod_int(int num,int mod){
    int r,q;
    q = num/mod;
    r = num - (mod*q);
    if(r<0){return r+=mod;}
    return r;
}
ZZ mod(ZZ num,ZZ mod)
{
	ZZ r,q;
	q=num/mod;
	r=num-(mod*q);
	if(r<0){return r+=mod;}
	return r;
}
ZZ euclides(ZZ A,ZZ b)
{
	ZZ q;
	ZZ r;
	ZZ mcd;
	r=mod(A,b);
	while(r>0){
		mcd=r;
		q=A/b;
		r=mod(A,b);
		A=b;
		b=r;
	}
	return mcd;
}

ZZ extendido(ZZ r1,ZZ r2){
    ZZ s1=to_ZZ("1");
	ZZ s2=to_ZZ("0");
	ZZ r=to_ZZ("0");
	ZZ q=to_ZZ("0");
	ZZ x=to_ZZ("0");
	while(r2>0){
		q=r1/r2;
		r=r1-q*r2;
		r1=r2;
		r2=r;

		x=s1-q*s2;
		s1=s2;
		s2=x;
	}
	x=s1;
	return x;
}
ZZ la_inversa_modular(ZZ r1,ZZ r2)
{
    ZZ x;
    x=extendido(r1,r2);
	if(x<0){x=mod(x,r2);}
	return x;
}

ZZ generar_aleatorio(int bits)
{
    ZZ a=RandomBits_ZZ(bits);
    return a;
}
ZZ ramdom(ZZ top,ZZ i)
{
	srand((unsigned)time(NULL));
	ZZ d=RandomBnd(top)+i;
	return d;
}

ZZ exp_modular(ZZ a,ZZ exp,ZZ modulo){
    //cout<< "Expo modular: "<<a<<"exp "<<exp<<" mod "<<modulo<<" = ";
	ZZ result;
	result = ZZ(1);
	while(exp!=ZZ(0)){
		if((exp&1)==1){
			result=mod(result*a,modulo);
		}
		a=mod((a*a),modulo);
		exp=exp >> 1;
	}
    //cout<<result<<endl;
	return result;
}

string ZZ_a_string(ZZ n)
{
    stringstream  ss;
    ss<<n;
    string  numero;
    ss>>numero;
    return numero;
}
ZZ string_a_ZZ(string algo)///verdadero funciona (anabel)
{
    stringstream sst(algo);
    ZZ Num;
    sst>>Num;
    return Num;
}
string int_to_string(int num)
{
    string s;
    stringstream ent;
    ent << num;
    s = ent.str();
    return s;
}
int string_to_int(string le)
{
    stringstream a(le);
    int num;
    a>> num;
    return num;
}

string completarC(string pal,long c_c)
{
    //cout<< "pal.size dif c_c: "<<c_c-pal.size()<<endl;
    long dif = c_c-pal.size();
    if(pal.size()< c_c)//completar ceros si es < que el nro de cifras
    {   // normalizamos
        for(int j=0;j < dif;j++)
            pal = "0" + pal;
    }
    //cout<<"PAL WITH 0: "<< pal<<endl;
    return pal;
}
string completarC_Atras(string pal,long c_c)
{
    //cout<< "COMPLETARAR UTLIMO "<<endl;
    int t = pal.length();//cout<< "t "<<t<<endl;
    int ul = mod_int(t,c_c);//cout<< "ul "<<ul<<endl;
    string final=pal;
    string p = pal.substr(t-ul);//cout <<"p: "<<p<<endl;
    string fil = pal.substr(0,t-ul);
    int i=p.size();//cout<< "i "<<i<<endl;

    if(i!=0){
    int a=0;
    while(a<c_c-i){
        p += "0";a++;
    }
    }
    fil.insert(t-ul,p);
    return fil;
}
string completarC_Adelante(string pal,long c_c)
{   //cout<< "COMPLETARAR AL INICIO "<<endl;
    int t = pal.length();//cout<< "t "<<t<<endl;
    int ul = mod_int(t,c_c);//cout<< "ul "<<ul<<endl;
    string final=pal;
    string p = pal.substr(0,ul);//cout <<"p: "<<p<<endl;//extare lo que sobra
    string fil = pal.substr(ul,t);//cout <<"fil: "<<fil<<endl;
    int i=p.size();//cout<< "i "<<i<<endl;
    if(i!=0){
    while(i<c_c-p.size()){
        p = "0"+p;i++;
    }
    }
    fil.insert(0,p);//cout<<"fil "<<fil<<endl;
    return fil;
}
bool Is_parZZ(ZZ num){
    if(mod(num,ZZ(2))== 0)
        return true;
    else return false;
}
bool Is_par(int cifras)
{
    return (mod_int(cifras,2))?false:true;
}
//PARA RSA REDUCIR CALCULOS
bool exis_TRC( ZZ mod_1,ZZ mod_2){
    if(euclides(mod_1,mod_2)==1)// VERIFICACION, SON COPRIMOS
        return true;
    else return false;
}
ZZ teo_Resto_Chino(ZZ a, ZZ b, ZZ mod_1,ZZ mod_2)
{
	//cout << " ---------- Resto Chino --------------" << endl;
	ZZ P = mod_1*mod_2 ;

	ZZ pi = P/mod_1; //P / p;
	ZZ qi = P/mod_2; //P / q;

	ZZ q_1 = la_inversa_modular(pi , mod_1);
	ZZ q_2 = la_inversa_modular(qi , mod_2);

	ZZ x_0 = mod(mod(a * pi * q_1, P ) + mod(b * qi * q_2,P),P);

	return x_0;
}
bool son_copr(ZZ A,ZZ B){
    if (euclides(A,B)==1)
        return true;
    else return false;
}

void escribiR(string name,string sms)
{
    setlocale(LC_ALL, "");
    ofstream escritura;
    escritura.open( name+".txt", ios::binary );
    escritura<<sms;

    escritura.close();
}
