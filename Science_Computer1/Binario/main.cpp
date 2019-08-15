#include <iostream>
#include <fstream>
using namespace std;

int main(int argc,char* argv[])
{
    ofstream salida("dato.dat", ios::binary | ios::app);
    int i;
    for(i=0;i<10;i++)
        salida.write((char *)(&i),sizeof(int));//cateo de char, el tamaño del espacio de memoria que va a reservar para el momento del lmacenamiento
    ifstream lectura("dato.dat",ios::binary);

    if(!lectura){
        cerr <<"error";
    }
    lectura.seekg(0);

    lectura.read((char *)(&i),sizeof(int));
    while(!lectura.eof()){//mientras no se alacance el final del archivo
        cout<< i<<" ";
        lectura.read((char *)(&i),sizeof(int));
    }
    lectura.close();
    return 0;
}
