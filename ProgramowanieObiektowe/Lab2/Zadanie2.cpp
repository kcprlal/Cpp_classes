#include <iostream>
#include <string>
#include <algorithm>
int main()
{
    std::string word{}, temp{};
    int i{};

    std::cin >> word;

    for (int i = word.size() - 1; i >= 0; --i)
    {
        temp += word[i];
    }
    std::cout << "rotated manually: " << temp << std::endl;
    std::reverse(word.begin(), word.end());
    std::cout << "rotated by function: " << word << std::endl;
    return 0;
}