#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string invS(string cadena){
    string str (cadena);
    string inverso,a;
    string::iterator it;
    for ( it=str.end(); it!=str.begin(); --it){
        //inverso.push_back(a);
        *it--;
    }
    return inverso;
}

bool palindrome(string palabra){
    size_t i=0,f;
    size_t t=palabra.size();
    cout<<t<<endl;
    size_t it =t/2;
    f=t-1;
    //mit1= palabra.substr(0,it);
    //cout<<mit1<<endl;
    //mit2= palabra.substr(it);
    //cout<<mit2<<endl;
    while(i<=it){
        if(palabra[i]==palabra[f])  {
            i++;
            f--;
        }
        else
            break;

    }
    if(i-1==it)
        return true;
    else
        return false;
}
/*
int cantPalaenStr(string princ){
    int cont=0;
    size_t t= princ.size();
    cout <<"t "<<t<<endl;
    size_t pos=0;
    while( pos<t && (princ!= " " || princ!="")){
        pos= princ.find(" ");
        if(pos!=string ::npos){
            cont++;
            break;
        }
        else{
            cout <<"pos "<<pos<< " pal "<<princ<<endl;
            cont++;
            princ= princ.substr(pos+1);
            cout<< "recorte "<<princ<<endl;
            t=princ.size();
        }

        }
    return cont;
}
*/
int cantPalaenStr(string princ){
    int cont=0;
    size_t pos=0;
    pos= princ.find(" ");
    //cout << pos<<endl;
    while(pos!=string::npos){
        //cout <<"pos "<<pos<< " pal "<<princ<<endl;
        cont++;
        princ.erase(princ.begin()+pos);
        //cout<< "sin espacio  "<<princ<<endl;
        pos= princ.find(" ");
        }
    return cont+1;

}



string ordenadorAlfab(string princ,string palabra){
    size_t t=princ.size();
    if(palabra[0]>princ[0]){
            princ.insert(t," "+palabra);
            t=princ.size();
        }
    else {
        princ.insert(0,palabra+" ");
        t=princ.size();
    }
    return princ;
}
int main()
{

    //Pregunta 2
    /*
    int cont =0;
    std::string str="abaabbababababbba";

    std::size_t pos = str.find("aba");
    while( pos!= std::string::npos){
        pos= str.find("aba");
        str= str.substr(pos+3);//extraigo dede la pos hasta el final
        cont++;
    }
    cout << cont << '\n';
    */
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
    cout << cont<<endl;
*/
    //Pregunta 4
    /*
    Recibir dos strings por consola. Dividir el primer string usando el segundo como separador de
    elementos. Imprimir cada uno de los substrings en una nueva línea. El primer string puede
    contener espacios en blanco.
    Ejemplo:
    Input:
    Hola,como,estas
    ,
    Output:
    Hola
    como
    estas
    */
    //funciona cin
/*
    int cont=0;
    string pal1,pal2,str;
    cout << "Primer string:\t";
    getline(cin,pal1);
    cout<<"String de separacion:\t";
    cin>>pal2;
    size_t t= pal1.size();
    size_t pos=0;
    while( pos<=t){
        pos= pal1.find(pal2);
        str= pal1.substr(0,pos);//extraer la palabra antes del caracter de separacion
        cout<<str<<endl;
        pal1= pal1.substr(pos+1);
        t=pal1.size();
        }

    cout <<endl;
    */
    //pregunta 5
    /*5. Recibir una cadena por consola y determinar si la cadena es palíndromo o no. Devuelve “SI” en
    caso de que la cadena sea palíndromo y “NO” en el caso contrario.
    Ejemplo:
    Input:
    acbca
    Output:
    SI
    */
    /*
    int i=0;
    string palabra,mit1,mit2;
    cout << " string:\t";
    cin>>palabra;
    bool p=true;
    size_t t=palabra.size();
    size_t it =t/2;
    if(palindrome(palabra)==1){
        cout<<" SI \n";
    }
    else
        cout <<" NO \n";
        */
    //Pregunta 6
    /*
    Recibir un string con espacios que representa una lista de palabras ordenadas alfabéticamente,
    un entero n y n palabras. Insertar las n palabras en el string de la lista de palabras, manteniendo
    el orden alfabético. Imprimir el string de la lista de palabras resultante.
    Ejemplo:
    Input:
    avion cola numero
    3
    abreviatura
    perro
    destino
    Output:
    abreviatura avion cola destino numero perro*/
/*
    string cadena,palabras;
    int n;
    cout << " string con espacios ord. alfab. :\t";
    getline(cin,cadena);
    size_t ta=cadena.size();
    int npal=cantPalaenStr(cadena);
    //cout<<"n de palb, " <<npal<<endl;
    cout<<" cantidad de palabras:\t";
    cin>> n;
    cout <<endl;
    cout <<" las palabras: \n";
    for(int i=0;i<n;i++){
        cin>>palabras;
        cadena=ordenadorAlfab(cadena,palabras);
        palabras="";
    }
    cout<<cadena<<endl;
*/
    return 0;
}
