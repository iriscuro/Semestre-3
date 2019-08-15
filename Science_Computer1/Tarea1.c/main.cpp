#include <iostream>

using namespace std;
void camV(float cambio,float arr[],int lenA){
    int i=0;
    float cant=0;
    while(cambio >=0 && i<lenA){
        if(cambio >=arr[i]){
            cant=cambio/arr[i];
            cout<<"Cantidad de billetes/monedas de "<< arr[i] <<" -> "<< cant <<endl;
            }
        else{

            cant=0;
            i++;
        }
        cambio-=(arr[i]*cant);
        }

}

int main()
{
    float  cantidad,cambio,dinero;
    float denomM[]={200,100,50,20,10,5,2,1,0.5,0.2,0.1,0.05,0.01};
    /*
    cout << "Ingrese la cantidad con la que paga:"<<'\t';
    cin >> dinero;
    cout << "Monto gastado en el/los  producto/s: "<<'\t';
    cin>> cantidad;
    cambio=dinero-cantidad;
    if(dinero<cantidad)
        cout <<"Su pago no cubre su gasto..."<<endl;
    else{
        cout<<"El cambio es: "<<cambio<<endl;
        camV(cambio,denomM,13);
    }
*/
    cin>>cambio;
    camV(cambio,denomM,13);
    /*
    int cantidad, cambio,dinero;
    int p100=0,p50=0,p20=0,p10=0,p5=0,p1=0;
    cout << "billete con el que paga: " <<'\t';
    cin>> dinero;
    cout << "monto gastado en el producto: "<<'\t';
    cin>> cantidad;
    cambio=dinero-cantidad;
    while(cambio !=0){
        if(cambio >= 100){
            p100++;
            cambio-=100;
        }
        else if(cambio>=50){
            p50++;
            cambio-=50;
        }
        else if(cambio>=20){
            p20++;
            cambio-=20;
        }
        else if(cambio>=10){
            p10++;
            cambio-=10;
        }
        else if(cambio>=5){
            p5++;
            cambio-=5;
        }
        else if(cambio>=1){
            p1++;
            cambio-=1;
        }

    }

    cout<<"El cambio es: "<<endl;
    cout<<"Cantidad de billetes de 100.00 ->"<<p100<<endl;
    cout<<"Cantidad de billetes de 50.00 ->"<<p50<<endl;
    cout<<"Cantidad de billetes de 20.00 ->"<<p20<<endl;
    cout<<"Cantidad de billetes de 10.00 ->"<<p10<<endl;
    cout<<"Cantidad de billetes de 5.00 ->"<<p5<<endl;
    cout<<"Cantidad de billetes de 1.00 ->"<<p1<<endl;
    //cout<<"Cantidad de billetes de 100.00 ->"<<p100<<endl;
    //cout<<"Cantidad de billetes de 100.00 ->"<<p100<<endl;
    */
    return 0;
}
