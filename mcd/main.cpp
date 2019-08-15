#include <iostream>

using namespace std;

int mod(int num,int mod)
{
	int r,q;
	q=num/mod;
	r=num-(mod*q);
	if(r<0){return r+mod;}
	return r;
}
int euclides(int A,int b)
{
	int q;
	int r;
	int mcd;
	r=mod(A,b);
	while(r>0){
		mcd=r;
		q=A/b;
		r=mod(A,b);
		A=b;
		b=r;
	}
	return mcd;
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

int main()
{
    //int mcd= euclides(45,9);
    int mcdE=algEuclidesMCD(9,45);
    //cout <<" mcd: "<<mcd<<endl;
    cout <<" mcd: "<<mcdE<<endl;
    return 0;
}
