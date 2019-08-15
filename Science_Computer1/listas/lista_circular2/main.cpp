#include <iostream>
//#include "lista.h"
#include "listaF.h"
using namespace std;

void Josephus(int turno,int total){//turno
    lista<int> j;
    //lista ordenada con el total
    for(int i=1;i<=total;i++){
        j.add(i);
    }j.show();
    nodo<int> *t=j.head;
    do{
        for(int i=1;i<turno;i++){
            t=t->next;
        }cout<<"\nt: "<<t->valor<<endl;
        int valor=t->valor;
        t=t->next;
        j.erase(valor);cout<<"\nt ne: "<<t->valor<<endl;

    }while(t!=t->next);
    j.show();
}
int main()
{   /*
    lista<int> b;
    b.Josephus(4,10);
    b.show();*/
    //LISTA CIRCULAR SIMPLE falta mejorar
    /*
    lista<int> le;
    le.add(7);//cout<<endl;
    le.add(1);//cout<<endl;
    le.add(5);
    le.show();
    le.add(3);//cout<<endl;
    le.add(9);
    le.show();
    le.erase(9);
    le.show();
*/
    // LISTA CIRCULAR CON FUNCTORES
    lista<int,Iterador<nodo<int> > > mylista;
    lista<int,Iterador<nodo<int> > >:: _iterador i ;
	mylista.add_nodo(1);
	mylista.add_nodo(3);
	mylista.add_nodo(6);
	mylista.add_nodo(9);


    for(i = mylista.begin(); i!=0;i++)
        cout<<*i<<" -> ";

    return 0;
}
