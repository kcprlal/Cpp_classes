#include <iostream>
using namespace std;

class Board
{
public:
    void drawBoard();
    void restart();
    void setupBoard();
    void makeMove(bool, int, int);
    bool checkIfLegal(int, int, int);

private:
    char field[64];
};

void Board::setupBoard()
{
    for (int k = 0; k < 64; ++k)
    {
        field[k] = ' ';
    }
    for (int i = 0; i < 8; i += 2)
    {
        field[i] = 'x';
        field[9 + i] = 'x';
    }
    for (int i = 0; i < 8; i += 2)
    {
        field[6 * 8 + i] = 'o';
        field[9 + i + 6 * 8] = 'o';
    }
    //Just to test
    /*field[27]='x';
    field[34]='o';
    field[36]='o';*/
}

void Board::drawBoard()
{
    cout << "     #0  #1  #2  #3  #4  #5  #6  #7\n";
    for (int i = 0; i < 8; i++)
    {
        cout << '#' << i * 8;
        if (i == 0 || i == 1)
            cout << ' ';
        cout << " | ";
        for (int j = 0; j < 8; j++)
        {
            cout << field[i * 8 + j] << " | ";
        }
        cout << "\n";
    }
}

bool Board::checkIfLegal(int state, int moveFrom, int moveTo)
{
    if (state == 0)
    {
        if (field[moveFrom] == 'x' && field[moveTo] == ' ' && (moveTo - moveFrom == 7 || moveTo - moveFrom == 9))
            return true;
    }

    else if (state == 1)
    {
        if (field[moveTo] == ' ' && moveTo - moveFrom == 14 && field[moveTo - 7] == 'o')
        {
            field[moveTo-7]=' ';
            return true;
        }
        else if (field[moveTo] == ' ' && moveTo - moveFrom == 18 && field[moveTo -  9] == 'o')
        {
            field[moveTo-9]=' ';
            return true;
        }
    }

    else if (state == 2)
    {
        if (field[moveFrom] == 'o' && field[moveTo] == ' ' && (moveFrom - moveTo == 7 || moveFrom - moveTo == 9))
            return true;
    }

    else if (state == 3)
    {
        if (field[moveTo] == ' ' && moveFrom - moveTo == 14 && field[moveTo + 7] == 'x')
        {
            field[moveTo+7]=' ';
            return true;
        }
        else if (field[moveTo] == ' ' && moveFrom - moveTo == 18 && field[moveTo +  9] == 'x')
        {
            field[moveTo+9]=' ';
            return true;
        }
    }

    return false;
}

void Board::makeMove(bool xplays, int moveFrom, int moveTo)
{
    if (xplays)
    {
        if (checkIfLegal(0, moveFrom, moveTo))
        {
            field[moveFrom] = ' ';
            field[moveTo] = 'x';
        }
        else if (checkIfLegal(1, moveFrom, moveTo))
        {
            field[moveFrom] = ' ';
            field[moveTo] = 'x';
        }

        else
        {
            cout << "ILLEGAL MOVEEEE pick new fields\n";
            cin >> moveFrom >> moveTo;
            cout << '\n';
            makeMove(true, moveFrom, moveTo);
        }
    }
    else
    {
        if (checkIfLegal(2, moveFrom, moveTo))
        {
            field[moveFrom] = ' ';
            field[moveTo] = 'o';
        }
        else if (checkIfLegal(3, moveFrom, moveTo))
        {
            field[moveFrom] = ' ';
            field[moveTo] = 'o';
        }

        else
        {
            cout << "ILLEGAL MOVEEEE pick new fields\n";
            cin >> moveFrom >> moveTo;
            cout << '\n';
            makeMove(false, moveFrom, moveTo);
        }
    }
}

int main()
{
    Board b;
    bool continuegame = true;
    b.setupBoard();
    int moveFrom;
    int moveTo;
    while (continuegame)
    {
        b.drawBoard();
        cout << '\n';
        cout << "Now X plays\n";
        cin >> moveFrom >> moveTo;
        cout << "\n";
        b.makeMove(true, moveFrom, moveTo);

        b.drawBoard();
        cout << '\n';
        cout << "Now O plays\n";
        cin >> moveFrom >> moveTo;
        cout << "\n";
        b.makeMove(false, moveFrom, moveTo);
    }
    return 0;
}