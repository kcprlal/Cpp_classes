#include <iostream>
int main()
{
    int array[5]{};
    for (int i{0}; i < 5; ++i)
    {
        std::cout << "enter a number ";
        std::cin >> array[i];
    }
    for (int i{0}; i < 5; ++i)
    {
        std::cout << array[i] << " ";
    }
    return 0;
}