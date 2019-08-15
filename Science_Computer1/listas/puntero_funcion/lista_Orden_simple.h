
#include <iostream>
using namespace std;

class nodo
{
  public:
  int valor;
  nodo*sig;
  nodo(int valor=0)
    {
      this->valor=valor;
      sig=NULL;
    }
  };

class lista
{
  public:
  nodo *head;
  lista()
  {head=NULL;}

  void add_nodo(int valor)
  {

    if(head == NULL){
      nodo *cent= new nodo(valor);
      head=cent;
      }
    else
     {
       nodo *aux=head;
       while(aux->sig != NULL)
         {aux=aux->sig;}
       nodo *cent= new nodo(valor);
       aux->sig = cent;
     }
  }

  void print_lista()
  {
    nodo *cent;
    cent=head;
    if(cent == NULL)
    {cout<<"La lista sta vacia"<<endl;return;}
    whD:\Semestre_III\Ciencia de la Computación II\listas\puntero_funcion\puntero_funcion.cbpile(cent){
        cout<<cent->valor;
        cout<<"-> ";
        cent =cent->sig;
    }
	cout<<endl;
  }

};

