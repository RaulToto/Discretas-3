/* 
 * C++ Program to Implement Miller Rabin Primality Test
 */
 // C++ program Miller-Rabin primality test
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <NTL/ZZ.h>

#define ll long long
using namespace std;
using namespace NTL; 
/* 
 * calculates (a * b) % c taking into account that a * b might overflow 
 */
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
ZZ mulmod(ZZ a, ZZ b, ZZ mod)
{
    ZZ x = conv<ZZ>(0),y =conv<ZZ>(module(a , mod));
    while (b > 0)
    {
        if (module(b,conv<ZZ>(2)) == 1)
        {    
            x = module((x + y), mod);
        }
        y = module((y * 2) , mod);
        //b /= 2;//corregir
        b=b>>1;
    }
    return module(x , mod);
}
/* 
 * modular exponentiation
 */

ZZ modulo(ZZ base, ZZ exponent, ZZ mod)
{
    ZZ x = conv<ZZ>(1);
    ZZ y = base;
    while (exponent > 0)
    {
        if (module(exponent , conv<ZZ>(2)) == 1)
            x =module( (x * y) , mod);
        y = module((y * y) , mod);
        //exponent = exponent / 2;
        exponent=exponent>>1;
    }
    return module(x , mod);
}
 
/*
 * Miller-Rabin primality test, iteration signifies the accuracy
 */
bool Miller(ZZ p,int iteration)
{
    if (p < 2)
    {
        return false;
    }
    if (p != 2 && module(p ,conv<ZZ>(2))==0)
    {
        return false;
    }
    ZZ s = p - 1;
    while (module(s ,conv<ZZ> (2)) == 0)
    {
        //s /= 2;
        s=s>>1;
    }
    for (int i = 0; i < iteration; i++)
    {
        ZZ a = module(conv<ZZ>(rand()) , (p - 1)) + 1;
        ZZ temp = s;
        ZZ mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && module(temp ,conv<ZZ>(2)) == 0)
        {
            return false;
        }
    }
    return true;
}
//Main
int main()
{
    ZZ a;
    cin >> a;
    if(Miller(a,5))
        cout << "true";
    /*int iteration = 5;
    ll num;
    cout<<"Enter integer to test primality: ";
    cin>>num;
    if (Miller(num, iteration))
        cout<<num<<" is prime"<<endl;
    else
        cout<<num<<" is not prime"<<endl;
    return 0;*/
}