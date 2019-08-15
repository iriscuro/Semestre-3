#include "mat.h"
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;
mat::mat()
{
    //ctor
}
mat::~mat()
{}
ZZ mat::generar_aleatorio(int byte){
    ZZ a;
     a=RandomBits_ZZ(byte);
      return a;

}
int mat::modulo(int a,int b){
    int x=a-b*(a/b);
    if(x<0){
        x+=b;
    }
    return x;
}
ZZ mat::mod(ZZ D, ZZ d)
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
ZZ mat::mcd( ZZ a , ZZ b )
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
ZZ mat::euclides(ZZ a,ZZ b){
    ZZ tmp;
    while(b!=0){
        tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}
ZZ mat::eExtendido(ZZ a ,ZZ b)
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
ZZ mat::exp(ZZ  a, ZZ p, ZZ n)
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
