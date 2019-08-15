#include <iostream>
#include <conio.h>
#include <stdio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;
int romp[][4]={{2,3,5,7},{1,10,14,13},{8,4,6,12},{10,11,9,0}};
int tam=sizeof(romp)/sizeof(*romp);
int x=3,y=3;
void imprimir(){

    for(int i=0;i<tam;i++){
        for(int j=0; j<tam; j++){
            if(*(*(romp+i)+j)<10){
                if(*(*(romp+i)+j)==0)
                    cout<< "[    ]";
                else
                    cout<<"[  " <<*(*(romp+i)+j)<<" ]";
            }
            else
                cout<<"[ " <<*(*(romp+i)+j)<<" ]";

        }
        cout << endl;
    }
    cout<<endl;
}

int main()
{
    // ROMPECABEZAS
    char caracter;
    *(*(romp+x)+y)=0;//[y][x]=0;
    imprimir();
    do{
        caracter=getch();

        switch(caracter){
            case KEY_DOWN://abajo
                if(y<=2){
                    //moviendo la ficha y=c,x=f
                    *(*(romp+y)+x) = *(*(romp +y+1)+x);
                    *(*(romp+y+1)+x)=0;
                    system("cls");
                    imprimir();
                    y++;
                }
                else
                    cout <<"fuera de limites \n";
                break;
            case KEY_UP: //arriba
                if(y>=1){
                    //moviendo ficha
                    *(*(romp+y)+x)=*(*(romp+y-1)+x);
                    *(*(romp+y-1)+x)=0;
                    system("cls");
                    imprimir();
                    y--;
                }
                else
                    cout << "fuera del limite \n";
                break;
            case KEY_RIGHT: //derecha
                if(x<=2){
                    *(*(romp+y)+x)=*(*(romp+y)+x+1);
                    *(*(romp+y)+x+1)=0;
                    system("cls");
                    imprimir();
                    x++;
                }
                else
                    cout<<"fuera de limites\n";
                break;
            case KEY_LEFT: // izquierda
                if(x>=1){
                    *(*(romp+y)+x)=*(*(romp+y)+x-1);
                     *(*(romp+y)+x-1)=0;
                     system("cls");
                    imprimir();
                    x--;
                }
                else
                    cout <<"fuera de limites\n";
                break;
        }
    }while(caracter != '0');
    return 0;
}
