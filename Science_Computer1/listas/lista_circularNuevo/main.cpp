#include <iostream>
#include "listaC.h"
using namespace std;
void swapP(int *a, int  *b){
    int n= *a;
    *a=*b;
    *b=n;
}
void Josephus(int turno,int total){//turno
    listaC<int> j;
    //lista ordenada con el total
    for(int i=1;i<=total;i++){
        j.agregar(i);
    }j.mostrar();
    nodo<int> *t=j.head;
    do{
        for(int i=1;i<turno;i++){
            t=t->next;
        }//cout<<"t eliminado: "<<t->valor<<endl;
        int valor=t->valor;
        t=t->next;
        j.eliminar(valor);//cout<<"\nt ne: "<<t->valor<<endl;

    }while(t!=t->next);
    j.mostrar();
}
bool mayor(int a,int b){
    return (a>b);
}

bool menor(int a,int b){
    return (a<b);
}
void cocktail(int *numeros,int tam,bool(*p)(int,int)){//funciona bien
    int *ini=numeros;
    int *fin=(numeros+tam-1);
    int *A=ini;
    int *B=fin;bool swapC=1;
    ini=ini+1;fin=fin-1;
    while(swapC){
      if(ini<fin){
          if(A<=fin){
            if(p(*(A+1),*A)){//recorrer todos los numeros
              swapP(A,(A+1));
              }A++;
          }
          else{
            if(B>=ini){
                if(p(*B,*(B-1))){
                  swapP(B,(B-1));}
                  B--;}
                else{
                  fin--;B=fin;
                  ini++;A=ini;}
                }
              }
        else{swapC=0;
        }
    }
}

int main()
{

    listaC<int> le;
    Josephus(7,50);
    /*
    le.agregar(1);
    le.agregar(5);
    le.agregar(9);
    le.mostrar();
    cout<< endl;
    le.agregar(3);
    le.agregar(7);
    le.mostrar();
    le.eliminar(1);
    le.eliminar(5);
    le.eliminar(9);
    le.mostrar();*/

    /*
    //COCKTAIL
    int numeros[]={1,23,2,45,13,89,100,20,76,30};
    int tam=sizeof(numeros)/sizeof(*numeros);
    cout << "tam: "<<tam<<endl;
    //imprimir el array original
    for(int a=0;a<tam;a++){
        cout<<numeros[a]<<" ";
    }
    bool (*p)(int,int)=menor;
    cocktail(numeros,tam,p);

    cout<<endl;

    for(int i=0;i<tam;i++){
        cout<<numeros[i]<<" ";
    }*/
}
