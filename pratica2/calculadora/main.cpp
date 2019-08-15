#include <iostream>

using namespace std;
void menuCM(){
    cout<<"1.  SUMA"<<endl;
    cout<<"2.  RESTA"<<endl;
    cout<<"3.  MULTIPLICACION"<<endl;
    cout<<"4.  INVERSO"<<endl;
}
int moduloR(int a,int b){//numero , modulo
    int c;
    c=a-b*(a/b);
    if(c<0)
        c=c+b;
    return c;
}
/*
int moduloAM(int a,int m){
    int crel=0;
    int cont=0;
    int lim=m;
    if(a>0){
        while(cont<a){
        cont++;
        crel++;
        if(crel==lim)
            crel=0;
    }
    }
    else{
        crel=m;
        while(cont<=a*(-1)){
            cont++;
            if(crel==lim-1 || crel==0){
                crel=m-1;
                cont++;
            }

            crel--;
            }
    }
    return crel;

}
*/
/*
int modulAritMod(int numero,int modulo){
    int resp,aux1,aux2,crel;
    if (numero>=0){
        resp=numero%modulo;
    }
    else{
        if(numero*(-1)>modulo){
            resp=numero%modulo;
            resp=modulo+resp;
        }
        else
            resp=modulo+numero;
    }
    return resp;
}
*/
int sumaM(int a,int b,int mod){
    int suma=a+b;
    int res=moduloR(suma,mod);
    return res;
}
int restaM(int a,int b,int mod){
    int resta=a-b;
    int res=moduloR(resta,mod);
    return res;
}
int multiplicaionM(int a,int b,int mod){
    int multi=a*b;
    int res=moduloR(multi,mod);;
    return res;
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
        p = moduloR(p,mod);
        cont++;
        p_0 = p_1;
        p_1 = p;
        r=b-a*(b/a);
        b=a;
        a=r;
    }
    return p;
}
int main()
{
    int n_1,n_2,mod,opcion,resp;
    cout << " ---------Calculadora modular ---------" << endl;
    menuCM();
    cout<<" Ingrese el numero de la operacion que desea obtener :\t ";
    cin>>opcion;

    if(opcion<0 || opcion>4){
        cout << " operacion errada ..."<<endl;
    }
    if(opcion==4){
        cout <<" n_1:\t";
        cin>> n_1;
        cout <<" mod:\t";
        cin>>mod;
        if(inverModular(n_1,mod)==1){
            int vuel=vMCD(n_1,mod);
            resp = inversoModular(n_1,mod,vuel);
            cout<< resp<<endl;
        }
        else
            cout <<"No tiene inverso..."<<endl;
    }
    else{
        cout <<" n_1:\t";
        cin>> n_1;
        cout <<" n_2:\t";
        cin>>n_2;
        cout <<" mod:\t";
        cin>>mod;
        if(opcion==1){
            resp=sumaM(n_1,n_2,mod);
            cout<< resp<<endl;
        }
        else if(opcion==2){
            resp = restaM(n_1,n_2,mod);
            cout<< resp<<endl;
        }
        else {
            resp= multiplicaionM(n_1,n_2,mod);
            cout<< resp<<endl;
        }

    }
    return 0;
}
