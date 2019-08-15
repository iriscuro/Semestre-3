#include "formulario.h"
#include<bits/stdc++.h>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;
formulario::formulario()
{
    //ctor
}
formulario::~formulario()
{}
ZZ formulario::generar_aleatorio(int byte){
    ZZ a;
     a=RandomBits_ZZ(byte);
      return a;

}
int formulario::modulo(int a,int b){
    int x=a-b*(a/b);
    if(x<0){
        x+=b;
    }
    return x;
}
ZZ formulario::mod(ZZ D, ZZ d)
{
	ZZ q = ZZ(D/d);
	ZZ r = ZZ(D-(q*d));
	if ( r< ZZ(0))
	{
		q--;
		r += d;
	}
	return r;
}
ZZ formulario::mcd( ZZ a , ZZ b )
{
	ZZ aux = ZZ(1) ;
	ZZ tmp;

	while( a % 2 == 0 and b %2 == 0 )
	{
	//cout << " 2 " << endl;
		a >>= 1 ;
		b >>= 1 ;
		aux <<= 1 ;
	}

	while ( a != 0 )
	{
	//cout << " 3 " << endl;
		if ( mod(a, ZZ(2)) == 0)
			a >>= 1 ;
		else if ( mod(b, ZZ(2)) == 0 )
			b >>= 1;
		else { //3er caso : a y b son impares
			tmp = abs(a-b);
			tmp >>= 1 ;
			if (a >= b )
				a = tmp;
			else
				b = tmp;
		}
	}

	return aux*b;
}
ZZ formulario::euclides(ZZ a,ZZ b){
    ZZ tmp;
    while(b!=0){
        tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}
ZZ formulario::eExtendido(ZZ a ,ZZ b)
{
	ZZ r1 , r2, s1, s2 , t1, t2, r,s,t,q;
	r1=a ; r2=b ; s1 = ZZ(1) ; s2 = ZZ(0)  ; t1 = ZZ(0) ; t2 = ZZ(1) ;

	while( r2> ZZ(0))
	{
		q = r1/r2;
		r = r1 -(q*r2);
		r1 = r2 ; r2 = r ;

		s= s1 -(q*s2);
		s1 = s2 ; s2 = s ;

		t = t1 -(q*t2) ;
		t1 = t2 ; t2 = t ;
	}
	return s1;
}
ZZ formulario::exp(ZZ  a, ZZ p, ZZ n)
	{
	ZZ  y;
	y = ZZ(1);
	while (p!=ZZ(0))
	{
      if ((p&1)==1)
		y = mod((y * a) ,n);

      a = mod((a * a),n);
      p = p >> 1;
	}

	return y;
	}
ZZ formulario::inversa(ZZ  &a, ZZ  &b)
{   ZZ v;
    ZZ inver;
    v=eExtendido(a,b);
    if(v==1)
        {inver=v;
        if(inver<0 or inver>b )
            inver=mod(inver,b);}
    else
        {cout<<"no tine inversa"<<endl;}
//error sillo cuando 7 modulo 7

return  inver;
}
ZZ formulario::fermat_peque(ZZ pos,ZZ e,ZZ p){
    if(ProbPrime(p)&& mcd(pos,p)==1){
        if((p-1)==e)
            return to_ZZ(1);
        if(p<e){
            return exp(pos,e,p);
        }
    }
}
ZZ formulario::phi(ZZ p){
    if(p==to_ZZ(1))
        return to_ZZ(0);
    else if(ProbPrime(p))
        return to_ZZ(p-1);
    else{
        ZZ k(1);
        for(ZZ i=to_ZZ(2);i<=p;i++){
            ZZ num(0);
            ZZ k1;
            long long potencia=0;
            while(mod(p,i)==to_ZZ(0)){
                num=1;
                potencia++;
                p/=i;
            }
            if(num!=to_ZZ(0)){
                k1=power(num,potencia)-power(num,potencia-1);
                k*=k1;
            }
        }
        return k;
    }
}

ZZ formulario::euler(ZZ pos,ZZ e,ZZ n){
    if(ProbPrime(n)&&mcd(pos,n)==1&&mod(pos,n)!=0&&pos<n){
        if((phi(n)+to_ZZ(1))==e){
            return to_ZZ(1);
        }
        if((phi(n)+to_ZZ(1))<e){
            ZZ sim=mod(e,n);
            return mod(pos*exp(pos,sim,n),n);
        }
    }
    return exp(pos,e,n);
}
ZZ formulario::inversa_fermat(ZZ a,ZZ p){
    if(ProbPrime(p)&&mod(a,p)!=0&&mcd(a,p)==1){
        return exp(a,p-to_ZZ(2),p);
    }
    return eExtendido(a,p);
}
ZZ formulario::inversa_euler(ZZ a,ZZ p){
    if(ProbPrime(p)&&ProbPrime(a)&&mcd(a,p)==1){
        return exp(a,phi(p)-to_ZZ(1),p);
    }
    return eExtendido(a,p);
}
