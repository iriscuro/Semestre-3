#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void separar(string &palabra,string &separador){
    string str;
    size_t t= palabra.size();
    size_t pos=0;
    while( pos<=t){
        pos= palabra.find(separador);
        str= palabra.substr(0,pos);//extraer la palabra antes del caracter de separacion
        cout<<str<<endl;
        palabra= palabra.substr(pos+1);
        t=palabra.size();
        }
}
int main()
{
    string pal,pal2,str;
    cout << " string completo :\t";
    getline(cin,pal);
    cout<<"String de separacion:\t";
    cin>>pal2;
    separar(pal,pal2);
    return 0;
}
