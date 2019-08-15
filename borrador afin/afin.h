#include <iostream>
#include <string>

using namespace std;

class afin
{

    public:
        string alfabeto;
        int tam;
        afin();
        afin(int a, int b);
        int get_clave_a(){return clave_a;}
        int get_clave_b(){return clave_b;}

        string cifrar(string );
        string descifrar(string );
	private:
        int clave_a;
        int clave_b;
        int clave_x;
};
