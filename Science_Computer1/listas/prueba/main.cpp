#include <iostream>

using namespace std;
bool mayor(int a,int b){
    return (a>b);
}

bool menor(int a,int b){
    return (a<b);
}

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
void cocktail(int *numeros,int tam,bool(*p)(int,int)){
    int *ini=numeros;
    int *fin=(numeros+tam-1);
    int *A=ini;
    int *B=fin;bool swapC=1;
    ini=ini+1;fin=fin-1;
    while(swapC){
      if(ini<=fin){
          if(A<=fin){
            if(p(*(A+1),*A)){//recorrer todos los numeros
              swapP(A,(A+1));
              }A++;
          }
          else{
            if(B>=ini){
                if(p(*B,*(B-1))){
                  swapP(B,(B-1));}
                  B--;}
                else{
                  fin--;B=fin;
                  ini++;A=ini;}
                }
              }
        else{swapC=0;
        }
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
    //imprimir el array original
    while(inici<=finle){
        cout<<*(inici)<<" ";
        inici++;
    }
    cout<<endl;
    bool(*p)(int,int)=mayor;
    //bool(*p)(int,int)=menor;
    cocktail(numeros,tam,p);

    cout<<endl;

    for(int i=0;i<tam;i++){
        cout<<numeros[i]<<" ";
    }


    return 0;
}
