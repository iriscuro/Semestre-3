#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void romboS(int num){
    int a, n, n1;
    int res=num/2;//cout<<res;
    int contador = 0;
    for (a = num/2; a >= 0; a--){
		 for (n = 0; n <=a; n++){
			 printf(" ");
		 }
		 for (n1 = 0; n1 <=contador; n1++){
			 printf("*");
		 }
		 printf("\n");
		 contador += 2;
		 }

	 for (a = res; a > 0; a--){
	     printf(" ");
		 for (n = res; n >= a; n--){
			 printf(" ");
		 }
		 for (n1 = 3; n1 < contador; n1 ++){
			 printf("*");
		 }
		 printf("\n");
		 contador -= 2;
	 }
}
int main()
{
    int num;
    cout<< " Ingrese el numero impar:\t";
    cin>>num;
    romboS(num);

    return 0;
}
