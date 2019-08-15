#include <iostream>

using namespace std;
/*
void unidades(int unidad){
    switch (unidades)
        {
            case 1: cout<<"UNO"; break;
            case 2: cout<<"DOS"; break;
            case 3: cout<<"TRES"; break;
            case 4: cout<<"CUATRO"; break;
            case 5: cout<<"CINCO"; break;
            case 6: cout<<"SEIS"; break;
            case 7: cout<<"SIETE"; break;
            case 8: cout<<"OCHO"; break;
            case 9: cout<<"NUEVE"; break;
        }
}

void decenas(int decena){
      switch (decena)
        {
            case 1: cout<<"DIEZ "; break;
            case 2: cout<<"VENTE "; break;
            case 3: cout<<"TREINTA "; break;
            case 4: cout<<"CUARENTA "; break;
            case 5: cout<<"CINCUENTA "; break;
            case 6: cout<<"SESENTA "; break;
            case 7: cout<<"SETENTA"; break;
            case 8: cout<<"OCHENTA "; break;
            case 9: cout<<"NOVENTA "; break;
        }
}
void centenas(int centena){
      switch (centena)
        {
            case 1: cout<<"CIEN "; break;
            case 2: cout<<"DOSCIENTOS "; break;
            case 3: cout<<"TRESCIENTOS "; break;
            case 4: cout<<"CUATROCIENTOS "; break;
            case 5: cout<<"QUINIENTOS "; break;
            case 6: cout<<"SEISCIENTOS "; break;
            case 7: cout<<"SETECIENTOS "; break;
            case 8: cout<<"OCHO "; break;
            case 9: cout<<"NUEVE "; break;
        }
}
*/
void  nomNumeros(int num){

}


int main()
{

    int numeros[]={0,1,2,3,4,5,6,7,8,9};
    string nomNum1[]={"","UNO ","DOS ","TRES ","CUATRO ","CINCO ","SEIS ","SIETE ","OCHO ","NUEVE "};
    string nomNum2[]={"ONCE ","DOCE ","TRECE ","CATRORCE ","QUINCE "};
    string nomNum3[]={"","DIEZ ","VEINTE ","TREINTA ","CUARENTA ","CINCUENTA ","SESENTA" ,"SETENTA ","OCHENTA ",
                    "NOVENTA "};
    string nomNum4[]={"","DIECI","VEINTI","TREINTA Y","CUARENTA Y ","CINCUENTA Y ","SESENTA Y ","SETENTA Y",
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
                    if(cmil==1){
                        cout << "CIEN ";
                    }
                else{
                    cout <<nomNum5[cmil];
                   }

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
            else
                cout<<nomNum4[dec];

            cout <<nomNum1[uni];


                }


        }

    return 0;
}
