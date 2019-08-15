#include <iostream>

using namespace std;

int main()
{
   //Pregunta 2

    int cont=0;
    string pal1= "abaabbababababbba";
    string pal2= "aba";
    //cout << "Primer string:\t";
    //cin>>pal1;
    //cout<<"Segundo string:\t";
    //cin>>pal2;
    size_t t2=pal2.size();
    size_t pos = 0;
    while( pos!= std::string::npos){
        pos= pal1.find(pal2);
        pal1= pal1.substr(pos+t2);//extraigo dede la pos hasta el final
        cont++;
    }
    cout << cont<<endl;
    return 0;
}
