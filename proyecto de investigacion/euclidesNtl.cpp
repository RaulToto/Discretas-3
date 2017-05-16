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
    ZZ q,r;
    q=a/b;
    r=module(a,b);
    while(r!=0)
    {
        q=a/b;
        r=module(a,b);
        cout << a  << '\t'<<  " = " << q << "(" << b << ")" << "+" << r << endl;//print the euclides algorithm
        a=b;
        b=r;
    }
}
int main()
{
    ZZ a,b;
    cout << "input a:" ; cin >> a; //imput the numbers 
    cout << "input b:" ; cin >> b;
    euclides(a,b);
}

