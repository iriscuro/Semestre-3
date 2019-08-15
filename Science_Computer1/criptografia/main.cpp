#include <iostream>
#include <fstream>
// ofstream: Clase stream para escribir archivos.
// ifstream: Clase stream para leer archivos.
// fstream: Clase stream para hacer ambas cosas, leer y escribir.
using namespace std;
int mcd(int num1,int num2){
    int a,b,mcdr;
    a=max(num1,num2);
    b=min(num1,num2);
    if(num1==0){
        mcdr=num2;
    }
    if(num2==0){
        mcdr=num1;
    }
    else{
        do{
            mcdr=b;
            b=a%b;
            a=mcdr;
        }
        while(b!=0);
        }

    return mcdr;
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
int vMCD(int a,int b){
    int r,cont=0;
    while(r!=0){
        r=b-a*(b/a);
        b=a;
        a=r;
        cont++;
    }
    return cont-1;
}

int modulo(int a, int b){
    int c;
    c=a-b*(a/b);
    if(c<0)
        c=c+b;
    return c;
}
int moduloR(int a,int b){//numero , modulo
    int m;
    if(a<0){
      m=a-(a/b-1)*b;
      if(m==b)
        m=0;
    }
    else{
       m=a-(a/b)*b;
    }
    return m;
}

bool  inverModular(int num, int mod){
    return (algEuclidesMCD(num,mod)==1)? true:false;

}

int inversoModular(int a,int b,int vueltas){//NUMERO,MODULO , CANT. VUELTAS
    int p_0=0;
    int p_1=1;
    int p,r,cont =0;
    int mod=b;
    while(cont<=vueltas-1){
        p = p_0-p_1*(b/a);
        //cout<<"p sin m "<<p<<endl;
        //cout<< "b "<<b<<endl;
        //cout<< "a "<<a<<endl;
        p = modulo(p,mod);
        cont++;
        //cout<< "p "<<p<<endl;
        p_0 = p_1;
        //cout<< "p_0 "<<p_0<<endl;
        p_1 = p;
        //cout<< "p_1 "<<p_1<<endl;
        r=b-a*(b/a);
        b=a;
        a=r;
    }
    return p;
}
//cifrar


// descifrar

int main()
{
    int claveP;
    int clavePr;
    cout <<"Clave publica: ";
    cin>> claveP;
    if(inverModular(claveP,256)==1)
        //pedir mensaje y hacer su cifrado

    else{
        cout<<"clave invalida, ingresa otra...\n";
        cin>>claveP;
    }
    /*
    ofstream file("mensaje.txt");
    string mensaje;
    cout<< "Escribe un mensaje: ";
    cin>>mensaje;
    file << "primera línea\n";
    file << "segunda línea\n";
    file << "tercera línea\n";
    file<< mensaje<<endl;
    */
    /*
    fstream archivo("cifrado.txt");
    string linea;
    int op;
    cout<<"1- Leer registro\n2.- Salir\n";
    cin>> op;

    if(op==1){
        if(!archivo.is_open())
            archivo.open("cifrado.txt",ios::in);
        while(getline(archivo,linea))
            cout<< linea <<"\n";
        archivo.close();
        //system("pause");
    }
*/
/*
    char a;
    int i;
    int op;
    do{
        system("cls");
        cout<<"Elige una opcion\n";
        cout<<"1- Codigo a ASCCI\n";
        cout<<"2- ASCCI a codigo\n";
        cout<<"3- Salir\n";
        cin>>op;
        if(op == 1){
            cout<<"Introduce el codigo ASCII:\n";
            cin>>i;
            a=i;
            cout <<"El caracter es :\n"<<a<<endl;
        }
        if(op==2){
            cout <<"Introduce el caracter :\n";
            cin>>a;
            i=a;
            cout<<"El codigo ASCII es: "<<i<<endl;

        }
        system("pause");
    }
    while(op!=3);
*/
    return 0;
}
