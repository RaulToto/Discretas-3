// C++ program Miller-Rabin primality test
#include <bits/stdc++.h>
#include <iostream>
#include <NTL/ZZ.h>
#include <time.h>
#include <stdbool.h>
using namespace NTL;
using namespace std;
//bbs
ZZ n_bbs;
ZZ xi_bbs;
ZZ MAX_XOR=conv<ZZ>(12312312312312);
//xorshift
ZZ xorshift_x;
ZZ xorshift_y;
ZZ xorshift_w;
ZZ xorshift_z;

class BitVector
{
    public:
        BitVector(int x) {
            if(x%8==0){
                vector=new unsigned char[x/8];
                tam=x/8;
            }
            else{
                vector=new unsigned char[(x/8)+1];
                tam=(x/8)+1;
            }

            for(int i=0;i<tam;i++)
            {
                vector[i]=0;
            }
        }
        virtual ~BitVector() {

            delete [] vector;
        }

        void SetBit(int pos, bool def);
        bool getBit(int pos);
        void ShowRow();
    //protected:
    //private:

        unsigned char * vector;
        int tam;
};

void BitVector::SetBit(int pos, bool def)
{
    int part=pos/8;
    int pos_part=pos%8;
    unsigned char adolfo=1<<pos_part;

    if(def)
    {
        vector[part]=vector[part]|adolfo;
    }
    else
    {
        int tmp= ~adolfo;
        vector[part]=vector[part]&tmp;
    }

}

bool BitVector::getBit(int pos)
{

    int part=pos/8;
    int pos_part=pos%8;
    unsigned char adolfo=1<<pos_part;
    return (vector[part]&adolfo);

}

void BitVector::ShowRow()
{
    for(int i=0;i<tam;i++)
    {
        cout<<(int)vector[i]<<endl;
    }
    cout<<endl;
}

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
ZZ expModulo(ZZ base, ZZ exponent, ZZ mod)
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
//xorshift
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
void SeedBBS()
{
    ZZ p;
    ZZ q;
    p=13;
    q=37;
    n_bbs=p*q;
    ZZ seed=XorShift();
    xi_bbs=expModulo(seed,conv<ZZ>(2),n_bbs);//call exp modular
}
ZZ BlumBlumShub(int tam)
{
    ZZ res;
    BitVector bits(tam);
    for (int i = tam-1; i>=0; i--)
    {
        xi_bbs=expModulo(xi_bbs,conv<ZZ>(2),n_bbs);
        bits.SetBit(i,(xi_bbs%2)==1);
    }
    res=ZZFromBytes(bits.vector,tam/8);
    if(module(res,conv<ZZ>(2))==0)
        res+=1;
    return res;
}
int main()
{
    SeedXorShift();
    SeedBBS();
    int tam =64;
    for (int i = 0; i < 10; i++)
    {
        SeedBBS();
        cout << BlumBlumShub(1024) << endl;
    }
    
}
