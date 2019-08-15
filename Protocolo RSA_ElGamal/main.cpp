#include <NTL/ZZ.h>
#include <NTL/vector.h>

using namespace std;
using namespace NTL;

ZZ sum(const Vec<ZZ>& v)
{
   ZZ acc;

   acc = 0;

   for (long i = 0; i < v.length(); i++)
      acc += v[i];

   return acc;
}

int main()
{
   ZZ a, b, c;

   cin >> a;
   cin >> b;
   c = (a+1)*(b+1);
   cout << c << "\n";
}
