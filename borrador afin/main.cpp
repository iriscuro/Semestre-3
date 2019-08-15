#include <iostream>
#include "afin.h"


using namespace std;


int main()
{
    afin emisor;
    //string mensaje= "la valentia es saber que es lo que no debemos temer estamos doblemente armados si luchamos con fe";
    //string mensaje="la musica es para el alma lo que la gimnasia es para el cuerpo-irisRocio";
    //antoni

    //string mensaje="nVGPRs-seR5o9RUo9QVR9eRePGo4P-GP";
     string mensaje="r8W8I 4sIQ8B4mIwOW8qUI6UqQk0kO0 8IoUmI4sI6UquOqkUI 4I6UqU60W04qkUQIUBu4k0iUQIKIi4m0y068Bs4QIQUBm4IOq8IW8k4m08I 4k4mW0q8 8ISO4IQUqIUBk4q0 UQIW4 08qk4Is8IUBQ4mi860DqIKIs8I4go4m0W4qk860Uq";
    string cifrado;
    string descifrado;
    /*
    cout<<"escriba el mensaje: "<<endl;
	getline(cin,mensaje);
	*/
	//string te = emisor.cifrar(mensaje);
    //cout << "Texto encriptado: " << te << endl;

    cout<<"\n";
    //PARA DESCIFRAR
    /*
    int claveA=emisor.get_clave_a();
    int claveB=emisor.get_clave_b();
    */
    /*
    int claveA=5;
    int claveB=42;
*/
    //yerson
    int claveA=31;
    int claveB=61;
    afin receptor(claveA,claveB);

    cout <<"Descifrado afin: "<<endl;
    descifrado=receptor.descifrar(mensaje);
    cout <<descifrado<<endl;
    return 0;
}
