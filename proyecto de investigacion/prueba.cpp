#include <iostream>
#include <NTL/ZZ.h>
using namespace NTL;
using namespace std;
int main()
{
    ZZ a;
    a=3;
    
    ZZ b[conv<int>(a)];
}