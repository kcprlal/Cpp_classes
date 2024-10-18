#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string word{"kajaki"}, temp{};
    temp=word;
    std::reverse(word.begin(),word.end());
    if (temp==word)
    {
        std::cout << "PALINDROME" << std::endl;
    }
    else
        std::cout << "NOT PALINDROME" << std::endl;
    return 0;
}
