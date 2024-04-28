#include <iostream>
int main()
{
    auto *wsk = new int;
    std::cout << "na co wskazuje wskaźnik: " << *wsk << "\n";
    std::cout << "adres: " << wsk << "\n";
    *wsk = 465;
    std::cout << "na co wskazuje wskaźnik: " << *wsk << "\n";
    delete wsk;

    std::cout << "----------------------\n";
    int rybka = 46;
    double *wsk2 = reinterpret_cast<double *>(&rybka);
    std::cout<<"a to wskazuje 2"<<*wsk2<<"\n";
    return 0;
}