#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

unsigned t0, t1;

void Swap(int &a,int &b){
    int tmp=a;
    a=b;
    b=tmp;
}
int modulo(int a,int b){//numero , modulo
    int c;
    c=a-b*(a/b);
    if(c<0)
        c=c+b;
    //cout<<"m: "<< c<<endl;;
    return c;
}
int euclideanOld(int m,int n){
    if(m=0)
        return n;
    while(n!=0){
        if(m>n)
            n-=m;
        else
            m-=n;
    }
    return m;
}
int EuclideanIterative(int m, int n){
    while(n!=0){
        int t=n;
        n=modulo(m,n);
        m=t;
    }
    return m;
}
int EuclideanRecursive(int m,int n){
    if(n=0)
        return m;
    else{
        return EuclideanIterative(n,modulo(m,n));
    }
}
bool isEven(int a){
    int mod=modulo(a,2);
    return (mod==0)? true: false;
}
int BinaryGCD(int m, int n){
    if(m==0 || n==0)
        return 0;
    int s=0;
    while(isEven(m)==1 &&isEven(n)==1){
        m=m/2;
        n=n/2;
        s=s+1;
    }
    while(isEven(n)==1){
            n=n/2;
    }
    while(m!=0){
        while(isEven(m)==1){
            m=m/2;
        }
        if(m<n){
           Swap(m,n);
        }
        m=m-n;
        m=m/2;
    }
    //cout<<"n: "<<n<<endl;
    return pow(2,s)*n;
}
int main()

{
    /*
    mcd(321,1576);
    mcd(35,14);
    mcd(252,180);
    */
    int m;
    int n;
    int resul;
    cout <<"Dos numeros: "<<endl;
    cin>>m;
    cin>>n;
    //resul= euclideanOld(m,n);
    //cout<< resul<<endl;
    t0=clock();
    resul= BinaryGCD(m,n);
    //resul=EuclideanIterative(m,n);
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;
    cout<< resul<<endl;
    return 0;
}
