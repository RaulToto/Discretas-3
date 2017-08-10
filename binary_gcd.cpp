#include <iostream>
#include <NTL/ZZ.h>//includ  the lib ntl 
using namespace std;//using std namespace 
using namespace NTL;//using NTL namespaces
#define ISODD(x) ((x) & 0x1)
#define ISEVEN(x) (!ISODD(x))
unsigned int gcd_binary(unsigned int a, unsigned int b) 
{   /*  Returns gcd(a, b) */
    unsigned int r, t, k;
    if (a < b) { 
        t = a;
        a = b;
        b = t;
    }
    if (0 == b) {
        return a;
    }
    r = a % b;
    a = b;
    b = r;
    /* If b = 0 output a and stop */
    if (0 == b) {
        return a;
    }
    /* 2. [Compute power of 2] */
    k = 0;  /* g = 2^k <-- 1 */
    while (ISEVEN(a) && ISEVEN(b)) {    
        /* While a and b are even */
        a >>= 1;  /* a <-- a/2 */
        b >>= 1;  /* b <-- b/2 */
        k++;      /* g <-- 2g */
    }
    while (a != 0) {
        while (ISEVEN(a)) {
            a >>= 1;  
        }
        while (ISEVEN(b)) {
            b >>= 1;  
        }
        if (b > a)
            t = (b - a) >> 1;
        else
            t = (a - b) >> 1;
        if (a >= b)
            a = t;
        else
            b = t;
    }
    return (b << k);
}

int main()
{
    int a,b;
    cout << "input a:" ; cin >> a; //imput the numbers 
    cout << "input b:" ; cin >> b;
    cout << gcd_binary(a,b) << endl;
    return 0;
}