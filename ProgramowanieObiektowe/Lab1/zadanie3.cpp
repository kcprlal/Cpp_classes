#include <cstdlib>
#include <ctime>
#include <iostream>
int main() {
    
    srand(static_cast<unsigned int>(time(0)));
    
    int randomNumber = rand() % 100 + 1;
    int guess{};
    do{
        std::cout<<"enter a number: ";
        std::cin>>guess;
        std::cout<<"\n";
        if(guess>randomNumber){
            std::cout<<"Too high!\n";            
        }
        else if(guess<randomNumber){
            std::cout<<"Too low!\n";
        }
    }while(randomNumber!=guess);
    return 0;
}
