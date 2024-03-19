#include <iostream>

class Board
{
public:
    void drawBoard();
    void move();
    void reset();

private:
    char figure[9]{'-', '-', '-', '-', '-', '-', '-', '-', '-'};
    bool check(int);
    bool win(char);
};