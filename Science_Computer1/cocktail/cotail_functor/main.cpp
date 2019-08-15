/*#include <iostream>
#include <vector>

using namespace std;

class functor
{
public:
    int operator()(int a,int b){
        return (a < b);
    }
};
template < typename F>
class cocktail
{
    public:
    int* arreglo;
    F m;
    cocktail(int* _arreglo):arreglo(_arreglo){
    }
    void swapP(int *a, int  *b){
        int n= *a;*a=*b;
        *b=n;
    }
    void ordenar(int tam){
        int *ini=arreglo;int *fin=(arreglo+tam-1);
        int *A=ini;int *B=fin;bool swapC=1;
        ini=ini+1;fin=fin-1;
        while(swapC){
            if(ini<=fin){
                if(A<=fin){
                    if(m(*(A+1),*A)){
                        swapP(A,(A+1));
                    }A++;
                }
                else{
                if(B>=ini){
                    if(m(*B,*(B-1))){
                        swapP(B,(B-1));}
                        B--;}
                    else{
                    fin--;B=fin;
                    ini++;A=ini;}
                    }
                }
                else{swapC=0;}
                }
        }

};
int main(){

    int numeros[]={1,23,2,45,13,89,100,20,76,30};
    cocktail<functor> a(numeros);
    int tam=sizeof(numeros)/sizeof(*numeros);
    cout << "tam: "<<tam<<endl;


    for(int i=0;i<tam;i++){
        cout<<numeros[i]<<" ";
    }
    cout<<endl;

    a.ordenar(tam);

    cout<<endl;

    for(int i=0;i<tam;i++){
        cout<<numeros[i]<<" ";
    }
    return 0;
}*/
//Liata con funtores


#include <iostream>
//#include <vector>

using namespace std;

template<typename R>
class Iterador
{
    R* it;
    public:
    void operator = (R* nod){
     it = nod;
    }
    R* operator ++(int ){
        return it = it->next;
    }
    int operator *(){
        return it->valor;
    }
    bool operator !=(R* algo){
        return (it!=algo);
    }
};

template <typename T>

class nodo
{
    public:
        T valor;
        nodo<T>* next;
        nodo(T v_valor, nodo<T>* n_next = nullptr)
        {
        valor = v_valor;
        next = n_next;
        }
        virtual ~nodo() {}

};
template<typename T,typename R>
class lista
{
    public:

        nodo<T>* head;
        lista(){
            head = nullptr;
        }

        typedef R _iterador ;
        nodo<T>* begin(){
            return head;
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
template<typename T,typename R>
bool lista<T,R>::find_nodo(T valores, nodo<T> *&ptr){
    ptr = nullptr;
    for(nodo<T> *p = head; p && p->valor <= valores;ptr = p,p=p->next){
        if( p->valor== valores){
            cout<<"\nptr: "<< p->valor<<endl;
            return true;
        }
    }
    return false;
}
template<typename T,typename R>
void lista<T,R>::add_nodo(T dato){
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
template<typename T,typename R>
void lista<T,R>::erase_nodo(T dato){
    nodo<T>* pos;
    nodo<T>* tem;
    if(find_nodo(dato,pos)== true){
        if(!pos){//null;
            tem = head;
            head= head->next;
            delete tem;
            }
        else{
            tem = pos->next;
            pos->next = pos->next->next;
            delete tem;
            }
    }
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
int main(){
    //MERGE SORT
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
/*
#include "headers.h"
class isOdd {

public:
    bool operator() ( int x ) {
        return x % 2;
    }
};

class isEven {

public:
    bool operator() ( int x ) {
        return ! ( x % 2 );
    }
};

class isMultiple {

private:
    int m_multi;
public:
    isMultiple ( int multi ) : m_multi {multi} {}
    bool operator() ( int x ) {
        return ! ( x % m_multi );
    }

};
int main ( int argc, char** argv ) {
    vector<int> col {1, 2, 3, 4, 5, 7, 9, 13, 14, 15, 19};

    int cOdd, cEven, cMulti, multi {5};

    cOdd = count_if ( begin ( col ), end ( col ), isOdd() );
    cEven = count_if ( begin ( col ), end ( col ), isEven() );
    cMulti = count_if ( begin ( col ), end ( col ), isMultiple ( 5 ) );


    cout << "Number of integers that are odd : " << cOdd << endl;
    cout << "Number of integers that are even : " << cEven << endl;
    cout << "Number of integers that are multiple of " << multi
         << " : " << cMulti << endl;

    return ( 0 );
}
*/
