#include <fstream>
#include <iostream>
#include <string>

using namespace std;

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
/*
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
*/
//ordenar
/*
para i=1 hasta n-1
    minimo = i;
    para j=i+1 hasta n
        si lista[j] < lista[minimo] entonces
            minimo = j
        fin si
    fin para
    intercambiar(lista[i], lista[minimo])
fin para
*/
void alafavetic(string lista[],int canti){
    int min;
    for(int i=1;i<=canti-1;i++){
        min=i;
        for(int j=i+1;j<=canti;j++){
            if(lista[j]<lista[min])
                min = j;

        }
        lista[i].swap(lista[min]);
    }
    for(int i=1;i<=canti-1;i++)
        cout << lista[i]<<" ";
}
int main()
{
    //pregunta 6
/*
    string cadena,palabras;
    int n;
    cout << " string con espacios ord. alfab. :\t";
    getline(cin,cadena);
    size_t t=cadena.size();
    string separador;
    int npal=cantPalaenStr(cadena);
    cout<<"n de palb, " <<npal<<endl;
    cout<<" cantidad de palabras:\t";
    cin>> n;
    cout <<" las palabras: \n";
    for(int i=0;i<n;i++){
        cin>>palabras;
        cadena=ordenadorAlfab(cadena,palabras);
        palabras="";
    }
    cout<<cadena<<endl;*/

    string cadena = "avion cola numero";
    int cantp=0;
    string palabras = "";
    cout<<" cantidad de palabras:\t";
    cin>> cantp;
    int t=3+cantp;
    string words[3+cantp];

    //llenar matriz

    string aux;
    for(int i=0;i<3;i++){
        int found = cadena.find(" ");
        cout << found<<endl;
        aux=cadena.substr(0,found);
        cout<<aux<<endl;
        cadena=cadena.substr(found+1);
        cout<<cadena<<endl;
        words[i]=aux;
    }
    //impresion 1
    /*
    for(int i=0;i<3;i++){
         cout <<words[i]<<" ";
    }
*/
    //llenar matriz con nuevas palabras
    for(int i=3;i<t;i++){
        cin>>palabras;
        words[i]=palabras;
    }
    //impresion
    for(int i=0;i<cantp;i++){
         cout <<words[i]<<" ";
    }


    return 0;
}
