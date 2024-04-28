#include <iostream>
#include <string>

std::string evenorodd(const std::string &number)
{
    int even=0,odd=0;

    for(char element:number){
        element-='0';
        if(element%2==0) even+=element;
        else odd+=element;
    }
    if(even>odd) return "even is gerater";
    else if(even==odd) return "even=odd";
    else return "odd is greater";
}

int main()
{
    std::cout << evenorodd("22174") << "\n";
    std::cout << evenorodd("214") << "\n";
    std::cout << evenorodd("33331") << "\n";
    return 0;
}