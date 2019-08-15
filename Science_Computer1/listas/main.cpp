#include <iostream>
#include "lista.h"
using namespace std;

void ordenar(lista<int> A,lista<int> B){// no funciona bien
    nodo<int> *cent1;
    cent1=A.head;
    nodo<int> *cent2;
    cent2=B.head;
    nodo<int> *tejas;
	tejas=A.head;
	cout<<"Recorriendo la lista"<<endl;
    while(tejas){
        nodo<int>* aux1;
        nodo<int> *aux2;
        cout<<tejas->valor<<" ";
        if(cent1->valor <= cent2->valor){
                aux1=cent1->next;cent1->next=cent2;
        }
        else{cent2->next=cent1;}
        tejas =tejas->next;
        cent1=aux1;
    }
    cout<<endl;
    A.show_lista();
}
nodo<int>* ordenarL_U(lista<int> A,lista<int> B){//Funciona correctamente
    nodo<int> *stardA = A.head;
    nodo<int> *stardB = B.head;
    nodo<int> *tejas = A.head;
    cout<<"Recorriendo la lista"<<endl;
    while(stardA && stardB){nodo<int> *gancho;
        cout<<tejas->valor<<" ";
           if(stardA->valor <= stardB->valor){
              gancho=stardA->next;
              tejas->next = stardA;
              stardA = gancho;
          }
          else{gancho = stardB->next;
            tejas->next = stardB;
            stardB = gancho;
          }
          tejas=tejas->next;
    }
    if(stardA){
      tejas->next = stardA;}
    if(stardB){
      tejas->next = stardB;
    }

    cout<<endl;
    return A.head;
}
nodo<int>* ordenarL(nodo<int> *stardA ,nodo<int> *stardB){
    nodo<int> *stardT = stardA;
    nodo<int> *tejas = stardA;
    cout<<"Recorriendo la lista"<<endl;
    while(stardA && stardB ){nodo<int> *gancho;
        cout<<tejas->valor<<" ";
           if(stardA->valor <= stardB->valor){
              gancho=stardA->next;
              tejas->next = stardA;
              stardA = gancho;
          }
          else{gancho = stardB->next;
            tejas->next = stardB;
            stardB = gancho;
          }
          tejas=tejas->next;
    }
    if(stardA){
      tejas->next = stardA;}
    if(stardB){
      tejas->next = stardB;
    }

    cout<<endl;
    return stardT;
}
int main()
{   //LISTAS ENLAZADAS SIMPLE
    // Funciona correctamente
    /*
    lista<int> lista;
    lista.add(1);
    lista.add(7);
    lista.add(3);
    lista.add(2);
    lista.add(5);
    lista.show();
    lista.erase(3);
    lista.erase(1);
    lista.erase(7);
    //lista.add(9);
    lista.show();*/

    //MERGE SORT
    lista<int> mylista;/*
	mylista.add_nodo(1);
	mylista.add_nodo(3);
	mylista.add_nodo(5);
	mylista.add_nodo(7);*/

	lista<int> listaB;/*
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

	cout << "la lista A es " <<endl;
    mylista.show_lista();
    cout << "la lista B es " <<endl;
    listaB.show_lista();
    nodo<int>* C = ordenarL(mylista.head,listaB.head);//FUNCIONA
    lista<int> R;
    R.head=C;
    R.show_lista();
    return 0;
}
