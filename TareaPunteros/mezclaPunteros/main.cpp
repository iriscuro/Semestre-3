#include <iostream>

using namespace std;
int menor(int *a,int* b){
    return (*a<*b)?*a:*b;
}

void Mezcla(int* A,int* B, int* C,int n){
    int* fin1 = &A[n/2-1];
    int* fin2 = &B[n/2-1];
    while(A <= fin1 && B <= fin2){
        if(*A<*B){
            *C=*A;
            cout <<"C: "<<*C<<endl;
            C++;
            A++;
        }
        else{
            *C=*B;
            cout <<"C: "<<*C<<endl;
            C++;
            B++;
        }
    }

    if(A<B){
        while(A<=fin1){
            *C=*A;
            C++;
            A++;
        }
    }
    else{
        while(B<=fin2){
            *C=*B;
            C++;
            B++;
        }
    }

}
int main()
{   //MEZCLA
    //arreglos del mismo tamaño

    int pares[]={20,600,800,908};
    int impares[]={101,315,615,1117};
    int tam=sizeof(pares)/sizeof(*pares)*2;
    int n=sizeof(pares)/sizeof(*pares);
    int mezc[tam]={0};

    cout<<endl;
    // para la mezcla
    Mezcla(pares,impares,mezc,tam);
    int *inic=mezc;
    int *finl=&mezc[tam-1];

    //imprimir array
    while(inic<=finl){
        cout<<*(inic)<<" ";
        inic++;
    }
    return 0;
}
