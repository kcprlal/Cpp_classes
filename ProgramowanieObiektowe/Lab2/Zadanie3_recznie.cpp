#include <iostream>
#include <string>
#include <algorithm>

/*bool palindrome(const std::string &word, const std::string &reversed_word)
{
    for (int i = 0; i < word.size() / 2; ++i)
    {
        if (word[i] != reversed_word[i])
            return false;
        else
            continue;
    }
    return true;
}*/

int main()
{
    std::string word{"kajadsk"}, temp{};
    int i{};
    for (int i = word.size() - 1; i >= 0; --i)
    {
        temp += word[i];
    }
    if (word==temp)
    {
        std::cout << "PALINDROME" << std::endl;
    }
    else
        std::cout << "NOT PALINDROME" << std::endl;
    return 0;
}

