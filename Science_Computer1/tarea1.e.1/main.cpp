#include <iostream>

using namespace std;

int main()
{
    int n_1,n_2,m,resp,a;
    int crel=0;
    int cont=0;
    cout <<" n_1:\t";
    cin>> n_1;
    cout <<" n_2:\t";
    cin>>n_2;
    cout <<" mod:\t";
    cin>>m;
    a=n_1+n_2;
    int lim=m;
    if(a>0){
        while(cont<a){
        cont++;
        cout<<"cont  "<< cont<<endl;
        crel++;
        cout<< "crel  "<<crel<<endl;
        if(crel==lim)
            crel=0;
    }
    }
    else{
        crel=m;
        while(cont<=a*(-1)){
            cont++;
            crel--;
            cout<<"cont  "<< cont<<endl;
            if(crel==lim-1 || crel==0){
                crel=m-1;
                cont++;
                cout<< "crel  "<<crel<<endl;
            }

            }
    }

    cout<<"resultado  "<<crel;
    return 0;
}
