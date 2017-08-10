#ifndef CRITOGRAPHY_H
#define CRITOGRAPHY_H
#include <iostream>
#include <string>

class Critography
{
public:
    Critography();
    Critography(std::string , int );
    std::string getMessage();
    int getKey();
    void setMessage(std::string );
    void setkey(int);
    std::string encrypt();
    std::string decrypt();

private:
    std::string message;
    int key;
};

#endif // CRITOGRAPHY_H
