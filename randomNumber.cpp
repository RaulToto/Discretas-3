#include<iostream>
#include <string>
#include <NTL/ZZ.h>
#include <time.h>
using namespace NTL; 
using namespace std;
ZZ MAX_XOR;
ZZ xorshift_x;
ZZ xorshift_y;
ZZ xorshift_w;
ZZ xorshift_z;

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
void SeedXorShift()
{
    time_t timer = time(NULL);
    struct tm y2k;
    ZZ seconds;
    y2k.tm_hour=0;
    y2k.tm_min=0;
    y2k.tm_sec=0;
    y2k.tm_year=100;
    y2k.tm_mon=0;
    y2k.tm_mday=1;
    seconds= conv<ZZ>(difftime(timer,mktime(&y2k)));
    xorshift_x=seconds;
    xorshift_y=seconds^123456789;
    xorshift_z=seconds << 31;
    xorshift_w=seconds >> 28321;
}
ZZ XorShift()
{
    ZZ tmp;
    //ZZ MAX_XOR ;
    tmp=xorshift_x^(xorshift_x << 11);
    xorshift_x=xorshift_y;
    xorshift_y=xorshift_z;
    xorshift_z=xorshift_w;
    xorshift_w=xorshift_w^(xorshift_w >> 19) ^ (tmp^(tmp >> 8));
    return module(xorshift_w,(conv<ZZ>(MAX_XOR)));
}
//merse
int main()
{
    cout << "imput large number"; cin >> MAX_XOR;
    MAX_XOR=conv<ZZ>(123123123123127765757575757575757);
    cout << endl;
    SeedXorShift();
    ZZ str=conv<ZZ>(1);
    //str=conv<string> (MAX_XOR);
    for (int i = 0; i < 10; i++)
    {
        str*=conv<ZZ> (XorShift());
        //cout << str;
    }
    cout << str ;
}
