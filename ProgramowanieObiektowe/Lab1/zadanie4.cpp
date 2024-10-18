#include<iostream>

double func_fahrenheit(double f){
    return (f-32)*0.55;
}

int main(){
    double celsius, fahrenheit{};
    std::cout<<"Fahrenheit: ";
    std::cin>>fahrenheit;
    celsius=func_fahrenheit(fahrenheit);
    std::cout<<"your temp in celsius "<<celsius<<"\n";
}