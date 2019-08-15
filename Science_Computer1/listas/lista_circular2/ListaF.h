template <class G>
class nodo
{
    public:
        G valor;
        nodo<G>* next=nullptr;
        nodo(G v_valor, nodo<G>* n_next = nullptr) {
        valor = v_valor;
        next = n_next;
        }

};
template <class I,class R>
class lista
{
    public:
        nodo<I>*head=NULL;// cabeza
        nodo<I>*tail=NULL;// ultimo
        lista(){tail=head;}

        typedef R _itlista;
        nodo<I>* begin(){
            return head;
        }
    bool find(I dato, nodo<I>*&ptr){
            ptr=nullptr;
            for(nodo<I>*p=head;p&&p->valor<=dato;ptr=p,p=p->next){
                if(p->valor==dato){
                 return true;}
                if(head->valor > dato){break;}
            }
            return false;
    }

    void add(I dato){
            nodo<I>*pos;
            if(!find(dato,pos)){
                if(!pos){
                    if(!head){
                    nodo<I>*tem = new nodo<I>(dato) ;
                    head=tem;
                    tail=head;
                    }
                    else{
                    nodo<I>*tem = new nodo<I>(dato,head);
                    tail=head;
                    head=tem;
                    }
                }
                else{
                    pos->next=new nodo<I>(dato,pos->next);
                    pos=pos->next;
                    if(!pos->next){
                        tail= pos;
                        tail->next= head;
                    }
                }

        }
    }

    void erase(I dato){
        nodo<I>*nuevo;
        if(find(dato,nuevo)){
            if(!nuevo){
                if(head->next== head){
                    delete head;
                    head = nullptr;
                }
                else{
                nodo<I>*tmp=head;
                head=head->next;
                delete tmp;
                tail->next=head;
                }
            }
            else{
                nodo<I>*tmp=nuevo->next;
                if(nuevo->next->next== head){
                    tail= nuevo;
                    tail->next= head;
                }
                else{
                    nuevo->next=nuevo->next->next;
                    delete tmp;}
            }
        }

    }
    void show(){
        nodo<I> *p = head;
            do{
               p= p->next;
            }while(p!= head);

    }
    /*
    ~lista(){
        cout<<"destructor"<<endl;
        while(head){
            erase(head->valor);
        }
    }*/
};

