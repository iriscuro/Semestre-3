#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"
#include <iostream>
using namespace std;
template<typename T>
class lista
{
    public:
        nodo<T>* head;
        lista(){
            head = nullptr;
        }
        bool find_nodo(T valores, nodo<T> * &p);
        void add_nodo(T dato);
        void erase_nodo(T dato);
        void show_lista(){
            for(nodo<T> *p = head; p ; p=p->next){
                cout<<p->valor<<" - ";
                if(p->next==0)cout<<"nulo\n";
            }
        }

};
template<typename T>
bool lista<T>::find_nodo(T valores, nodo<T> *&ptr){
    ptr = nullptr;
    for(nodo<T> *p = head; p && p->valor <= valores;ptr = p,p=p->next){
        if( p->valor== valores){
            cout<<"\nptr: "<< p->valor<<endl;
            return true;
        }
    }
    return false;
}
template<typename T>
void lista<T>::add_nodo(T dato){
    nodo<T>* pos;
    if(find_nodo(dato,pos)== false){
        if(!pos) // vacio
            head = new nodo<T>(dato,head);
        else{
            //nodo<T> *temp = pos;
            pos->next = new nodo<T>(dato,pos->next);
            }
        }
    }
template<typename T>
void lista<T>::erase_nodo(T dato){
    nodo<T>* pos;
    nodo<T>* tem;
    if(find_nodo(dato,pos)== true){
        if(!pos){//null;
            tem = head;
            head= head->next;cout<< "elimino "<<tem->valor<<endl;
            delete tem;
            }
        else{
            tem = pos->next;
            pos->next = pos->next->next;cout<< "elimino "<<tem<<endl;
            delete tem;
            }
    }
}
#endif // LISTA_H
