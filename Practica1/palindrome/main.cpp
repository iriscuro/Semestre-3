#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool palindrome(string palabra){
    size_t i=0,f;
    size_t t=palabra.size();
    size_t it =t/2;
    f=t-1;
    while(i<=it){
        if(palabra[i]==palabra[f])  {
            i++;
            f--;
        }
        else
            break;
            }
    if(i-1==it)
        return true;
    else
        return false;
    }

int main()
{
    //Pregunta 5

    int i=0;
    string palabra,mit1,mit2;
    cout << " string:\t";
    cin>>palabra;
    if(palindrome(palabra)==1){
        cout<<" SI \n";
    }
    else
        cout <<" NO \n";
    return 0;
}
