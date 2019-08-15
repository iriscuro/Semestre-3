#ifndef FIRMA_H
#define FIRMA_H
#include "mat.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;
class Firma
{
    public:
        //string nomImag = "imagenes/logo.jpg";
        string nomImag = "imagenes/only.png";
        vector<int> g;// generado
        vector<int> r;// reconstruido

        mat mat;

        Firma();
        Firma(int bit);
        Firma(ZZ,ZZ);
        void generar_clave();
        ZZ string_a_ZZ(string algo);
        string ZZ_a_string(ZZ n);
        string Int_a_string(int a);
        string completar(string name,int a);
        int string_a_int(string n);
        string firmar();
        string Rubrica();
        string firmo();
        string recibom(string a);
        void confirma(string pex);
        bool numero(char);

        string loadImg(int alto,int ancho);
        void showImage(int d_x,int d_y);
        void showImageResult();

        //MIO

        string firmaDigital();
        void obtenerRubica(string firma);
        void guardarR(string pixeles);


        ZZ N,d,e,p,q,phi_n;
        ZZ e_b,N_b,d_b;
        ZZ R;// RUBRICA
        ZZ F;// FIRMA DE LA RUBRICA
        int n_bit;
};

#endif // FIRMA_H



/*#ifndef FIRMA_H
#define FIRMA_H
#include "mat.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;
class firma
{
    public:
        mat mat;
        firma(int bit);
        firma(ZZ,ZZ,int);
        void generar_clave();
        ZZ string_a_ZZ(string algo);
        string ZZ_a_string(ZZ n);
        string Int_a_string(int a);
        string completar(string name,int a);
        int string_a_int(string n);
        string firmar();
        string Rubrica();
        string firmo();
        string recibom(string a);
        void confirma (string);
        bool numero(char);




        ZZ n,d,e,p,q,fi_n;
         ZZ e_el,n_el;
        int bit;
};

#endif // FIRMA_H

*/

/*
#ifndef FIRMA_H
#define FIRMA_H
#include <iostream>
#include "string"
#include<bits/stdc++.h>
#include <NTL/ZZ.h>
#include "fstream"
#include <vector>
using namespace std;
using namespace NTL;

class Firma
{
    public:
        vector<int> g;
        vector<int> r;
        string nomImag = "imagenes/logo22.jpg";
        ZZ e ;
        ZZ N ;
        ZZ e_b;
        ZZ N_b;
        Firma();//para probar
        Firma(int n_bits);// Emisor
        Firma(ZZ d_B,ZZ N_B);   // Receptor

        string firmaDigital(ZZ N_B,ZZ E_B);
        void obtenerRubica(string firma,ZZ E_A,ZZ N_A);
        void generar_claves();
        string loadImg(int alto,int ancho);
        void showImage(int d_x,int d_y);
        void showImageResult();
        void guardarR(string pixeles);

    private:
        ZZ d;
        ZZ d_b;
        ZZ R;// RUBRICA
        ZZ F;// FIRMA DE LA RUBRICA
        ZZ p,q;  // numeros primos
		ZZ phi_N;
		int n_bits;

};

#endif // FIRMA_H
*/
