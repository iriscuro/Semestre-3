#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include  <math.h>

using namespace std;
void vueltoC(float cambio,float arr[],int lenA){
    int i=0,cant=0;
    while(cambio >=0 && i<lenA){
        if(cambio >=arr[i]){
            cant=cambio/arr[i];
            cout<<"Cantidad de billetes/monedas de "<< arr[i] <<" -> "<< cant <<endl;
            }
        else{
            cant=0;
            i++;
        }
        cambio-=(arr[i]*cant);
        cambio +=0.0001;
        }
}
float vueltoE(float cambio,int ent[],int lenE){
    int i=0,cant=0;
    while(cambio >=0 && i<lenE){
        if(cambio >=ent[i]){
            cant=cambio/ent[i];
            cout<<"Cantidad de billetes/monedas de "<< ent[i] <<" -> "<< cant <<endl;
            }
        else{
            cant=0;
            i++;
        }
        cambio-=(ent[i]*cant);
        }
    return cambio;
}

float camD(float cambio,int arr[],int lenA){
    float a= cambio*10;
    int i=0,cant=0;
    cambio*=10;
    int s=(int)cambio;
    cout<< s<<endl;
    a=a-s;
    while(s >=0 && i<lenA){
        if(s >=arr[i]){
            cant=s/arr[i];
            cout<<"Cantidad de monedas de "<< arr[i]*0.1 <<" -> "<< cant <<endl;
            }
        else{
            cant=0;
            i++;
        }
        //s%=arr[i];
        s-=(arr[i]*cant);
    }
    return a;
}

string nombreMes(int mes){
    switch(mes){
        case 1: return "Enero";
        case 2: return "Febrero";
        case 3: return "Marzo";
        case 4: return "Abril";
        case 5: return "Mayo";
        case 6: return "Junio";
        case 7: return "Julio";
        case 8: return "Agosto";
        case 9: return "Setiembre";
        case 10: return "Octubre";
        case 11: return "Noviembre";
        default: return "Diciembre";

    }
}

bool esBisiesto(int year){
    if (year%4!= 0 ||(year%100==0 && year%400!=0))
        return false;
    else
        return true;
}

// Devuelve
 // 0 = Domingo, 1 = Lunes, 2 = Martes, 3 = Miercoles,
 // 4 = Jueves, 5 = Viernes, 6 = Sábado
 int zeller(int year, int mes) {
    int a = (14 - mes) / 12;
    int y = year - a;
    int m = mes + 12 * a - 2;
    int dia = 1, d;
    d = (dia + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    return (d);
 }

 int calcularDiasMes(int year,int mes){
    if(mes == 1 || mes == 3|| mes ==  5|| mes == 7 ||
       mes ==8 || mes == 10 || mes ==12)
        return 31;
    if(mes ==2 ){
        if(esBisiesto(year)) return 29;
        return 28;
    }
    return 30;
}

void calendario(int year){
    for(int mes=1; mes<=12 ; mes++){
        cout << "Mes: " << nombreMes(mes) <<"\n";
        cout <<" Dom  Lun  Mar  Mir  Jue  Vie  Sab\n";
        int z= zeller(year,mes);
        for(int i=0;i<z; i++){
            cout<< "     ";
        }
        int diasMes = calcularDiasMes(year,mes);
        for(int dia= 1;dia<=diasMes;dia++){
            printf("%4d ",dia);
            z++;
            if(z%7==0)
                cout <<"\n";
        }
        cout << "\n";
    }
}


void calendarioMes(int year,int mes){
    cout << "     " << nombreMes(mes) <<"\n";
    cout <<" Dom  Lun  Mar  Mir  Jue  Vie  Sab\n";
    int z= zeller(year,mes);
    for(int i=0;i<z; i++){
    cout<< "     ";
    }
    int diasMes = calcularDiasMes(year,mes);
    for(int dia= 1;dia<=diasMes;dia++){
        printf("%4d ",dia);
        z++;
    if(z%7==0)
        cout <<"\n";
    }
}

int main()
{
    // Pregunta 1 Calendario
/*
    cout << "Meses:"<<endl;
    cout << "1. enero\n"<<"2. febrero\n"<<"3. marzo\n"<<"4. abril\n"<<"5. mayo\n"<<"6. junio\n"<<"7. julio\n"<<
                    "8. agosto\n"<<"9. setiembre\n"<<"10. octubre\n "<<"11. noviembre\n "<<"12. diciembre"<<endl;
    int year;
    cout <<" Ingrese el A\xa4o : "<<endl;
    cin>>year;
    int mes=0;
    cout << " Ingrese el numero del mes : "<<endl;
    cin >> mes;
    calendarioMes(year,mes);
    cout <<endl;
*/
    // Pregunta 2 Numeros a letras
/*
    int numeros[]={0,1,2,3,4,5,6,7,8,9};
    string nomNum1[]={"","UNO ","DOS ","TRES ","CUATRO ","CINCO ","SEIS ","SIETE ","OCHO ","NUEVE "};
    string nomNum2[]={"ONCE ","DOCE ","TRECE ","CATRORCE ","QUINCE "};
    string nomNum3[]={"","DIEZ ","VEINTE ","TREINTA ","CUARENTA ","CINCUENTA ","SESENTA" ,"SETENTA ","OCHENTA ",
                    "NOVENTA "};
    string nomNum4[]={"","DIECI","VEINTI","TREINTA Y ","CUARENTA Y ","CINCUENTA Y ","SESENTA Y ","SETENTA Y",
                    "OCHENTA Y ","NOVENTA Y "}  ;
    string nomNum5[]={"","CIENTO ","DOSCIENTOS ","RESCIENTOS ","CUATROCIENTOS ","QUINIENTOS ","SEISCIENTOS ",
                    "SETECIENTOS ","OCHOCIENTOS ","NOVECIENTOS "};
    //string nomNum6[]={"","","","","","","","","","","",""};
    string nomNum7[]={"","MIL ","MILLONES"};

    int uni,dec,cen,umil,dmil,cmil,umm;
    int num=0;

    cout <<" >>> De numeros a letras <<< "<<endl;
    cout << " Ingresar el numero :" <<endl;
    cin>>num;
    if(num > 9999999 || num <0)
        cout<< "Ingrese un numero menor a 9999999 y mayor a 0 :"<<endl;
    else{
        if(num==0){
            cout<< " CERO ";
        }
        else{

            uni =num%10;  num /= 10;
            dec =num%10;  num /= 10;
            cen =num%10;  num /=10;
            umil =num%10;  num /=10;
            dmil =num%10;  num /=10;
            cmil =num%10;  num /=10;
            umm =num%10;  num /=10;

            if(umm==0)
                cout <<"";
            else
                cout <<nomNum1[umm] << " MILLONES ";

            if(cmil!=0){
                if(dmil==0 && umil==0){
                    if(cmil==1)
                        cout << "CIEN ";
                    else
                        cout<<nomNum5[cmil];//
                    }

                else{
                    cout <<nomNum5[cmil];
                   }
            }
            else
                cout<<nomNum1[umm];


            if(dmil*10+umil<=15 && dmil*10+umil>=15){

                cout <<nomNum2[umil];
            }
            else{
                cout <<nomNum4[dmil];
            }

            cout <<nomNum1[umil];

            if(cen==1 && dec==0 && uni ==0){
                cout << " CIEN ";
            }
            else
                cout<<nomNum5[cen];
            if(dec!=0 && uni==0){
                cout <<nomNum3[cmil];
            }
            else3
                cout<<nomNum4[dec];

            cout <<nomNum1[uni];
            }
        }
    //cout<<nomNum7[]<<nomNum5[]<<nomNum4[]<<nomNum3[]<<nomNum2[]<<nomNum1[];
    cout <<endl;
*/
    // Pregunta 3 Vuelto

    cout << " ....VUELTO ...." << endl;

    float  cantidad,cambio,dinero,vuelto;
    float dine[]={200,100,50,20,10,5,2,1,0.5,0.2,0.1,0.05,0.01};
    int denomM[]={200,100,50,20,10,5,2,1};
    int centm[]={5,2,1};
    int centv[]={5,1};
    cin>>vuelto;
    cantidad=vueltoE(vuelto,denomM,8)+0.0001;
    //cout <<cantidad<<endl;
    if(cantidad != 0){
        cantidad=camD(cantidad,centm,3);
        //cout <<cantidad<<endl;
        if(cantidad != 0)
            cantidad=camD(cantidad,centv,2);

    }
    vueltoC(vuelto,dine,13);

    //camD(cantidad,centm,3);
    //cout << "Ingrese la cantidad con la que paga:"<<'\t';
    //cin >> dinero;
    //cout << "Monto gastado en el/los  producto/s: "<<'\t';
    //cin>> cantidad;
    //cambio=dinero-cantidad;
    /*
    if(dinero<cantidad)
        cout <<"Su pago no cubre su gasto..."<<endl;
    else{
        cout<<"El cambio es: "<<cambio<<endl;
        camV(cambio,denomM,13);
    }*/
/*
    int cantidad;

    float monedaL[]={200,100,50,20,10,5,2,1,0.5,0.2,0.1,0.05,0.01};

    cout << "Introduzca cantidad: \n";
    cin >>cantidad;
    for(int i=0;i<13;i++){
        int v;
        v=cantidad/monedaL[i];
        cantidad-=(monedaL[i]*v);
        //cantidad=(int)cantidad%monedaL[i];
        cout << v <<" del valor de "<<monedaL[i]<<" sol/es "<<endl;
        //arr[i]=v;
    }
    */
    // Pregunda 4 Numeros Romanos

    /*
    I     1
    V     5
    X     10
    L     50
    C     100
    D     500
    M     1000

    */
/*
    cout << " Numeros Romanos: "<<endl;
    int unid=0,dece=0,cent=0;
    int number=0;
    string rom1[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    string rom2[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string rom3[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    int nums[] = {1,2,3,4,5,6,7,8,9};
    cout << " Ingresar el numero :" <<endl;
    cin>>number;
    if(number > 999 || number <0)
        cout<< "Ingrese un numero menor a 999 y mayor a 0 :"<<endl;
    else{
        if(num<10){
            cout <<rom1[number];
        }
        else{
            unid=num%10;
            number /= 10;
            dece=number%10;
            number /= 10;
            cent=number%10;
            number /=10;
            cout <<rom3[cent];
            cout <<rom2[dece];
            cout <<rom1[unid];
            }

        }
        */

    // Pregunta 5 Criptografias
    return 0;
}
