#include <iostream>
#include "lista.h"
using namespace std;

int main()
{
    lista<int> lista;
    lista.add(6);
    lista.add(3);
    //lista.add(7);
    lista.add(5);

    //lista.erase(1);
    //lista.add(9);
    lista.show();
    return 0;
}
