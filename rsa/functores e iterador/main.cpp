#include <iostream>
#include <vector>
#include "Nueva.h"
using namespace std;
template <typename G>
void tabla(G f){
    cout<< "***TABLA***"<<endl;
    for(int i=0;i<=10;i++){
        cout<<f(i)<<endl;
    }
}
struct functor{
    void operator()(){
        cout<< "I am here,now"<<endl;
    }
};
template <typename T, typename G>
struct opera{
    T suma(T a,T b){
        G c;
        c();
        return a+b;
    }
};
template<class T, class I>
class vectore{
    T a[10];
public:
    typedef I it_vector;
    T* begin(){
    return &a[0];}
    T* end(){
    return &a[9];}
};
int main()
{
    //iTERADORES
    vectore<int,Iterator<int>> Ent;
    vectore<int , Iterador<int>>:: it_vector it;
    for(it =Ent.begin();it<= Ent.end();it++)
    {cout<< "Ingrese un numero: ";
    cin>> it;
    }
    for(it = Ent.begin();it<=Ent.end();
    //TAREA Functores
    int numeros[]={1,23,2,45,13,89,100,20,76,30};
    int tam=sizeof(numeros)/sizeof(*numeros);
    cout << "tam: "<<tam<<endl;


    int *inici=numeros;
    int *finle=&numeros[tam-1];
    //imprimir el array original
    while(inici<=finle){
        cout<<*(inici)<<" ";
        inici++;
    }
    cout<<endl;
    bool(*p)(int,int)=mayor;
    //bool(*p)(int,int)=menor;
    cocktail(numeros,tam,p);

    cout<<endl;

    for(int i=0;i<tam;i++){
        cout<<numeros[i]<<" ";
    }
/*
   vector<int> vec;
   int i;
   cout << "vector size = " << vec.size() << endl;
   for(i = 0; i < 5; i++){
      vec.push_back(i);
   }
   cout << "extended vector size = " << vec.size() << endl;
   // access 5 values from the vector
   for(i = 0; i < 5; i++){
      cout << "value of vec [" << i << "] = " << vec[i] << endl;
   }
   // use iterator to access the values
   vector<int>::iterator v = vec.begin();
   while( v != vec.end()) {
      cout << "value of v = " << *v << endl;
      v++;
   }
 cout << vec[2]<<endl;

   return 0;
}
*/
/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
// An empty vector of vectors. The space
// between the 2 '>' signs is necessary
   vector<vector<int> > v2d;

// Now we'll try to create a 3 by 5 "matrix".
// First, create a vector with 5 elements
   vector<int> v2(5, 0);

// Now create a vector of 3 elements.
// Each element is a copy of v2
   vector<vector<int> > v2d2(3,v2);

// Print out the elements
   for(int i=0;i<v2d2.size(); i++) {
      for (int j=0;j<v2d2[i].size(); j++)
        cout << v2d2[i][j] << " ";
      cout << endl;
   }
	v2d2[2].push_back(4);
cout << "aaaaa"<< endl;
for(int i=0;i<v2d2.size(); i++) {
      for (int j=0;j<v2d2[i].size(); j++)
        cout << v2d2[i][j] << " ";
      cout << endl;
   }
	v2d2[0][0]=3;
cout << "aaaaa"<< endl;
for(int i=0;i<v2d2.size(); i++) {
      for (int j=0;j<v2d2[i].size(); j++)
        cout << v2d2[i][j] << " ";
      cout << endl;
   }
}
*/  //Ejemplo 1
    /*
    opera<int,functor> o;
    functor f;
    cout<< o.suma(2,5)<<endl;*/

    //Ejemplo 2
    /*
    Nueva a(2);
    tabla(Nueva(2));
    tabla(a);*/

    //cout<<a(3)<<endl;

    return 0;
}
