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
        bool find(T valores, nodo<T> * &p);
        void add(T dato);
        void show(){
            for(nodo<T> *p = head; p ; p=p->next){
                cout<<p->valor<<" - ";
            }
        }
        /*
        void add(T dato){
            nodo<T>* pos, *temp;
            if(!head)
                head = new nodo<T> (dato);
            else{
                if(!find(dato, pos))
                {
                    temp = ne
                    nodo<T>(dato);
                    if(!pos){
                        head = temp;
                    }
                    else{
                        temp-> next = pos->next;
                        pos->next = tem;
                    }
                }
            }
        }*/



    protected:

    private:
};
template<typename T>
bool lista<T>::find(T valores, nodo<T> *&p){
    for(nodo<T> *p = head; p && p->valor <= valores; p=p->next){}
        if(p && p->valor== valores)
            return true;
        return false;
}
template<typename T>
void lista<T>::add(T dato){
    nodo<T>* pos;
    if(find(dato,pos)== false){
        if(!pos)
            head = new nodo<T>(dato,head);
        else{
            //nodo<T> *temp = pos;
            pos->next = new nodo<T>(dato,pos->next);
            }
        }
    }
#endif // LISTA_H
