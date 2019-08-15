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
/*
    string months[]={"1. enero","2. febrero","3. marzo","4. abril","5. mayo","6. junio","7. julio",
                    "8. agosto","9. setiembre","10. octubre","11. noviembre","12. diciembre"};

    for(int m=0;m<=12;m++){
        cout << months[m]<<endl;
    }
    */
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
    system("pause");
    return 0;

}
