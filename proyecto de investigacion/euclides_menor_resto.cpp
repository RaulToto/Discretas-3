

#include <iostream>
#include <NTL/ZZ.h>//includ  the lib ntl 
#include <ctime>
using namespace std;//using std namespace 
using namespace NTL;//using NTL namespaces
unsigned t0,t1;
ZZ menor(ZZ x,ZZ y)
{
    if(y<x)
        return y;
    else 
        return x;
}
void euclides(ZZ &a, ZZ &b)//
{
    t0=clock();
    ZZ q,q1,r;
    q=a/b;
    q1=q;q1++;
    r=menor(a-(q*b),a-(q1*b));
    //r=a%b;
    while(r!=0)
    {
        q=a/b;
        q1=q;q++;
        r=menor(a-(q*b),a-(q1*b));
        cout << a  << '\t'<<  " = " << q << "(" << b << ")" << "+" << r << endl;//print the euclides algorithm
        a=b;
        b=r;
    }
    t1=clock();
}
int main()
{
    ZZ a,b;
    cout << "input a:" ; cin >> a; //imput the numbers 
    cout << "input b:" ; cin >> b;
    euclides(a,b);
    double time=(double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution time:" << time << endl;

}