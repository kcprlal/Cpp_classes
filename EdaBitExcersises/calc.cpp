#include<iostream>

class Calc
{
public:
    int multiply(int,int);
};

Calc::multiply(int a, int b){
    return a*b;
}

int main(){
    int m=5,n=10;
    Calc wynik;
    std::cout<<wynik.multiply(m,n)<<std::endl;
    return 0;
}