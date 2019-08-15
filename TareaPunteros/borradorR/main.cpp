#include <iostream>

using namespace std;
/*
    w
a       d
    s
*/
int tabla[4][4];
int x=3,y=3;

void imprimir(){
    int i= 0,j;
    while(i<4){
        j=0;
        while(j<4){

            if(tabla[i][j]<10)
                if(tabla[i][j]==0)
                    cout<< "[    ]";
                else
                    cout<<"[  " <<tabla[i][j]<<" ]";
            else
                cout<<"[ " <<tabla[i][j]<<" ]";
            j++;
        }
        cout<<"\n";
        i++;
    }
}

int main()
{
    // ROMPECABEZAS
    int i=0,j= 0,contador = 1;
    char caracter, enter;
    // Inicializar la tabla de juego
    while(i<4){
        j = 0;
        while(j<4){
                tabla[i][j]= contador;
                j++;
                contador++;
        }
        cout<<"\n";
        i++;
    }
    tabla[y][x]=0;
    imprimir();
    do{
        caracter =getchar();
        enter = getchar();
        switch(caracter){
            case 'w'://arriba
                if(y<=2){
                    //moviendo la ficha
                    tabla[y][x] = tabla[y+1][x];
                    tabla[y+1][x]=0;
                    imprimir();
                    y++;
                }
                else
                    cout <<"fuera de limites \n";
                break;
            case 's': //abajo
                if(y>=1){
                    //moviendo ficha
                    tabla[y][x]= tabla[y-1][x];
                    tabla[y-1][x] = 0;
                    imprimir();
                    y--;
                }
                else
                    cout << "fuera del limite \n";
                break;
            case 'a': //izquierda
                if(x<=2){
                    tabla[y][x]= tabla[y][x+1];
                    tabla[y][x+1]=0;
                    imprimir();
                    x++;
                }
                else
                    cout<<"fuera de limites\n";
                break;
            case 'd': // derecha
                if(x>=1){
                    tabla[y][x] = tabla[y][x-1];
                    tabla[y][x-1]=0;
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
