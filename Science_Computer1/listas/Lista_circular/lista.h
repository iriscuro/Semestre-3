#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "nodo.h"
using namespace std;
template <class T>

class lista
{
    public:
    nodo<T>*head=NULL;
    nodo<T>*tail=NULL;

    lista(){

        this->tail=this->head;
    }

    bool find(T dato, nodo<T>*&ptr){
        ptr=nullptr;
        for(nodo<T>*p=head;p&&p->valor<=dato;ptr=p,p=p->next){
            if(p->valor==dato){//cout<<"find "<<ptr->valor<<endl;
                return true;}
        }//cout<<"find f "<<ptr<<endl;
        return false;
    }

    void add(T dato){

        nodo<T>*pos;

        if(!find(dato,pos)){
            if(!pos){cout<<"!pos"<<endl;

                if(!head){cout<<"!head y tail ";

                head = new nodo<T>(dato,head);
                head->next=head;
                //cout<< "T "<<tail<<endl;
                if (head) {
                    nodo<T>tmp(dato);
                    tmp->next=head;
                    head->next=tmp;
                    tmp=head;
                }
                cout<<"creo head porque no habia "<<endl;
                    tail->next=head;cout<<tail<<endl;
                    }
            }
            else
            {
                pos->next=new nodo<T>(dato,pos->next);
                pos=pos->next;
                if(!pos->next){cout <<"actualiza tail"<<endl;
                    tail=pos;
                    tail->next=head;
                }
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
        //cout<<" tail-> "<<tail->valor<<endl;
        if(!d)
            cout<<"la lista esta vacia....."<<endl;
        else{int c=0;
            do{
                cout<<d->valor<<"  ";
                d=d->next;
                c++;
            }while(c<6);
            cout<<" tail-> "<<tail->valor<<endl;
        }
    }
    ~lista(){//destructor
        cout<<"Destructor"<<endl;
        while(head){
            erase(head->valor);
        }
    }
};

#endif // LISTA_H
