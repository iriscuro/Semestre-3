#include "nodo.h"
#include <iostream>
template <class T>
using namespace std;
nodo::nodo(T v_valor, nodo n_next = nullptr )
{
    valor = v_valor;
    next = n_next;
}

nodo::~nodo()
{
    //dtor
}
