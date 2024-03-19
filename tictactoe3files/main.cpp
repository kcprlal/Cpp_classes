#include "tictactoe.h"
#include <iostream>

int main()
{
    Board b;
    while (true)
    {
        b.drawBoard();
        b.move();
    }
    return 0;
}