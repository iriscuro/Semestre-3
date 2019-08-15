#include <iostream>
#include <string>
#include "ZIGZAG.h"
#include <clocale>
#include "CESAR.h"

using namespace std;

int main()
{

    setlocale(LC_CTYPE,"Spanish");
    //string chat="Creencia Cuando la flor-se abre-Compartir debilidades Es para siempre Cuando pienso en el futuro Tengo miedo Para siempre Para siempre Porque hay un sueño para continuarSolo ve hacia adelante Voy a caminar Cruzar el ancho mar Iris Rocio Curo 171-10-41448 Abrir tus oidos Escuchar Risas y lagrimas Todos estan vivos-KUROSAWA-";
    //string cifrado;
    //string cifrado="EpeedsDmsiyxrDlihgDweirmwspkmvDhD48lpsiqDhDDwuiwiehrlgexDrswmsxiswnpDeeqwiDgrwiesBLe557DeqwDumestDDiwwsisyDvgeDijhsDwriegkwDqvhDDeAQDiivbd6bDsxwyvqkispDDeDmBqwimvBhvrhwDiwhsDDysieikrDRv55geimvetfDyjDesqDrxDpe";
    //string cifrado="Ff6rnqjEfqixEExhqxhiowwswsaeju wnqExfruwEtEjEjjijqEjsqfnfEjjffEzEjyffyni66nwnEytftEnEfwxxEjEizififffxwrCsxsExsqxxEitRfEbXj jxEwEtEfEnEtfzxEqsEfEEEEEffEnExtyjyjgnsEEfeEEEsfufsyuxhzhyrvtfDtkisfutioEtyxnrtEtzt Cs3w88vjEhjujnwjtwnstExlzijnzwfsjEvsftEfxwEssEofvnb6zxzEwEhxnhsyrjwCyswEqhjywEEqzEwrjyEtiEnfzzanstjsxnEjfnxfjjjxujy";
    //string cifrado="C6jixmc6ExEjjft65fEfqhwsD9yz EEEj6xsjhtxm9jfznifh7EEwkfs8uw";
    //milagros
    //string cifrado="qIA1rnqIwBIG zvwxnBCjxnnyjmjIlAIAImmIInAIjFBAzwvlAjpvm Bn GjArIAxGvxI9GAnAIlxwBCIIrwBIInBICnxrvo mICjwnIvAvvwBIIxuIjI IjmIxjIAzrBAjInjIwBnomAnjwyB nrAjIrICInjxnrxI HCjxywxBjAnCAojII wnB CGjjuxr ---IvIqrInrIjxnCnxnrxAnwAInIBIm  IAArIxwAw A IjBAnnwnAAvujCFnxvAImujxmxIr mr wIIpnwrnnnAlBA nwCkxswljnIAArHwBIlAlkmC BwIurjAup416-ynjmzrnnvpwIA AlIxInIjwjCjroInBxpAArjnrxznvArlACIjjIrmnnwurxD xmmI jwnjAnCAwrIIqv IxnrIowxwjIwmI rwnI jI AjxnnxwxIoAn Ij-6 ICwrnxIuBuAwAm xIvlCrwIuAwIIpnIxvBIpr jyuAxmInxBCBAxAuIAxp";
    string cifrado="HCxhmlgrljFuvhhCqpqdhfidrfq2jdCChdwvCvCuCC2Av";
    string descifrado;
    /*
    int claveC=4;
    int claveZ=5;
    */
    /*
    int claveC=5;
    int claveZ=8;
    */
    /*
    int claveC=5;
    int claveZ=6;
    */
    //Mio
    /*
    int claveC=9;
    int claveZ=5;
*/

    int clave1=5;
    int clave2=8;
/*

    CESAR receptorC(claveC);
    ZIGZAG receptorZ(claveZ);
    */

    //milagros
    /*
    int claveC=9;
    int claveZ=5;
    */
    int claveC=3;
    int claveZ=3;
    //CESAR emisorC(clave1);
    //ZIGZAG emisorZ(clave2);
    /*
    CESAR receptorC(claveC);
    ZIGZAG receptorZ(claveZ);

    cout <<"Descifrado zigzag: ";
    descifrado=receptorZ.descifrado(cifrado);
    cout <<descifrado<<endl;


    cout <<"Descifrado cesar: ";
    descifrado=receptorC.descifrado(descifrado);
    cout <<descifrado<<endl;
    */


    //CESAR emisorC(clave1);
    //ZIGZAG emisorZ(clave2);

    CESAR receptorC(claveC);
    ZIGZAG receptorZ(claveZ);
    /*
    string cifrado;
    cout <<"Cifrado cesar: "<<endl;
    cifrado=emisorC.cifrado(chat);
    cout <<cifrado<<endl;

    cout<<endl;
    cout <<"Cifrado zigzag: "<<endl;
    cifrado=emisorZ.cifrado(cifrado);
    cout <<cifrado<<endl;

    cout<<endl;
    */

    cout <<"Descifrado zigzag: "<<endl;
    descifrado=receptorZ.descifrado(cifrado);
    cout <<descifrado<<endl;

    cout<<endl;

    cout <<"Descifrado cesar: "<<endl;
    descifrado=receptorC.descifrado(descifrado);
    cout <<descifrado<<endl;
    return 0;
}
