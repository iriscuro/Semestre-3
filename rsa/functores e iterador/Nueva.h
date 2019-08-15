#ifndef NUEVA_H
#define NUEVA_H
#include <iostream>
using namespace std;

class Nueva
{
    public:
        int x;
        //PRUEBA
        /*
        Nueva(){cout << "Hello, how are you?"<<endl;}
        void operator()(){
        cout<<"I am here"<<endl;
        }*/
        Nueva(int _x):x(_x){}
        double operator()(int y){
            x=x+y;
            return x;
        }
};

#endif // NUEVA_H
