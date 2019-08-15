#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    /*
    int cont=0;
    string pal1,pal2;
    cout << "Primer string:\t";
    cin>>pal1;
    cout<<"Segundo string:\t";
    cin>>pal2;
    size_t t2=pal2.size();
    size_t pos = 0;
    while( pos!= std::string::npos){
        pos= pal1.find(pal2);
        pal1= pal1.substr(pos+t2);//extraigo dede la pos hasta el final
        cont++;
    }
    */
    //cout << cont<<endl;
    int cont =0;
    std::string str="abaabbababababbba";

    std::size_t pos = str.find("aba");
    while( pos!= std::string::npos){
        pos= str.find("aba");
        str= str.substr(pos+3);//extraigo dede la pos hasta el final
        cont++;
    }
    cout << cont << '\n';
    return 0;
}
