#include <iostream>
#include <NTL/ZZ.h>
using namespace NTL;
using namespace std;
ZZ module(ZZ  x , ZZ  y)
{
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

long modular(long dato ,long exp, long modulo)
{
    long resultado;
    resultado=1;
    cout <<"exp%2"<<'\t'<< "a^2" << '\t' << "resultado" << '\t' << "exp/2" << endl;
    
    while(exp>0)
    {
        if(exp%2==1)
        {
            resultado=(resultado*dato)%modulo;
        }
        dato=(dato*dato)%modulo;
        exp=exp/2;
        cout <<exp%2<<'\t'<< dato << '\t'<<  resultado << '\t'<<'\t'<< exp  << endl; 
        //exp=exp>>1;
    }
    cout << "resultado" <<  resultado;
}

ZZ expModule(ZZ base , ZZ exponent, ZZ mod)
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

int main()
{
    ZZ a,b,c;
    cout << "input base ?" ; cin >> a;
    cout << "input exponent ?" ; cin >> b;
    
    cout << "input module ?" ; cin >> c;
    cout << expModule(a,b,c);
}
