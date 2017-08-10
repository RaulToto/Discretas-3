#include "critography.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
    cout << "WELCOME TO ENCRYPT" << endl;
    std::string message;
    int key;
    cout << "imput the message" << endl;
    getline(cin,message);
    cout << "imput the key for encrypt the message " ; cin>> key;
    Critography cry(message,key);
    cry.encrypt();
    cout << cry.getMessage();
}
