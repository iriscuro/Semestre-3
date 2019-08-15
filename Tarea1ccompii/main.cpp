#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#define MONEDAS  8

using namespace std;

 int v,d,cinco,dos,uno;
 int cambio_moneda(int cantidad)
 {
     v=cantidad/20;
     cantidad=cantidad%20;
     d=cantidad/10;
     cantidad=cantidad%10;
      cinco=cantidad/5;
     cantidad=cantidad%5;
     dos=cantidad/2;
     cantidad=cantidad%2;
     uno=cantidad/1;
     cantidad=cantidad%1;
 }//int
int main()
{
    // Pregunta 1 Calendario

    // year 1 es bisiesto incio un martes
    int year=0;
    int mes;
    int esp=0;
    string dias[]={"dom","lun","mar","mier","jue","vie","sab"};
    string months[]={"enero","febrero","marzo","abril","mayo","junio","julio","agosto","setiembre","octubre","noviembre","diciembre"};
    int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
    cout << "Input year : "<<endl;
    cin >> year;
    cout << "Ingrese el mes : "<<endl;
    cin >>mes;
    // es bisiesto
    int b=0;
    bool f=true;
    if (year%4!= 0 ||(year%100==0 && year%400!=0))
        f=false;
    else
        b=1;
    // conteo
    int cdias=0;// dias que tiene el mes
    for(int i=0;i<=12;i++)
    {
        //comparacion
        if(strcmp(mes,months[i])==0);
            cdias=days[i];
    }
    //calculo del primer dia del mes
    int semana;
    //semana=((year-1)%7+ ((year-1)/4 -(3*((year-1)/100+1)/4))%7+moduloMes+1%7)%7;


    //impresion
    int s=1;
    int conta=0;
    int num=1;
    for(int c=0;c<=3;i++)
        cout << "/";
    for(int d=0;d<=dias;d++)
    {
        cout << num;
        num+=num;
        conta+=conta;
        if(num=3)
        {
            cout<< "/";
            conta=0;
        }
        if(conta/7=1)
        {
            cout<< "/";
            conta=0;
        }
    }

    // Pregunta 2 Numeros a letras

    int x;
    cout<<"ingrese un numero"<<endl;
    cin>>x;
if((x<1)||(x>999)) cout<<"INGRESA UN NUMERO DEL 1 AL 999\n";
else

    {
        if(x>=900)   {cout<<"NOVECIENTOS " ;x=x-900;}
       else if(x>=800)   {cout<<"OCHOCIENTOS " ;x=x-800;}
       else if(x>=700)   {cout<<"SETECIENTOS " ;x=x-700;}
       else if(x>=600)   {cout<<"SEISCIENTOS " ;x=x-600;}
       else if(x>=500)   {cout<<"QUINIENTOS "  ;x=x-500;}
       else if(x>=400)   {cout<<"CUATROCIENTOS "   ;x=x-400;}
       else if(x>=300)   {cout<<"TRESCIENTOS " ;x=x-300;}
       else if(x>=200)   {cout<<"DOSCIENTOS "  ;x=x-200;}
       else if(x>100)    {cout<<"CIENTO "  ;x=x-100;}
       else if(x==100)  {cout<<"CIEN"     ;x=x-100;}
        if(x>90) {cout<<"NOVENTA Y "   ;x=x-90; }
            if(x==90)   {cout<<"NOVENTA"  ;x=x-90; }
            if(x>80) {cout<<"OCHENTA Y "   ;x=x-80; }
            if(x==80)   {cout<<"OCHENTA"  ;x=x-80; }
            if(x>70) {cout<<"SETENTA Y "   ;x=x-70; }
            if(x==70)   {cout<<"SETENTA"  ;x=x-70; }
            if(x>60) {cout<<"SESENTA Y "   ;x=x-60; }
            if(x==60)   {cout<<"SESENTA"  ;x=x-60; }
            if(x>50) {cout<<"CINCUENTA Y " ;x=x-50; }
            if(x==50)   {cout<<"CINCUENTA"    ;x=x-50; }
            if(x>40) {cout<<"CUARENTA Y "  ;x=x-40; }
            if(x==40)   {cout<<"CUARENTA" ;x=x-40; }
            if(x>30) {cout<<"TREINTA Y "   ;x=x-30; }
            if(x==30)   {cout<<"TREINTA"  ;x=x-30; }
            if(x>20) {cout<<"VEINTI"       ;x=x-20; }
            if(x==20)   {cout<<"VEINTE"       ;x=x-20; }
        if(x>=16)    {cout<<"DIECI"        ;x=x-10; }
       else if(x==15)   {cout<<"QUINCE"       ;x=x-15; }
       else if(x==14)   {cout<<"CATORCE"  ;x=x-14; }
       else if(x==13)   {cout<<"TRECE"        ;x=x-13; }
       else if(x==12)   {cout<<"DOCE"     ;x=x-12; }
       else if(x==11)   {cout<<"ONCE"     ;x=x-11; }
       else if(x==10)   {cout<<"DIEZ"     ;x=x-10; }
        if(x==9)    {cout<<"NUEVE"        ;x=x-9;  }
        if(x==8)    {cout<<"OCHO"     ;x=x-8;  }
        if(x==7)    {cout<<"SIETE"        ;x=x-7;  }
            if(x==6)    {cout<<"SEIS"     ;x=x-6;  }
       else if(x==5)    {cout<<"CINCO"        ;x=x-5;  }
       else if(x==4)    {cout<<"CUATRO"       ;x=x-4;  }
       else if(x==3)    {cout<<"TRES"     ;x=x-3;  }
       else if(x==2)    {cout<<"DOS"      ;x=x-2;  }
       else if(x==1)    {cout<<"UNO"      ;x=x-1;  }
       }
    cout<<endl;

    // Pregunta 3 Vuelto


     int cantidad;
     printf("Introduzca cantidad: \n");
     scanf("%d",&cantidad);
     cambio_moneda(cantidad);
     printf("\nsu cambio\n20:%d\n10:%d\n5:%d\n2:%d\n1:%d",v,d,cinco,dos,uno);
     system("pause>nul");
    // Pregunda 4 Numeros Romanos

    int numero, unidades, decenas, centenas, millares;

 cout<< "Ingrese un numero"<<endl;
 cin>> numero;

 /*Esto se hace para separar el numero,
 tomen como ejemplo el numero 2103, a ese numero
 lo debemos transformar de la manera siguiente:
 2 - 1 - 0 - 3 donde 3 va a ocupar la unidades,
 0 las decenas, 1 las centenas y 2 los millares*/

 unidades = numero % 10; numero /= 10;
 decenas = numero % 10; numero /= 10;
 centenas = numero % 10; numero /= 10;
 millares = numero % 10; numero /= 10;

 switch (millares)
 {
  case 1: cout<<"M"; break;
  case 2: cout<<"MM"; break;
  case 3: cout<<"MMM"; break;
 }

 switch (centenas)
 {
  case 1: cout<<"C"; break;
  case 2: cout<<"CC"; break;
  case 3: cout<<"CCC"; break;
  case 4: cout<<"CD"; break;
  case 5: cout<<"D"; break;
  case 6: cout<<"DC"; break;
  case 7: cout<<"DCC"; break;
  case 8: cout<<"DCCC"; break;
  case 9: cout<<"CM"; break;
 }

 switch (decenas)
 {
  case 1: cout<<"X"; break;
  case 2: cout<<"XX"; break;
  case 3: cout<<"XXX"; break;
  case 4: cout<<"XL"; break;
  case 5: cout<<"L"; break;
  case 6: cout<<"LX"; break;
  case 7: cout<<"LXX"; break;
  case 8: cout<<"LXXX"; break;
  case 9: cout<<"XC"; break;
 }

 switch (unidades)
 {
  case 1: cout<<"I"; break;
  case 2: cout<<"II"; break;
  case 3: cout<<"III"; break;
  case 4: cout<<"IV"; break;
  case 5: cout<<"V"; break;
  case 6: cout<<"VI"; break;
  case 7: cout<<"VII"; break;
  case 8: cout<<"VIII"; break;
  case 9: cout<<"IX"; break;
 }
 /*
 if(num<10)
            cout <<rom1[num-1];
        else {
            uni=num%10;
            num /= 10;
            dec=num%10;
            num /= 10;
            if(num==0){
                cout <<rom2[dec-1];
                cout <<rom1[uni-1];
                }
            else {
                cen=num%10;
                num /=10;
                cout <<rom3[cen-1];
                cout <<rom2[dec-1];
                cout <<rom1[uni-1];
                }
            }
        }
 */
    // Pregunta 5 Criptografias
    return 0;
}
