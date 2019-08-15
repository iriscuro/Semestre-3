#ifndef ITERADOR_H
#define ITERADOR_H


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

#endif // ITERADOR_H
