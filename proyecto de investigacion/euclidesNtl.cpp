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
#include <ctime>
using namespace std;//using std namespace 
using namespace NTL;//using NTL namespaces
unsigned t0,t1;
 
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
    t0=clock();
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

 