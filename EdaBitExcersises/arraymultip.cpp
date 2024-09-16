#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<std::string>> multiply(const std::vector<std::string> &arr)
{
    std::vector<std::vector<std::string>> newarr;
    for (const auto &element : arr)
    {
        std::vector<std::string> nesarr(arr.size(), element);
        newarr.push_back(nesarr);
    }
    return newarr;
}

void wyswietl(std::vector<std::vector<std::string>> result)
{
    for (const auto &row : result)
    {
        for (const std::string &element : row)
        {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::vector<std::string> arr1 = {"*", "%", "$"};
    std::vector<std::string> arr2 = {"A", "B", "C", "D", "E"};

    std::vector<std::vector<std::string>> result1 = multiply(arr1);
    std::vector<std::vector<std::string>> result2 = multiply(arr2);

    wyswietl(result1);
    wyswietl(result2);
    return 0;
}