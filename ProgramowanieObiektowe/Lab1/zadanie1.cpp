#include <iostream>
int main()
{
    int i{}, sum{};
    std::cin >> i;
    if (i < 0)
    {
        std::cout << "must be >0" << std::endl;
        std::cin >> i;
    }
    while (i > 0)
    {
        sum += i;
        std::cout << i << " ";
        i--;
    }
    std::cout << std::endl
              << "sum: " << sum << std::endl;

    return 0;
}