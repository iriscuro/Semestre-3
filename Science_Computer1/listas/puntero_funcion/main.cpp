#include <iostream>
#include "lista_Orden_simple.h"
using namespace std;

nodo* ordenar(lista A,lista B){
    nodo *stardA = A.head;
    nodo *stardB = B.head;
    nodo *tejas = A.head;
    cout<<"Recorriendo la lista"<<endl;
    while(stardA && stardB){nodo *gancho;
        cout<<tejas->valor<<" ";
        //if(stardA->valor != stardB->valor){
           if(stardA->valor <= stardB->valor){
              gancho=stardA->sig;
              tejas->sig=stardA;
              stardA=gancho;
          }
          else{gancho=stardB->sig;
            tejas->sig=stardB;
            stardB=gancho;
          }
          tejas =tejas->sig;//}
       /* else{
          if(tejas==stardA){ gancho=stardA->sig;stardA=gancho;}
          else{gancho=stardB->sig;stardB=gancho;}}*/
    }
    if(stardA){
      tejas->sig = stardA;}
    if(stardB){
      tejas->sig = stardB;
    }

    cout<<endl;
    return A.head;
    //A.print_lista();
}
nodo* ordenarN(nodo *A,nodo *B){//FUNCIONA CORRECTAMENTE
    nodo *stardA = A;
    nodo *stardB = B;
    nodo *tejas = stardA;
    cout<<"Recorriendo la lista"<<endl;
    while(stardA && stardB){nodo *gancho;
        cout<<tejas->valor<<" ";
          if(stardA->valor <= stardB->valor){
              gancho=stardA->sig;
              tejas->sig=stardA;
              stardA=gancho;
          }
          else{gancho=stardB->sig;
            tejas->sig=stardB;
            stardB=gancho;
          }
          tejas =tejas->sig;
    }
    if(stardA){
      tejas->sig = stardA;}
    if(stardB){
      tejas->sig = stardB;
    }

    cout<<endl;
    return A ;
    //A.print_lista();
}
void SPLIT(nodo *A,nodo*B=nullptr){
    nodo *T;nodo* gancho;nodo *S;
    for(T=A;T;T=T->sig){
        gancho = A->sig;
        if(T->valor%2==0)
            A->sig =T;
        else{
            if(!B)
                B=T;
            B->sig=T;
        }
        T=gancho;
    }
}
int main()
{   //MERGE SORT funciona
	lista mylista;/*
	mylista.add_nodo(1);
	mylista.add_nodo(3);
	mylista.add_nodo(5);
	mylista.add_nodo(7);*/

	lista listaB;/*
	listaB.add_nodo(2);
	listaB.add_nodo(4);
	listaB.add_nodo(6);
	listaB.add_nodo(8);*/

	//SEGUNDO CASO

	mylista.add_nodo(1);
	mylista.add_nodo(3);
	mylista.add_nodo(6);
	mylista.add_nodo(9);

	listaB.add_nodo(1);
	listaB.add_nodo(2);
	listaB.add_nodo(4);
	listaB.add_nodo(6);
    // TERCER CASO
    /*
	mylista.add_nodo(1);
	mylista.add_nodo(2);
	mylista.add_nodo(3);

	listaB.add_nodo(1);
	listaB.add_nodo(5);
	listaB.add_nodo(6);
	listaB.add_nodo(7);*/
	//CUARTO CASO
    /*
	mylista.add_nodo(1);
	mylista.add_nodo(2);
	mylista.add_nodo(3);

	listaB.add_nodo(4);
	listaB.add_nodo(5);
	listaB.add_nodo(6);*/
    cout << "la lista A es " <<endl;
    mylista.print_lista();
    cout << "la lista B es " <<endl;
    listaB.print_lista();
    //nodo* C = ordenar(mylista.head,listaB.head);
    nodo* C = ordenarN(mylista.head,listaB.head);
    lista R;
    R.head=C;
    R.print_lista();


}
