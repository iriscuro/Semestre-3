#include <iostream>
#include <rsa.h>
using namespace std;
string leer(string name)
{
        setlocale(LC_ALL, "");

    ifstream lectura;
    lectura.open( name+".txt", ios::binary );

    string sms, linea;

    while(getline(lectura, linea))
        sms += linea;

    cout << linea<<endl;
    lectura.close();
    return sms;
}

void escribir(string name,string sms)
{
    setlocale(LC_ALL, "");
    ofstream escritura;
    escritura.open( name+".txt", ios::binary );
    escritura<<sms;

    escritura.close();
}
string leertxt(string documento){
  string cadena;char tmp;
  ifstream fe(documento.c_str());
  while (!fe.eof()) {
    fe >> tmp;
    cout << cadena << endl;
  }
  return cadena;
  fe.close();
}
void escribir_txt(string txt,string documento){
  ofstream fs(documento.c_str(), ios::out);
  fs << txt << endl;
  fs.close();
}
string lecturar(){
    ifstream archivo;
    string texto;
    archivo.open("mensaje.txt",ios::in);
    if(archivo.fail()){cout<<"no abrio";exit(1);}
    while(!archivo.eof()){
        getline(archivo,texto);
    }
    return texto;
    archivo.close();
}
int main(){
    rsa a(7);
    int opcion;
    do{
       system("cls");
       cout <<"1. Encriptar: "<<endl;
       cout <<"2. Descencriptar:"<<endl;
       cout <<"3. Claves"<<endl;
       cout <<"4. Salir:"<<endl;
       cout <<"opcion: ";
       cin>>opcion;

       switch(opcion){
           case 1:{
               ZZ e_,n_;
               string msg;
               cout <<"ingrese e:";cin>>e_;
               cout <<"ingrese n:";cin>>n_;
               rsa a(e_,n_);
               msg=leer("mensaje");
               //cin.ignore();

               //getline(cin,msg);
               string cif=a.cifrarA(msg);
               escribir("cifrado",cif);
               cout <<"mensaje encriptado: "  << endl;
               system("");
               break;
           }
           case 2:{
                string msg;
                msg=a.decifrarA(leer("cifrado"));

                cout << msg<< endl;
                system("pause");
                break;
           }
           case 3:
            int bit;
               cout<<"ingrese numeros de bit ";
               cin>>bit;
               rsa b(bit);
            system("cls");
            cout << "claves de a :" << endl;
            cout <<"clave privada: "<<b.d<<endl;
            cout <<"clave publica: "<<b.e<<endl;
            cout <<"N: "<<b.n<<endl;
            cin.get();
            getchar();
            system("pause");
            break;

        }
        system("pause");
    }while(opcion!=4);

    /*rsa a(4);
    string x,y,z,v;
    cin>>v;
    x=a.cifrarA(v);
    cout<<"x: "<<x<<endl;
    cin>>z;
    y=a.decifrarA(z);
    cout<<"y: "<<y<<endl;*/
    return 0;
}
