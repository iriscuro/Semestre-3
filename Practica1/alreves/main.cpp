#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string reves(string &palabra){
    int t=palabra.length();
    string li= " ";
    int r=0;
    string ax;
    for(int a=t-1;a>=0;a--){
        ax=palabra[a];
        //cout<<ax<<endl;
        li.insert(r,ax);
        r++;
        //cout <<r<<endl;
    }
    return li;
}
int main()
{
    //Pregunta 1:

    string cadena = "Algebra abstracta es mi curso favorito";
    //cout<<" Texto original:\t";
    //getline(cin,cadena);
    //cout<<cadena<<endl;
    //string str (cadena);
    /*
    string::iterator it;
    cout<<" inverso:\t";
    //for ( it=str.end(); it!=str.begin(); --it)
    for ( it=cadena.end(); it!=cadena.begin(); --it)
        cout << *it;
    cout<<*it--;
    cout << '\n';
    */
    cadena=reves(cadena);
    cout<< cadena<<endl;
    return 0;
}
