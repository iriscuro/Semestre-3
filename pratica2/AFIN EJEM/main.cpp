#include "Afin.h"

#include <iostream>

using namespace std;

int main()
{
    Afin pf;

    string te = pf.Encrypt("with a little help from my friends",3,26);

    cout << "Texto encriptado: " << te << endl;
    string des =pf.Descrypt(te,3,26);
    cout << "Texto desencriptado: " << des << endl;
    return 0;
}
