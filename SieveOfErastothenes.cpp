#include <iostream>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;
#define MaxSize 100000000
//ZZ sizeMatrix
void sieveOfErastothenes(ZZ &val)
{
    //creaete a  size of matrix
    int row,cols=0;
    ZZ copyVal;
    copyVal=val;
    cout << "the cppy val is " << copyVal<<endl;
    if(val> MaxSize ) 
    {
        cout << "ingresa" << endl;
        while(copyVal>MaxSize)
        {
            cols++;
            copyVal=copyVal-MaxSize;
            cout << "new copyval" << copyVal << endl;
        }
    }
    cout << "the new cols is " << cols << endl;
    //create a matrix for creba

    /*bool **vec= new bool*[size];
    for (int i = 0; i < size; i++)
    {
        vec[i]=new bool[8];
    }*/

}
int main()
{
    ZZ n;
    cout << "input a number:"; cin >> n;
    sieveOfErastothenes(n);
}