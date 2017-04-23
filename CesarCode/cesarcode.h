#ifndef CESARCODE_H
#define CESARCODE_H

#include <string>
#include <iostream>
#include <algorithm>
class CesarCode
{
public:
    CesarCode();
    CesarCode(int );
    std::string encrypt(std::string);
    std::string decrypt(std::string);
    int getPos(char);
    std::string reverseString(std::string);
private:
    int key;
    //std::string message;
    std::string alfabeto="abcdefghijklmnopqrstuvwxyz*";

    std::string result{};
};

#endif // CESARCODE_H
