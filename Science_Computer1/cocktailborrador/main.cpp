#include <iostream>

using namespace std;

// SWAP
void swapP(int *a, int  *b){
    int n= *a;
    *a=*b;
    *b=n;
}
void swapS(int a, int  b){
    int n= a;
    b=a;
    a=n;
}
void cocktail(int *num,int tam){
    int *ini=num;
    int *fin=&num[tam-1];
    bool swapC=1;
    while(swapC){
        if(ini>ini+1){
           swapP(ini,(ini+1));
           swapC=true;
        }
        if(fin<fin-1){
            swapP(fin,(fin-1));
            swapC=true;
        }
        else
            swapC=false;
        fin--;
        ini++;
    }

}
int main()
{
    //cocktail con punteros
    /* necesitamos 3 punteros
    - uno para inicio
    - para el final
    - para recorrer
       necesitamos 1 bucle
     */
    int numeros[]={1,23,2,45,13,89,100,20,76,30};
    int tam=sizeof(numeros)/sizeof(*numeros);
    cout << "tam: "<<tam<<endl;


    int *inici=numeros;
    int *finle=&numeros[tam-1];

    while(inici<=finle){
        cout<<*(inici)<<" ";
        inici++;
    }
    cout<<endl;

    int *tem=numeros;
    int *tem2=&numeros[tam-1];
    int *ini=tem;
    int *fin=tem2;
    int *a=tem;

    bool swapC=1;

    cout<<endl;
     while(swapC){
        if(tem<tem2){
            if(ini<=tem2){
                if(*ini>*(ini+1)){//recorrer todos los numeros
                    swapP(ini,(ini+1));
                    }
                ini++;
            }
            else{
                if(fin>tem){
                    if(*fin<*(fin-1)){
                        swapP(fin,(fin-1));
                    }
                    fin--;
                }
                else{
                    fin=fin-1;
                    tem2--;
                    *fin=*tem2;
                    tem++;
                    ini=tem;
                }
            }
        }
        else{
            swapC=0;
        }
    }


    cout<<endl;

    int *inic=numeros;
    int *finl=&numeros[tam-1];
    //imprimir array
    while(inic<=finl){
        cout<<*(inic)<<" ";
        inic++;
    }


    return 0;
}
