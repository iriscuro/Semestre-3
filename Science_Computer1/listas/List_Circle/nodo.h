#ifndef NODO_H
#define NODO_H
template <typename T>

class nodo
{
    public:
        T valor;
        nodo<T>* next=nullptr;
        nodo(T v_valor, nodo<T>* n_next = nullptr)
        {
        valor = v_valor;
        next = n_next;
        }
        virtual ~nodo() {}

    private:
};

#endif // NODO_H
