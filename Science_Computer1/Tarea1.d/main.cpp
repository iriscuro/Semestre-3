#include <iostream>

using namespace std;

void numRoma(int num){
    int uni,dec,cen;
    string rom1[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    string rom2[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string rom3[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string rom4[] = {"","M"};
    int nums[] = {1,2,3,4,5,6,7,8,9};
    if(num > 999|| num <0)
        cout<< "Ingrese un numero menor a 999 y mayor a 0 :"<<endl;
    else{
        if(num<10){
            cout <<rom1[num];
        }
        else{
            uni=num%10;
            num /= 10;
            dec=num%10;
            num /= 10;
            cen=num%10;
            num /=10;
            cout <<rom3[cen];
            cout <<rom2[dec];
            cout <<rom1[uni];
            }

        }

}

//numeros hasta 5000
void NumeroRoma(int num){
    int uni,dec,cen,umil;
    string rom1[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    string rom2[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string rom3[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string rom4[] = {"","M"};
    int nums[] = {1,2,3,4,5,6,7,8,9};
    if(num > 5000|| num <0)
        cout<< "Ingrese un numero menor a 5000 y mayor a 0 :"<<endl;
    else{
        if(num<10){
            cout <<rom1[num];
        }
        else{

            uni=num%10;
            num /= 10;
            dec=num%10;
            num /= 10;
            cen=num%10;
            num /=10;
            umil=num%10;
            for(int i=0;i<umil;i++)
                cout <<rom4[1];
            cout <<rom3[cen];
            cout <<rom2[dec];
            cout <<rom1[uni];

            }

        }
}
int main()
{
    /*
    I     1
    V     5
    X     10
    L     50
    C     100
    D     500
    M     1000

    */
    cout << " Numeros Romanos: "<<endl;
    int uni,dec,cen;
    int num=0;
    string rom1[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    string rom2[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string rom3[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string rom4[] = {"","M"};
    int nums[] = {1,2,3,4,5,6,7,8,9};
    cout << " Ingresar el numero :" <<endl;
    cin>>num;
    numRoma(num);
    /*
    if(num > 999 || num <0)
        cout<< "Ingrese un numero menor a 999 y mayor a 0 :"<<endl;
    else{
        if(num<10){
            cout <<rom1[num];
        }
        else{
            uni=num%10;
            num /= 10;
            dec=num%10;
            num /= 10;
            cen=num%10;
            num /=10;*/
            /*
            if(cen==0 ){
                cout <<rom3[cen];
                cout <<rom2[dec];
                cout <<rom1[uni];
            }
            else if(uni==0){
                if(dec==0){
                    cout <<rom3[cen];
                    }
                else if(cen==0){
                    cout <<rom2[dec];
                }
                else{
                    cout <<rom3[cen];
                    cout <<rom2[dec];
                }
                }
            else if(dec==0){
                cout <<rom3[cen];
                cout <<rom1[uni];
            }

            else{
                cout <<rom3[cen];
                cout <<rom2[dec];
                cout <<rom1[uni];
            }*/
            /*
            cout <<rom3[cen];
            cout <<rom2[dec];
            cout <<rom1[uni];
            }

        }*/

    return 0;
}
