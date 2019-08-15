#include <iostream>

using namespace std;

int main()
{
    int i,j,k;
    int n,m;
    int *p;
    int **pr;
    //_----------------
    int **ArrB;
    //-----------------
    cout<<"Ingrese el numero de filas: ";
    cin>>n;
    cout<<"Ingrese el numero de columnas: ";
    cin>>m;
    int ArrA[n][m];

    k=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++,k++)
            ArrA[i][j]=k;
    }
    cout<< "Array A "<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            cout<<*(*(ArrA+i)+j)<<"  ";
        cout<<endl;
    }
    cout<< "Array A con punteros de bi a uni "<<endl;
    p= (int*)ArrA;
    cout<<"ArrA "<<ArrA<<endl;
    cout<<"p "<<p<<endl;
    for(i=0;i<n*m;i++){
        cout<<*(p+i)<<" ";
    }
    cout<<endl;
    cout<<"------------------------------------"<<endl;
    cout<< "Array B sin 100 "<<endl;

    ArrB = new int*[n];
    for(i=0;i<n;i++){
        *(ArrB+i) = new int[m];//ArrA[i]=new int[m];
    }
    k=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++,k++)
            ArrB[i][j]=k+100;
    }
    cout<< "Array B "<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            cout<<*(*(ArrB+i)+j)<<"  ";
        cout<<endl;
    }
    cout<<"ArrB "<<ArrB<<endl;
    //cout<<"*ArrB "<<(long)*ArrB<<endl;

    p=(int*)(ArrB);
    pr= (int**)(ArrB);
    cout<<"p "<<p<<endl;
    cout<<"**pr "<<**pr<<endl;
    for(i=0;i<n*m;i++){
        cout<< *(*(pr+i))<<"  ";
    }

    return 0;
}
