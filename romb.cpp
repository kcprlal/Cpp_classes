#include <iostream>
int main()
{
    int m = 10;
    // gorna czesc rombu
    for (int i = 0; i <= m / 2; ++i)
    {
        for (int j = m / 2 - i; j > 0; --j)
        {

            std::cout << " ";
        }
        for (int j = 0; j <= i * 2; ++j)
        {
            std::cout << "*";
        }

        std::cout << "\n";
    }
    // dolna czesc rombu
    for (int i = 0; i < m / 2; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            std::cout << " ";
        }
        for (int j = m - 1; j > 0 + i * 2; --j)
        {
            std::cout << "*";
        }

        std::cout << "\n";
    }
    return 0;
}