#include "tictactoe.h"

void Board::drawBoard()
{
    std::cout << figure[0] << "|" << figure[1] << "|" << figure[2] << std::endl;
    std::cout << "_____" << std::endl;
    std::cout << figure[3] << "|" << figure[4] << "|" << figure[5] << std::endl;
    std::cout << "_____" << std::endl;
    std::cout << figure[6] << "|" << figure[7] << "|" << figure[8] << std::endl;
}

void Board::move()
{
    int i;
    static bool player = true;
    std::cin >> i;
    if (check(i))
    {
        if (player)
        {
            figure[i - 1] = 'x';
            if (win(figure[i - 1]))
            {
                std::cout << "\n"
                          << figure[i - 1] << " WINS!\n\n\n\n";
                reset();
            }
            else
                player = false;
        }
        else
        {
            figure[i - 1] = 'o';
            if (win(figure[i - 1]))
            {
                std::cout << "\n"
                          << figure[i - 1] << " WINS!\n\n\n\n";
                reset();
            }
            else
                player = true;
        }
    }
    else
        std::cout << "NOT EMPTY!!!!!!!!!!!!\n";
}

void Board::reset()
{
    for (int i = 0; i < 9; i++)
    {
        figure[i] = '-';
    }
}

bool Board::win(char player)
{
    // horizontaly
    if ((figure[0] == player && figure[1] == player && figure[2] == player) ||
        (figure[3] == player && figure[4] == player && figure[5] == player) ||
        (figure[6] == player && figure[7] == player && figure[8] == player))
        return true;
    // vertically
    else if ((figure[0] == player && figure[3] == player && figure[6] == player) ||
             (figure[1] == player && figure[4] == player && figure[7] == player) ||
             (figure[2] == player && figure[5] == player && figure[8] == player))
        return true;
    // slant
    else if ((figure[0] == player && figure[4] == player && figure[8] == player) ||
             (figure[2] == player && figure[4] == player && figure[6] == player))
        return true;
    else
        return false;
}

bool Board::check(int square)
{
    if (figure[square - 1] == '-')
        return true;
    else
        return false;
}