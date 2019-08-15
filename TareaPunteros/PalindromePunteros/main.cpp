#include <iostream>

using namespace std;

void isPalindrome(char *palabra,int t){
    char *fin = &palabra[t-2];//no tomando el caracter nulo
    char *ini = palabra;
    while(ini< fin ){
        if(*ini==*fin){
            fin--;
            ini++;

            if(*ini== 32){
                ini++;
            }
            if(*fin== 32){
                fin--;
            }
        }
        else
            break;
    }
    if(ini>=fin)
        cout << "yes";
    else
        cout << "No";
}

int main()
{
    //char word[]= "anita lava la tina";
    //char word[]= "aman a panama";
    //char word[]= "adan no calla con nada";
    //char word[]= "alli ves sevilla";
    //char word[]= "anitalavalatina
    char word[]= "arde ya la yedra";

    int tam=sizeof(word)/sizeof(*word);
    for (int i = 0; i < tam; i++) {
        word[i] = word[i];
        cout << word[i];//imprime el caracter nulo del final
    }
    cout <<"/" <<endl;
    cout << "tam: "<<tam<<endl;
    isPalindrome(word,tam);

    return 0;
}
