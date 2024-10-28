#include <iostream>
#include<string>
class Student
{
private:
    std::string m_name;
    int m_age;

public:
    void setAge(int a)
    {
        if (a > 0)
        {
            m_age = a;
        }
    }
    int getAge() const
    {
        return m_age;
    }
    void setName(std::string n)
    {
        if (n != "")//n.size()!=0
        {
            m_name = n;
        }
    }
    std::string getName() const
    {
        return m_name;
    }
};

int main()
{
    Student student1;
    student1.setAge(21);
    student1.setName("Kacper");
    int age = student1.getAge();
    std::string name = student1.getName(); 
    std::cout<<"Student's age: "<<age<<std::endl;
    std::cout<<"Student's name: "<<name<<std::endl;

    student1.setAge(-32);
    student1.setName("");
    age = student1.getAge();
    name = student1.getName(); 
    std::cout<<"Student's age: "<<age<<std::endl;
    std::cout<<"Student's name: "<<name<<std::endl;

    return 0;
}