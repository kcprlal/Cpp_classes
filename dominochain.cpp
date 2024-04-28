#include <iostream>
#include <string>
std::string dominoChain(const std::string& chain)
{
    std::string result;
    bool stop=false;
    for(char element:chain){
        if(element=='|'&&stop==false) result.push_back('/');
        else {
                result.push_back(element);
                stop=1;
            }
    }
    return result;
}
int main()
{
    std::cout << dominoChain("||| ||||//| |/")<<'\n';
    std::cout << dominoChain("||//||")<<'\n';
    std::cout << dominoChain("||||")<<'\n';
    return 0;
}