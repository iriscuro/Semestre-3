#include <iostream>

using namespace std;

int main()
{
    // Pregunta 2 Numeros a letras

    int numeros[]={0,1,2,3,4,5,6,7,8,9};
    string nomNum1[]={"","UNO ","DOS ","TRES ","CUATRO ","CINCO ","SEIS ","SIETE ","OCHO ","NUEVE "};
    string nomNum2[]={"","ONCE ","DOCE ","TRECE ","CATRORCE ","QUINCE "};
    string nomNum3[]={"","DIEZ ","VEINTE ","TREINTA ","CUARENTA ","CINCUENTA ","SESENTA " ,"SETENTA ","OCHENTA ",
                    "NOVENTA "};
    string nomNum4[]={"","DIECI","VEINTI","TREINTA Y ","CUARENTA Y ","CINCUENTA Y ","SESENTA Y ","SETENTA Y ",
                    "OCHENTA Y ","NOVENTA Y "}  ;
    string nomNum5[]={"","CIENTO ","DOSCIENTOS ","TRESCIENTOS ","CUATROCIENTOS ","QUINIENTOS ","SEISCIENTOS ",
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
            //cout <<umm<<cmil<<dmil<<umil<<cen<<dec<<uni<<endl;
            //unidades de mil
            if(umm==0)
                cout <<"";
            else{
                if(umm==1)
                    cout<<" UN MILLON ";
                else
                    cout <<nomNum1[umm] << " MILLONES ";
            }
            //centena de mil -00 y 100

            if(dmil==0 && umil==0){
                    if(cmil==1)
                        cout << "CIEN ";
                    else
                        cout<<nomNum5[cmil];//centena de mil
            }
            else{
                cout<<nomNum5[cmil];
            }
            // decena de mil
            if(dmil!=0 && umil==0){
                cout <<nomNum3[dmil];
            }
            else{
                if(dmil*10+umil>=11 && dmil*10+umil<16){
                    cout<<nomNum2[umil];
                }
                else{
                    if(umil==1)
                        cout<<"";
                    else{
                        cout<<nomNum4[dmil];
                        cout <<nomNum1[umil];
                    }
                }
            }

            if(cmil!=0 || dmil!=0 || umil!=0){
                cout <<" MIL ";
            }
            //centenas
            if(cen==1 && dec==0 && uni ==0){
                cout << " CIEN ";
            }
            else
                cout<<nomNum5[cen];
            // decenas
            if(dec!=0 && uni==0){
                cout <<nomNum3[dec];
            }
            else{
                if(dec*10+uni>=11 && dec*10+uni<16){
                    cout<<nomNum2[uni];
                }
                else{
                    cout<<nomNum4[dec];
                    cout <<nomNum1[uni];
                }
                }

            //cout <<nomNum1[uni];//unidades
            }
        }

    cout <<endl;

    return 0;
}
