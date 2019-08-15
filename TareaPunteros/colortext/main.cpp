#include <iostream>

using namespace std;
//para consola de windows
int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // you can loop k higher to see more color choices
    for(int k = 1; k < 255; k++){
        // pick the colorattribute k you want
        SetConsoleTextAttribute(hConsole, k);
        cout << k << "Hello world!" << endl;
    }
    return 0;
}
