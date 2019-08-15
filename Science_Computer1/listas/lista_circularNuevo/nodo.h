#ifndef NODO_H
#define NODO_H

template<class I>
class nodo
{
    public:
        I valor;
        nodo* next;
        nodo(I v_valor,nodo* n_next = nullptr) {
            valor =v_valor;
            next = n_next;
        }
        //~nodo() {} para verificar que esta bien el destructor de la lista
};

#endif // NODO_H
