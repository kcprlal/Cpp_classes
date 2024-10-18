#include <iostream>
#include <string>
int main()
{
    std::string sentence{"Ala Ma kota"};
    int letter_counter[26]{};
    char letter{'a'};
    for (const auto &element : sentence)
    {
        ++letter_counter[std::tolower(element) - 'a'];
    }
    for (const auto &element : letter_counter)
    {
        std::cout<<element<<" ";
    }
    std::cout<<std::endl;
    for(int i = 0; i<26; ++i){
        std::cout<<static_cast<char>(letter+i)<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
