#ifndef CRIPTOGRAPHY_H
#define CRIPTOGRAPHY_H
#include <string>
#include <iostream>
class Criptography
{
public:
    Criptography();
    Criptography(int );
    std::string encrypt(std::string);
    std::string decrypt(std::string);

private:
    int key;
};

#endif // CRIPTOGRAPHY_H
