#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
#include <string.h>
using namespace NTL;
//#include "linkedlist.h"
//#include "node.h"
//#include "sieve.h"
using namespace std;
int main(int argc, char *argv[])
{
    vector<bool> *ptr= new vector<bool>(1000);
    memset(ptr,0,1000);
    for (int i = 0; i < 1000; ++i) {
        cout << ptr[i] << endl;
    }
}
