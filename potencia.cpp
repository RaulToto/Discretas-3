#include <iostream>
using namespace std;
int main()
{
    int potencia =10;
    for (int i = 0; i < potencia; i++)
    {
        cout << "2^" << i  << "=" << (1<<i) << endl; 
    }
}
