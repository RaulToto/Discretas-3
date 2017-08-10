
#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    std::string foo("foo");
    std::string copy(foo);
    std::cout << foo << '\n' << copy << '\n';

    std::reverse(copy.begin(), copy.end());
    std::cout << foo << '\n' << copy << '\n';
}