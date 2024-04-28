#include <iostream>
#include <cmath>
int integral(int b, int m, int n)
{
    return (pow(n,b+1)-pow(m,b+1));
}

int main()
{
    std::cout << integral(0, 2, 5) << '\n';
    std::cout << integral(2, 4, 7) << '\n';
    std::cout << integral(5, 9, 3) << '\n';
    return 0;
}