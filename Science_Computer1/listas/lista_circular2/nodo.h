#ifndef NODO_H
#define NODO_H
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

#endif // NODO_H
