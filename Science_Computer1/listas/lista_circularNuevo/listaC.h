#ifndef LISTAC_H
#define LISTAC_H
#include "nodo.h"
#include <iostream>

using namespace std;

template<class I>
class listaC
{
    public:
        nodo<I> *head;
        listaC() {head=nullptr;}
        bool encontrar(I dato,nodo<I>*& ptr){
            ptr = nullptr;
            nodo<I>* p= head;
            if(!head){
                return false;
            }
            else{
                do{
                    if(p->valor == dato){
                        return true;
                    }
                    if(head->valor > dato){break;} //ptr = nullptr

                    ptr=p;
                    p=p->next;
                }while(p!=head && p->valor <= dato);
                return false;
            }
        }
        void agregar(I dato){
            nodo<I> *pos;
            if(!encontrar(dato,pos)){
                if(!pos){
                    head = new nodo<I>(dato,head);
                    nodo<I> *tmp=head;
                    if(head->next!=nullptr){
                        nodo<I> * ult = tmp->next;
                        do{
                           ult= ult->next;
                        }while(ult->next!=tmp->next);
                        ult->next = head;
                    }
                    else{
                        tmp->next = head;
                    }
               }
               else{
                    pos->next = new nodo<I>(dato,pos->next);
               }
            }
        }
        void eliminar(I dato){
            nodo<I> *pos;
            if(encontrar(dato,pos)){
                if(!pos){
                    if(head->next== head){
                        delete head;
                        head = nullptr;
                    }
                    else{
                        nodo<I>*e= head;
                        head= head->next;
                        nodo<I> *u= head;
                        do{
                           u= u->next;
                        }while(u->next!=e);
                        u->next=head;
                        delete e;
                    }
                }
                else{
                    nodo<I>*e= pos->next;
                    pos->next= pos->next->next;
                    delete e;
                }
                //cout<< "\nborrado"<<endl;
            }

        }


        void mostrar(){
            nodo<I> *p = head;
            do{
               cout<<p->valor<<" ";
               p= p->next;
            }while(p!= head);
            cout<<"siguiente: "<<head->valor<<endl;
        }
        //~listaC() {}

};

#endif // LISTAC_H
