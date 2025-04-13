#include <iostream>
#include "ComplexNumber.hpp"

int main()
{
    kl::jpo::ComplexNumber<int> number1(2, 23);
    kl::jpo::ComplexNumber<int> number2(1, 31);
    bool num1{};
    bool num2{};
    std::cout << "add: " << number1 + number2 << std::endl;
    std::cout << "subt:" << number1 - number2 << std::endl;
    std::cout << "multi: " << number1 * number2 << std::endl;
    std::cout << "div: " << number1 / number2 << std::endl;
    std::cout << "add double: " << number1 + 2.0 << std::endl;
    std::cout << "sub duouble: " << number1 - 3.0 << std::endl;

    num1 = (number1 == number2);
    std::cout << "==: " << num1 << std::endl;
    num2 = (number1 != number2);
    std::cout << "!=: " << num2 << std::endl;
    number1 += number2;
    std::cout <<"+=: "<< number1 << std::endl;
    number1 -= number2;
    std::cout <<"-=: "<< number1 << std::endl;
    number1 *= number2;
    std::cout <<"*=: "<< number1 << std::endl;
    number1 /= number2;
    std::cout <<"/=: "<< number1 << std::endl;
    return 0;
}