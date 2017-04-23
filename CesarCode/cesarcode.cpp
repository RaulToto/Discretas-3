#include "cesarcode.h"
#include <iostream>
using namespace std;
CesarCode::CesarCode()
    :key(0)
{

}

CesarCode::CesarCode(int k)
    :key(k)
{

}

std::__cxx11::string CesarCode::encrypt(std::string message)
{
    int avanzar;
    for (int i = 0; i < message.length(); ++i) {

        avanzar=(getPos(message[i])+key)%27;
        this->result.push_back(alfabeto[avanzar]);

    }
    return this->result;
}

std::__cxx11::string CesarCode::decrypt(std::string message)
{
    string result1 {};
    string alfabeto1=alfabeto;
    //std::reverse(alfabeto.begin(),alfabeto.end());
    reverse(alfabeto1.begin(),alfabeto1.end());
    int retroceder;

    for (int i = 0; i < message.length(); ++i) {

        retroceder=(getPos(this->result[i])-key)%27;
        if(getPos(this->result[i])<key)
        {
            retroceder=(((getPos(this->result[i])-key)+1)%27);
            if(retroceder<0)
            {
                retroceder=-1*retroceder;
            }
            result1.push_back(alfabeto1[retroceder]);
        }
        else if(getPos(this->result[i])>=key)
        {
            retroceder=(getPos(this->result[i])-key)%27;
            if(retroceder<0)
            {
                retroceder=-1*retroceder;
            }
            result1.push_back(alfabeto[retroceder]);

        }
    }
    return result1;
}

int CesarCode::getPos(char list)
{
    int num=0;
    for (int i = 0; i < alfabeto.length(); ++i) {
        if(list==alfabeto[i])
            num=i;
    }
    return num;
}

