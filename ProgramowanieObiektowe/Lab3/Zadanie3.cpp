/*Stwórz proste klasy o nazwie GlobalClass, LocalClass oraz BlockClass
niech każda z nich posiada tylko kontruktor domyślny, który wypisuje na standardowe wyjście "Constructor of <nazwa_klasy> called", oraz destruktor domyślny, który wypisuje na standardowe wyjście "Destructor of <nazwa_klasy> called"
stwórz globalny obiekt klasy GlobalClass poza funkcją main*/

#include <iostream>

class GlobalClass
{
private:
public:
    GlobalClass();
    ~GlobalClass();
};

GlobalClass::GlobalClass()
{
    std::cout << "Constructor of class GlobalClass called" << std::endl;
}

GlobalClass::~GlobalClass()
{
    std::cout << "Destructor of class GlobalClass called" << std::endl;
}

class LocalClass
{
private:
public:
    LocalClass();
    ~LocalClass();
};
LocalClass::LocalClass()
{
    std::cout << "Constructor of class LocalClass called" << std::endl;
}
LocalClass::~LocalClass()
{
    std::cout << "Destructor of class LocalClass called" << std::endl;
}

class BlockClass
{
private:
public:
    BlockClass();
    ~BlockClass();
};

BlockClass::BlockClass()
{
    std::cout << "Constructor of class BlockClass called" << std::endl;
}

BlockClass::~BlockClass()
{
    std::cout << "Destructor of class BlockClass called" << std::endl;
}

GlobalClass global_object;

int main()
{
    std::cout<<"Entering main() function"<<std::endl;
    LocalClass local_object;
    {
        BlockClass block_object;
    }
    std::cout<<"Leaving main() function"<<std::endl;
    return 0;
}
