#include <iostream>
#include <vector>

std::vector<int> rangedReversal(const std::vector<int> &vec, int a, int b)
{
    std::vector<int> result = vec;
    for (int i = a, j = 0; i <= b; i++, j++)
    {
        result[i] = vec[b - j];
    }
    return result;
}

void wyswietl(std::vector<int> result)
{
    for (auto element : result)
    {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::vector<int> result1 = rangedReversal({0, 1, 2, 3, 4}, 0, 3);
    std::vector<int> result2 = rangedReversal({0, 1, 2, 3, 4}, 1, 4);
    std::vector<int> result3 = rangedReversal({0, 1, 2, 3, 4}, 2, 3);

    wyswietl(result1);
    wyswietl(result2);
    wyswietl(result3);
    return 0;
}