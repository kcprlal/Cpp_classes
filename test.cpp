#include <iostream>

using namespace std;

class test
{
private:
  int element,element2;
public:
  test(int el1, int el2);
  ~test();
  void setElement(int element1){
    this -> element = element1;
  }
  void display();
};

test::test(int el1, int el2):element(el1),element2(el2)
{
}

test::~test()
{
}

void test::display(){
  cout<<"element1: "<<element<<endl;
  cout<<"element2: "<<element2<<endl;
}

int main()
{
  test obj{3,4};
  obj.display();
  obj.setElement(124);
  obj.display();
  return 0;
}
