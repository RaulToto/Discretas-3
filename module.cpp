#include "module.h"
#include <iostream>
#include <cmath>
using namespace std;
//int modul(int &,int &);
int main()
{
    int a=-255;
    int b=11;
    cout << modul(a,b);
}
/*
int modul(int &x,int &y){
    int q=x/y,r;
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
}*/