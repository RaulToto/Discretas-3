#ifndef RELATEDCIPHER_H
#define RELATEDCIPHER_H

#include <string>
class RelatedCipher
{
public:
    RelatedCipher();
    RelatedCipher(int k,int k1);
    std::string encrypt(std::string);
    std::string decrypt(std::string);
    int module(int,int);
    int euclides(int,int);

private:
    int key,key1;
    std::string alfabeto="abcdefghijklmnopqrstuvwxyz";
};

#endif // RELATEDCIPHER_H
