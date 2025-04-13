#include<iostream>

namespace kl{
    class Animal;
}

class kl::Animal
{
public:
   virtual void makeSound()=0;
    virtual ~Animal(){
    std::cout<< "Animal destructor" << std::endl;
   }
};


class Dog : public kl::Animal{
    public:
        void makeSound() override {
            std::cout<<"Woof!"<<std::endl;
        }
        ~Dog(){
            std::cout << "DOG DESTRUCTOR" << std::endl;
        }
};

class Cat : public kl::Animal{
    public:
        void makeSound() override{
            std::cout<<"Meow!"<<std::endl;
        }
        ~Cat(){
            std::cout << "CAT DESTRUCTOR" << std::endl;
        }
};

kl::Animal* chooseAnimal(int number){
    if (number%2 == 0) {
        return new Dog();
    } else {
        return new Cat();
    }
}

int main(){
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    kl::Animal *animal = chooseAnimal(x);
    animal->makeSound();
    delete animal;
    return 0;
}