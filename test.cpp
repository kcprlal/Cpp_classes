#include <iostream>

using namespace std;

int main()
{
  int tab[2]{1, 2};
  cout << &tab << endl;
  int *p1 = tab-1;
  cout << &p1 << endl;
  *p1 = 3;
  double* p2=reinterpret_cast<double *>(p1);
  cout << tab[0] << endl;
  *p2=10.2314;
  cout << tab[0] << endl;
  return 0;
}
