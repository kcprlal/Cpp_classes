#include<iostream>
#include<utility>

std::pair<int,int> XOR(int a, int b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    return std::make_pair(a, b);
}

int main(){
    int a=10,b =2;
    std::pair<int, int> p = XOR(a,b);
    std::cout<<p.first<<' '<<p.second<<'\n';
    return 0;
}