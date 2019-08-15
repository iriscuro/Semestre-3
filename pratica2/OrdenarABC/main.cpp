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
    }
}
int main()
{
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
    /*setlocale(LC_CTYPE,"Spanish");
    int clave=1;
    string mensaje;
    string cifrado;
    string descifrado;
    cout <<"Mensaje: \n";
    getline(cin,mensaje);

    cout <<"Cifrado zigzag: ";

    string palabra;
    int tam=mensaje.size();
    //cout<<tam<<endl;
    int esp=espacio(clave);
    int p=0;
    int pos=0;
    int tem=esp;
    while(p<clave){
        pos=p;
        int temp1;
        int temp2;
        temp1 = espacio(clave) - pos * 2;
        temp2 = espacio(clave) - temp1;
        while(pos<tam){
            palabra += mensaje[pos];
            if(p==0 || p == clave-1){
                pos+=tem;
            }
            else{
                pos+=temp1;//ACTUALIZO ESPACIO recien actual. + el nuevo espaciado
                swap(temp1,temp2);
            }
        }
        esp-=2;
        p++;
    }
    cout<< palabra<<endl;*/
    /*
    setlocale(LC_CTYPE,"Spanish");
    int clave=5;
    string mensaje;
    string cifrado;
    string descifrado;
    cout <<"MensajeDesencriptado: \n";
    getline(cin,mensaje);

    cout <<"Descifrado zigzag: ";

    string palabra=mensaje;
    int tam=mensaje.size();
    //cout<<tam<<endl;
    int esp=espacio(clave);
    int p=0;
    int i = 0;
    int pos=0;
    int tem=esp;
    while(p<clave){
        pos=p;
        int temp1;
        int temp2;
        temp1 = espacio(clave) - pos * 2;
        temp2 = espacio(clave) - temp1;
        while(pos<tam){
            palabra[pos] = mensaje[i];
            if(p==0 || p == clave-1){
                pos+=tem;
            }
            else{
                pos+=temp1;//ACTUALIZO ESPACIO recien actual. + el nuevo espaciado
                swap(temp1,temp2);
            }
            i++;
        }
        esp-=2;
        p++;
    }
    cout<< palabra<<endl;*/
    return 0;
}
