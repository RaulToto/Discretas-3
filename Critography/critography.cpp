#include "critography.h"
using namespace std;
Critography::Critography()
    :message(NULL),key(0)
{

}

Critography::Critography(std::__cxx11::string ss, int k)
    :message(ss),key(k)
{

}

std::__cxx11::string Critography::getMessage()
{
    return this->message;
}

int Critography::getKey()
{
    return this->key;
}

void Critography::setMessage(std::__cxx11::string mess)
{
    this->message=mess;
}

void Critography::setkey(int  k)
{
    this->key=k;
}

std::__cxx11::string Critography::encrypt()
{
    cout << "hello world";
    /*
    string list {};
    int avanzar=(2*key)-2;
    for (int  i= 0; i < this->message.length(); i++) {
        list.push_back(message[i]);
        while(message[avanzar]!=' ' )
        {
            if(i<(key-2)/2)
            {
                list.push_back(message[avanzar]);
                list.push_back(message[avanzar-i]);
                list.push_back(message[avanzar+i]);
            }
            else
                i=message.length();
            avanzar*=2;
        }
     }
    return list;*/
}

std::__cxx11::string Critography::decrypt()
{

}
