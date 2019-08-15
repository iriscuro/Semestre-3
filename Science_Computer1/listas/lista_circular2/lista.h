#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"
#include <iostream>
using namespace std;
template <class I>
class lista
{
    public:
        nodo<I>*head=NULL;// cabeza
        nodo<I>*tail=NULL;// ultimo
        lista(){tail=head;}

    bool find(I dato, nodo<I>*&ptr){
            ptr=nullptr;
            for(nodo<I>*p=head;p&&p->valor<=dato;ptr=p,p=p->next){
                if(p->valor==dato){//cout<< "encontro el dato"<<endl;
                 return true;}
                if(head->valor > dato){break;}
            }//cout<<"no encontro"<<endl;
            return false;
    }

    void add(I dato){
            nodo<I>*pos;
            if(!find(dato,pos)){
                if(!pos){// pos es nulo
                    if(!head){// no hay cabeza cout<<"crea head"<<endl;
                    nodo<I>*tem = new nodo<I>(dato) ;
                    head=tem;
                    tail=head;
                    }
                    else{//cout<<"crea nuevo head"<<endl;
                    nodo<I>*tem = new nodo<I>(dato,head);
                    tail=head;
                    head=tem;//cout<<head->valor<<" "<<head->next->valor<<endl;
                    }
                }
                else{//cout<< "anade nodo en medio o final"<<endl;
                    pos->next=new nodo<I>(dato,pos->next);
                    pos=pos->next;
                    if(!pos->next){//pos->next nulo
                        tail= pos;
                        tail->next= head;//cout<< ": en final"<<endl;
                    }
                }

        }
    }

    void erase(I dato){
        nodo<I>*nuevo;
        if(find(dato,nuevo)){
            if(!nuevo){//pos igual a null cout<<"no hay nuevo"<<endl;
                if(head->next== head){
                    delete head;
                    head = nullptr;
                }
                else{
                nodo<I>*tmp=head;
                head=head->next;
                delete tmp;
                tail->next=head;//cout<<"elimina al inicio"<<endl;
                }
            }
            else{//pos difernte de null
                nodo<I>*tmp=nuevo->next;//cout<<"Eliminar cuando pos es diferente de null "<<nuevo->valor<<endl;
                if(nuevo->next->next== head){//pos->next nulo
                    tail= nuevo;
                    tail->next= head;//cout<< "elimino el final"<<endl;
                }
                else{//cout<<"elimino el siguiente de pos"<<endl;
                    nuevo->next=nuevo->next->next;
                    delete tmp;}
            }
        }

    }
    void show(){
        nodo<I> *p = head;
            do{
               cout<<p->valor<<" ";
               p= p->next;
            }while(p!= head);
            cout<<"tail: "<<tail->valor<<endl;
            cout<<"tail->next: "<<tail->next->valor<<endl;
    }
    /*
    ~lista(){
        cout<<"destructor"<<endl;
        while(head){
            erase(head->valor);
        }
    }*/
};

#endif // LISTA_H

