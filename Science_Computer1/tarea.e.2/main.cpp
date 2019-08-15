#include <iostream>

using namespace std;
int mcd(int num1,int num2){
    int a,b,mcdr;
    a=max(num1,num2);
    b=min(num1,num2);
    if(num1==0){
        mcdr=num2;
    }
    if(num2==0){
        mcdr=num1;
    }
    else{
        do{
            mcdr=b;
            b=a%b;
            a=mcdr;
        }
        while(b!=0);
        }

    return mcdr;
}
int algEuclidesMCD(int num,int mod){
    int a=num;
    int b=mod;
    int mcd_,q,r;
    if(a==0){
        mcd_=b;
        return mcd_;
    }
    if(b==0){
        mcd_=a;
        return mcd_;
    }
    q=a/b;
    r=a-b*q;//num=mod*q+r
    a=b;
    b=r;
    mcd_=algEuclidesMCD(a,b);


}
int modulo(int a, int b){
    int c;
    c=a-b*(a/b);
    if(c<0)
        c=c+b;
    return c;
}
/*
bool tieneInvM(int num,int mod){
    int r1,r2,cont=1,q,r;
    bool salir=false;
    q=mod/num;//mod=q(num)+r -> num=q_2(r)+r_2
    r1=mod-q*num;
    while(salir){
        mod=num;cout<<"mod "<<mod<<endl;
        num=r1;cout<<"num "<<num<<endl;
        q=mod/num;//mod=q(num)+r -> num=q_2(r)+r_2
        cout<<"q "<<q<<endl;
        r2=mod-q*num;cout<<"r "<<r2<<endl;
        r1=r2;cout<<"r1 "<<r1<<endl;
        cont ++;
        if(r2==0){
            salir=true;}

        }
        return (r2==1)?true:false;
    }
*/
bool  inversoModular(int num, int mod){
    while(r!=0){
        r=num-num/mod;
        if(r==1){
            return true;
            break;
        }
        else
            return false;
    }

}
int main()
{
    int numero,modul,res1,res2;
    cout << ">>>>>>>Inverso _modulo<<<<<" << endl;
    cout << "  numero:\t";
    cin>> numero;
    cout <<"  modulo:\t";
    cin>> modul;
    res1=modulo(numero,modul);
    cout <<res1;
    //res1=mcd(numero,modulo);
    //res2=algEuclidesMCD(numero,modulo);
    //cout<< res1 <<"\t"<<res2;
    //bool i=tieneInvM(numero,modulo);
    //cout << i <<endl;
    return 0;
}
