#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
void euclides_extendido(int a ,int b)
{

}

void euclides(int a , int b)
{
    ofstream file;
    file.open("euclides.txt");

   int q,r;
    q=a/b;
    r=a%b;
    while(r!=0)
    {
        q=a/b;
        r=a%b;
        cout << a  << " = " << q << "(" << b << ")" << "+" << r << endl;
        file << a  << "=" <<  q<< "+" << b<< "+" << r<< endl;
        a=b;
        b=r;
            
    }
    file.close();
    //archivo para entrar
    /*
    ifstream inputFile;
    string frase;
    inputFile.open("euclides.txt");
    if (inputFile.is_open())
    {
        while(!inputFile.eof())
        {
            getline(inputFile,frase);   
            cout << frase << endl;
        }
        inputFile.close();
    }
    inputFile.close();
*/


}
int main()
{
    //euclides(250,111);
    int a,b;
    cout << "imput a--:" ;cin>>a;
    cout << "imput b--:" ;cin>>b;
    
    euclides(a,b);
}