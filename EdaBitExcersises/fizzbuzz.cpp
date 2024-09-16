#include <iostream>
int main()
{
    int n = 121;
    for (int i = 1; i < n; ++i)
    {
        if (i % 5 == 0 && i % 3 == 0)
            std::cout << "Fizzbuzz\n";
        else
        {
            if (i % 5 == 0)
                std::cout << "buzz\n";
            else if (i % 3 == 0)
                std::cout << "fizz\n";
            else
                std::cout << i << "\n";
        }
    }
    return 0;
}