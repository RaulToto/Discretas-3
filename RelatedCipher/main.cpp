#include <iostream>
//#include <NTL/ZZ.h>
#include "relatedcipher.h"
using namespace std;
//using namespace NTL;
int main()
{
    int a,b,c;
    RelatedCipher cipher(7,1);
    string message,message1;
    cout << "imput the message" << endl;
    cin >> message;
    cout << "mensaje encriptado " << cipher.encrypt(message) << endl;
    //___________________________________________________
    cout << "imput message for decrypt" << endl;
    cin >> message1;
    cout << "the message decrypt is " << cipher.decrypt(message1) << endl;
}
