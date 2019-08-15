#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int mod(int num,int mod)
{
	int r,q;
	q=num/mod;
	r=num-(mod*q);
	if(r<0){return r+mod;}
	return r;
}

int euclides(int A,int b)
{
	int q,r,mcd;
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

int algEuclidesMCD(int num,int mod){
    int a=num;
    int b=mod;
    int mcd_,q,r;
    if(a==0){
        mcd_=b;
        return mcd_;
    }
    if(b==0){
        mcd_=a;
        return mcd_;
    }
    q=a/b;
    r=a-b*q;//num=mod*q+r
    a=b;
    b=r;
    mcd_=algEuclidesMCD(a,b);


}

int la_inversa(int r1,int r2,int tam)
{
	int s1=1;
	int s2=0;
	int r=0;
	int q=0;
	int x=0;//inverso
	while(r2>0){
        //r=r1-(r1/r2)r2
		q=r1/r2;
		r=r1-q*r2;
		r1=r2;
		r2=r;

		x=s1-q*s2;
		s1=s2;
		s2=x;
		}
	x=s1;
	if(x<0){
            x=mod(x,tam);
    }
	return x;
}

int ramdom(int top,int i)
{
srand((unsigned)time(NULL));
	int d=rand()%top+i;
	return d;
}

int generar_clave_a(int tam){
	int a=0;
	int i=0;
	while (euclides(a,tam)!=1){
        a=ramdom(tam,i);
        i++;
        cout<<"alet. a: "<<a<<endl;

	}
	return a;
}

int generar_clave_b(int tam){
	long clave =ramdom(1000,10);
	if(clave > tam){
            clave=mod(clave,tam);
    }

	return clave;
}
