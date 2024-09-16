#include <iostream>

int snakefill(int a)
{
    int snake = 1, result = 0;
    while (snake <= a ^ a)
    {
        snake = snake * 2;
        result++;
    }
    return result;
}

int main()
{
    std::cout << snakefill(3) << '\n';
    std::cout << snakefill(6) << '\n';
    std::cout << snakefill(24) << '\n';
    return 0;
}