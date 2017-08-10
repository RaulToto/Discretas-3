#include <iostream>
using namespace std;
float euclides(int  ,int  );
int main()
{
    cout << euclides(13,17) << endl;
}

float euclides(int a ,int b)
{
    if (b==0)
        return a;
    else 
        return euclides(b,a%b);
}