#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
unsigned t0,t1;
int menor(int x,int y)
{
    if(y<x)
        return y;
    else 
        return x;
}
int lsbgcd(int u, int v)
{
    t0=clock();
    int a,b,t,aux,s;
    a=abs(u);
    b=abs(v);
    while(b!=0)
    {
        s=0;
        while(b*pow(2,s)<=a)
        {
            s=s+1;
        }
        s=s-1;
        t=menor(a-b*pow(2,s),b*pow(2,s+1)-a);
        a=b;
        b=t;
        if(a<b)
        {
            aux=a;
            a=b;
            b=aux;
        }
    }   
    return a;
    t1=clock();
}
int main()
{
    cout << lsbgcd(89,44) << endl;

    double time=(double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution time:" << time << endl;
}