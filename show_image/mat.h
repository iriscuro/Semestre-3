#ifndef MAT_H
#define MAT_H

#include<bits/stdc++.h>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;

class mat
{
    public:
        mat();
        int modulo(int ,int);
        ZZ generar_aleatorio(int byte);
        ZZ mod(ZZ A,ZZ B);
        ZZ mcd(ZZ A,ZZ b);
        ZZ eExtendido(ZZ a, ZZ b);
        ZZ euclides(ZZ ,ZZ);
        ZZ exp(ZZ a,ZZ B,ZZ);
        ZZ inversa(ZZ &a, ZZ &B);
        ZZ fermat_peque(ZZ pos,ZZ B,ZZ p);
        ZZ euler(ZZ pos,ZZ e,ZZ n);
        ZZ phi(ZZ p);
        ZZ inversa_fermat(ZZ a,ZZ p);
        ZZ inversa_euler(ZZ a,ZZ p);
        virtual ~mat();

};


#endif // MAT_H
