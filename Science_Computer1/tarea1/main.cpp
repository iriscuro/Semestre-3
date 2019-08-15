#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

//void calendario(int year);
//string nombreMes(int &mes);
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





int main()
{
    int year;
    cout <<"Ingrese el A\xa4o : "<<endl;
    cin>>year;
    calendario(year);
    system("pause");

}

