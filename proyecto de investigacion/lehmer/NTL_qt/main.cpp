/*//g++ hola.cpp -o m -lntl -lgmp -lm*/
        /*//////////////////////////////////////////////////////
       ///  *@file BaseConverter.h                          ///
      ///   * @version 1.0                                 ///
     ///    * @date 19/04/17                              ///
    ///     * @author Raul Edgar Quispe Totocayo         ///
   ///      * @title BaseConverter                      ///
  ///       * @brief this program using the libntl     ///
 //////////////////////////////////////////////////////*/

#include <iostream>
#include <NTL/ZZ.h>//includ  the lib ntl
using namespace std;//using std namespace
using namespace NTL;//using NTL namespaces
ZZ module(ZZ &x,ZZ &y){
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
void euclides(ZZ &a, ZZ &b)//
{
    ZZ q,r,r1=a,r2=b,s,s1,s2,t,t1,t2;
    s1=1,s2=0,t,t1=0,t2=1;
    cout << "q" << "\t"<<"r1 "<< "\t" << "r2 "<< "\t" << "r "<< "\t" << "s1 "<< "\t" << "s2 "<< "\t" << "s "<< "\t" << "t1" << "\t"<< "t2 " << "\t"<< "t " << endl;
    while(r2>0)
    {
        q=r1/r2;
        r=r1-(q*r2);
        r1=r2;
        r2=r;
        //-----
        s=s1-(q*s2);
        s1=s2;
        s2=s;
        //cout << s << "\t" << s1 << "\t" << s2 << endl;
        //-------
        t=t1-(q*t2);
        t1=t2;
        t2=t;
        cout << q << "\t" << r1<< "\t" << r2<< "\t" << r<< "\t" << s1<< "\t" << s2<< "\t" << s<< "\t" <<t1<< "\t" <<t2<< "\t" << t << endl;
    }
}

int main()
{
    ZZ a,b;
    cout << "input a:" ; cin >> a; //imput the numbers
    cout << "input b:" ; cin >> b;
    euclides(a,b);
}
