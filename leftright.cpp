#include <iostream>
#include <vector>
#include <string>

int spinAround(std::vector<std::string> &dir)
{
    int r = 0, l = 0;
    for (const std::string &kierunek : dir)
    {
        if (kierunek == "left")
            r += 1;
        else if (kierunek == "right")
            l += 1;
    }
    return abs(r - l) / 4;
}

int main()
{
    std::vector<std::string> directions1 = {"left", "right", "left", "right"};
    std::vector<std::string> directions2 = {"right", "right", "right", "right", "right", "right", "right", "right"};
    std::vector<std::string> directions3 = {"left", "left", "left", "left"};

    std::cout << spinAround(directions1) << std::endl;

    std::cout << spinAround(directions2) << std::endl;

    std::cout << spinAround(directions3) << std::endl;
    return 0;
}