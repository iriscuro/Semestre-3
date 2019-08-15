#include <iostream>

using namespace std;
void menuCM(){
    cout<<"1.  SUMA"<<endl;
    cout<<"2.  RESTA"<<endl;
    cout<<"3.  MULTIPLICACION"<<endl;
    cout<<"4.  INVERSO"<<endl;
}
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

int sumaM(int a,int b,int mod){
    int suma=a+b;
    int res=modulAritMod(suma,mod);
    return res;
}
int restaM(int a,int b,int mod){
    int resta=a-b;
    int res=modulAritMod(resta,mod);
    return res;
}
int multiplicaionM(int a,int b,int mod){
    int multi=a*b;
    int res=modulAritMod(multi,mod);;
    return res;
}
int inversoM(int a,int mod){

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
        else if(opcion==3){
            resp= multiplicaionM(n_1,n_2,mod);
            cout<< resp<<endl;
        }
        else{
            resp = inversoM(n_1,mod);
            cout<< resp<<endl;
        }

    }
    return 0;
}
