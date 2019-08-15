#include <iostream>
#include "rsa.h"
using namespace std;


int main()
{
	cout<<"RECEPTOR: ";
	rsa Receptor;

	string mensaje= "g";
	cout<<"<clav_pub,N>"<<endl;
	int e,N;
	cin>>e;
	cin>>N;
	rsa Emisor(e,N);
	int cifrado = Emisor.cifrar(mensaje);
	string descifrado = Receptor.descifrar(cifrado);


	//cout<<"escriba el mensaje: "<<endl;
	//getline(cin,mensaje);
	/*
    int cifrado = Emisor.cifrar(mensaje);
	cout<<endl;

	string original = Receptor.descifrar(cifrado);
	cout<<"original: "<<original<<endl;
	*/
}
