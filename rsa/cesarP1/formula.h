#ifndef FORMULA_H
#define FORMULA_H
#include<bits/stdc++.h>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;
class formula
{
    public:
        formula();
        int modulo(int ,int);
        ZZ generar_aleatorio(int byte);
        ZZ mod(ZZ A,ZZ B);
        ZZ mcd(ZZ A,ZZ b);
        ZZ eExtendido(ZZ a, ZZ b);
        ZZ euclides(ZZ ,ZZ);
        ZZ exp(ZZ a,ZZ B,ZZ);
        ZZ inversa(ZZ a, ZZ B);
        virtual ~formula();

    protected:

    private:
};

#endif // FORMULA_H
