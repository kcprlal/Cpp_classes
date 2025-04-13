#include <iostream>

class Animal
{
public:
    virtual void sound()
    {
        std::cout << "du" << std::endl;
    }
};

class Dog : public Animal
{
public:
    void sound() override
    {
        std::cout << "du1" << std::endl;
    }
};

class Cat : public Animal
{
    public: 
    void sound()
    {
        std::cout << "du2" << std::endl;
    }
};

int main()
{
    Dog dog;
    Animal *ptr = new Dog();
    ptr -> sound();
    delete ptr;
    return 0;
}