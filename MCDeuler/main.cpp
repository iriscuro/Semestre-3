// EuclidesTotal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <NTL/ZZ.h>
#include <vector>
#include <time.h>

using namespace std;
using namespace NTL;
ZZ mod(ZZ c, ZZ d)
{
	ZZ e, f;
	if (c < 0)
		e = (c / d) - 1;
	else
		e = c / d;
	f = c - (d*e);
	return f;
}
int binary_gcd(int u, int v)
{
	int shl;shl=0;

	while (u && v && u != v) {
		bool eu = !(u & 1);
		bool ev = !(v & 1);

		if (eu && ev) {
			++shl;
			u >>= 1;
			v >>= 1;
		}
		else if (eu && !ev) u >>= 1;
		else if (!eu && ev) v >>= 1;
		else if (u >= v) u = (u - v) >> 1;
		else {
			int tmp = u;
			u = (v - u) >> 1;
			v = tmp;
		}
	}

	return !u ? v << shl : u << shl;
}
ZZ euclideanGCD(ZZ m,ZZ n)
{
   if(n==0)
       return m;
   else
       return euclideanGCD(n,mod(m,n));
}
ZZ GCDbrute(ZZ m, ZZ n)
{
    ZZ i=m;
    while((mod(m,i)!=0)||(mod(n,i)!=0))
    {
        i--;
    }
    return i;
}
ZZ eucli(ZZ a, ZZ b)
{
	ZZ r = mod(a, b);
	ZZ d = b;
	ZZ c;
	while (r > 0)
	{
		c = d;
		d = r;
		r = mod(c, d);
	}

	//cout<<"test"<<d<<"test"<<a<<"test"<<b;
	return d;
}
vector<ZZ>euclides_Extendido(ZZ a, ZZ b)
{
    vector<ZZ> EE;
    ZZ r1=a;
    ZZ r2=b;
    ZZ s1=ZZ(1);
    ZZ s2=ZZ(0);
    ZZ t1=ZZ(0);
    ZZ t2=ZZ(1);
    ZZ cociente,r,s,t;
    while(r2>0)
    {
        cociente=r1/r2;
        r=r1-(cociente*r2);
        r1=r2;      r2=r;
        s=s1-(cociente*s2);
        s1=s2;      s2=s;
        t=t1-(cociente*t2);
        t1=t2;      t2=t;
    }
    s=s1;
    t=t1;
    r=r1;
    EE.push_back(s);
    EE.push_back(t);
    EE.push_back(r);
    return EE;
}
ZZ gcdExtended(ZZ a, ZZ b, ZZ *x, ZZ *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    ZZ x1, y1;
    ZZ gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}
/*ZZ binaryExtended(ZZ a, ZZ b)
{

}*/
 void medir()
 {
     int arr[6]={8,16,128,521,1024,2048};
     clock_t inicio;
	 float duracion;
     for(int i=0;i<=5;i++)
     {
     ZZ t;
     ZZ t1;
     RandomBits(t,arr[i]);
     RandomBits(t1,arr[i]);
     cout<<"----------------"<<arr[i]<<"---------------------------"<<endl;
     cout<<"----------------Binary_GCD---------------------------"<<endl;
      inicio = clock();
     //binary_gcd(t,t1);
     duracion = (clock() - inicio) / (float)CLOCKS_PER_SEC;
     cout<<"Duracion: "<< duracion <<endl;
     cout<<"----------------Euclides  ---------------------------"<<endl;
     inicio = clock();
     eucli(t,t1);
     duracion = (clock() - inicio) / (float)CLOCKS_PER_SEC;
     cout<<"Duracion: "<< duracion <<endl;
     cout<<"----------------Recursivo----------------------------"<<endl;
     inicio = clock();
     euclideanGCD(t,t1);
     duracion = (clock() - inicio) / (float)CLOCKS_PER_SEC;
     cout<<"Duracion: "<< duracion <<endl;
     cout<<"----------------Fuerza Bruta-------------------------"<<endl;
     inicio = clock();
     GCDbrute(t,t1);
     duracion = (clock() - inicio) / (float)CLOCKS_PER_SEC;
     cout<<"Duracion: "<< duracion <<endl;
     cout<<"----------------Extendido----------------------------"<<endl;
     inicio = clock();
     euclides_Extendido(t,t1);
     duracion = (clock() - inicio) / (float)CLOCKS_PER_SEC;
     cout<<"Duracion: "<< duracion <<endl;
     cout<<"----------------ExtendidoRecursivo-------------------"<<endl;
     inicio = clock();
     ZZ x1,x2;
     gcdExtended(t,t1,&x1,&x2);
     duracion = (clock() - inicio) / (float)CLOCKS_PER_SEC;
     cout<<"Duracion: "<< duracion <<endl;
     }


 }
int main()
{
	medir();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
