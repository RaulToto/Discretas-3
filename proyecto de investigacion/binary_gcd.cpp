#include <iostream>
#include <NTL/ZZ.h>
#include <ctime>
using namespace std;
using namespace NTL;
unsigned t0,t1;
ZZ binary_gcd( ZZ u,ZZ v)
{
  t0=clock();
  int i;
  if (u == 0) return v;
  if (v == 0) return u;
  for (i = 0; ((u | v) & 1) == 0; ++i) {
         u >>= 1;
         v >>= 1;
  }
 
  while ((u & 1) == 0)
    u >>= 1;
  do {
       while ((v & 1) == 0)  
           v >>= 1;
       if (u > v) {
          ZZ t = v; v = u; u = t;}  
       v = v - u;                       
     } while (v != 0);
  return u << i;
  t1=clock();
}
int main()
{
  
    ZZ a,b;
    cout << "input a:" ; cin >> a; //imput the numbers 
    cout << "input b:" ; cin >> b;
    cout << binary_gcd(a,b) << endl;
    double time=(double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution time:" << time << endl;
}