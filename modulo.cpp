#include <iostream>
using namespace std;
void modulo(int a,int n)
{
    int q,r;
    q=a/n;
    r=a-q;
    if(r<0 and  q<0)
    {
        q=-1*q;
        q++;
    }
    r=a-q;
        
    cout << "q:" << q << endl;
    cout << "r:" << r << endl;
}
int main()
{

    modulo(-255,11);
	//cout << -255/11;
}
