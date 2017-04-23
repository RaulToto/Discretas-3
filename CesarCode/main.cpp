#include "cesarcode.h"
#include <iostream>
#include <string>
using  namespace std;
int main()
{
    int key;
    string message,message1;
    cout << "imput the message" << endl;
    cin >> message;

    cout <<"imput the key  " ; cin >> key;

    CesarCode cesar(key);
    cout << "the message encrypt is  :" <<cesar.encrypt(message) << endl;

    cout << "imput the word for decrypt" << endl;
    cin >> message1;

    cout << "the message decrypt is  :" << cesar.decrypt(message1) << endl;


}

