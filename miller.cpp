#include <bits/stdc++.h>
#include <NTL/ZZ.h>
using namespace NTL;
using namespace std;
ZZ module(ZZ x,ZZ y){
    ZZ q=x/y,r;
    if(q<0)
    {
        q=-1*q;
        q++;
        q=-1*q;
        r=x-(q*y);
    }
    else 
    {
        r=x-(q*y);
    }
    return r;
}
ZZ power(ZZ x,  ZZ y, ZZ p)
{
    ZZ res = conv<ZZ>(1);      // Initialize result
    x =module(x,p);  // Update x if it is more than or
                // equal to p
    while (y > 0)
    {
        // If y is odd, multiply x with result
        ZZ oper;
        ZZ one;
        one =1;
        NTL::bit_and(oper,y,one);

        if (oper>0)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = module((x*x),p);
    }
    return res;
}
 
// This function is called for all k trials. It returns
// false if n is composite and returns false if n is
// probably prime.
// d is an odd number such that  d*2<sup>r</sup> = n-1
// for some r >= 1
bool miillerTest(ZZ d, ZZ n)
{
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    ZZ a = module(conv<ZZ>(2) + rand() , (n - 4));
 
    // Compute a^d % n
    ZZ x = power(a, d, n);
 
    if (x == 1  || x == n-1)
       return true;
 
    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n-1)
    {
        x = module((x * x), n);
        d *= 2;
 
        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
 
    // Return composite
    return false;
}
 
// It returns false if n is composite and returns true if n
// is probably prime.  k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.
bool isPrime(ZZ n, ZZ k)
{
    // Corner cases
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
 
    // Find r such that n = 2^d * r + 1 for some r >= 1
    ZZ d = n - 1;
    while (module(d,conv<ZZ>(2)) == 0)
        d /= 2;
 
    // Iterate given nber of 'k' times
    for (ZZ i = conv<ZZ>(0); i < k; i++)
         if (miillerTest(d, n) == false)
              return false;
 
    return true;
}
 
// Driver program
int main()
{
    ZZ k = conv<ZZ>(4);  // Number of iterations
 
    cout << "All primes smaller than 100: \n";
    for (ZZ n = conv<ZZ>(1); n < 1000; n++)
       if (isPrime(n, k))
          cout << n << " ";
 
    return 0;
}