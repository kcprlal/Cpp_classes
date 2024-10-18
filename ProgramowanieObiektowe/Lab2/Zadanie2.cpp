#include<iostream>
#include <string>
#include<algorithm>
int main(){
    std::string word{"let's go"}, temp{};
    int i{};
    for(int i = word.size()-1; i>=0; --i){  
        temp+=word[i];
    }
    std::cout<<temp<<std::endl;
    std::reverse(word.begin(), word.end());
    std::cout<<word<<std::endl;
    return 0;
}