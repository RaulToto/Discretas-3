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
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;
void euclides(ZZ &a, ZZ &b)
{
    ZZ q,r;
    q=a/b;
    r=a%b;
    while(r!=0)
    {
        q=a/b;
        r=a%b;
        cout << a  << " = " << q << "(" << b << ")" << "+" << r << endl;
        a=b;
        b=r;
    }
}
int main()
{
    ZZ a,b;
    cout << "input a:" ; cin >> a;
    cout << "input b:" ; cin >> b;
    euclides(a,b);
}

