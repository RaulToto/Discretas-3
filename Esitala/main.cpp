#include "criptography.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int key;
    string message,message1;
    cout << "imput the message" << endl;
    cin >> message;

    cout <<"imput the key  " ; cin >> key;

    Criptography cripto(key);
    cout << "the message encrypt is  :" <<cripto.encrypt(message) << endl;

    cout << "imput the word for decrypt" << endl;
    cin >> message1;

    cout << "the message decrypt is  :" << cripto.decrypt(message1) << endl;

}
