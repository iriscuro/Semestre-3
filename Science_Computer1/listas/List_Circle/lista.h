#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"
#include <iostream>
using namespace std;
template <class T>

class lista
{
    public:
        nodo<T>*head=NULL;// cabeza
        nodo<T>*tail=NULL;// ultimo
        lista(){
            tail=head;
        }
        bool find(T dato, nodo<T>*&ptr){
            ptr=nullptr;
            for(nodo<T>*p=head;p&&p->valor<=dato;ptr=p,p=p->next){
                if(p->valor==dato){cout<< "encontro: "<<endl;
                    return true;}
            }cout<< "no encontro: "<<endl;
            return false;
        }
        void add(T dato){
            nodo<T>*pos;
            if(!find(dato,pos)){
                nodo<T> *tem ;
                if(!pos){// pos es nulo
                    if(!head){// no hay cabeza
                       // cout<< "tail no cab "<<tail<<endl;
                        tail=head;
                    }
                    //tem = head;
                    head=new nodo<T>(dato,head);cout<<"crea nodo"<<endl;
                    //cout<< "tail->valor "<<tail<<endl;
                }
                else{
                    if(!pos->next){cout<<"pos->next esta vacio"<<endl;
                        pos->next=new nodo<T>(dato,pos->next);
                        tail= pos->next;
                        tail->next= head;
                        cout<< "tail "<<tail->valor<<endl;
                    }
                    else{
                        pos->next=new nodo<T>(dato,pos->next);
                        cout<<"pos->next diferente de nulo"<<endl;
                    }/*
                    pos=pos->next;
                    if(!pos->next){cout <<"actualiza tail"<<endl;
                        tail=pos;
                        tail->next=head;
                    }*/
            }
        }
    }
    void erase(T dato){
        nodo<T>*nuevo;
        if(find(dato,nuevo)){
            if(!nuevo){
                nodo<T>*tmp=head;
                head=head->next;
                delete tmp;
            }
            else{
                nodo<T>*tmp=nuevo->next;
                nuevo->next=nuevo->next->next;
                delete tmp;
            }
        }

    }
    void show(){
        nodo<T>*d=this->head;
        if(!d)
            cout<<"la lista esta vacia....."<<endl;
        else{int c=0;
            do{
                cout<<d->valor<<"  ";
                d=d->next;
                c++;
            }while(c<5);
            cout<<" tail "<<tail->valor<<endl;
        }
    }/*
    ~lista(){
        cout<<"destructor"<<endl;
        while(head){
            erase(head->valor);
        }
    }*/
};

#endif // LISTA_H
