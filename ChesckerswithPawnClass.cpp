#include <iostream>
using namespace std;

class Pawn
{
public:
    bool isPromoted;
    int fieldNumber;
};

class Board
{
public:
    void drawBoard();
    void setupBoard();
    void makeMove(bool, int, int);
    bool checkIfLegal(int, int, int, bool, bool);
    bool checkForWin(bool);
    ~Board();

private:
    char field[64];
    int Xpawns;
    int Opawns;
    bool onSiteLeft;
    bool onSiteRight;
    bool onSiteLeftTake;
    bool onSiteRightTake;
};

Board::~Board()
{
    cout << "\nWORKING\n";
}

void Board::setupBoard()
{

    Xpawns = 8;
    Opawns = 8;
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
    // Just to test
    field[27] = 'x';
    field[34] = 'o';
    field[36] = 'o';
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

bool Board::checkIfLegal(int state, int moveFrom, int moveTo, bool onLeft, bool onRight)
{
    if (moveTo > 0 && moveTo < 64 && moveFrom > 0 && moveFrom < 64)
    {
        if (state == 0)
        {
            if (onLeft)
            {
                if (field[moveFrom] == 'x' && field[moveTo] == ' ' && moveTo - moveFrom == 9)
                    return true;
                else
                    return false;
            }
            else if (onRight)
            {
                if (field[moveFrom] == 'x' && field[moveTo] == ' ' && (moveTo - moveFrom == 7))
                    return true;
                else
                    return false;
            }
            else
            {
                if (field[moveFrom] == 'x' && field[moveTo] == ' ' && (moveTo - moveFrom == 7 || moveTo - moveFrom == 9))
                    return true;
            }
        }

        else if (state == 1)
        {
            if (onLeft)
            {
                if (field[moveTo] == ' ' && moveTo - moveFrom == 18 && field[moveTo - 9] == 'o')
                {
                    field[moveTo - 9] = ' ';
                    return true;
                }
                else
                    return false;
            }

            if (onRight)
            {
                if (field[moveTo] == ' ' && moveTo - moveFrom == 14 && field[moveTo - 7] == 'o')
                {
                    field[moveTo - 7] = ' ';
                    return true;
                }
                else
                    return false;
            }

            else
            {
                if (field[moveTo] == ' ' && moveTo - moveFrom == 14 && field[moveTo - 7] == 'o')
                {
                    field[moveTo - 7] = ' ';
                    return true;
                }
                else if (field[moveTo] == ' ' && moveTo - moveFrom == 18 && field[moveTo - 9] == 'o')
                {
                    field[moveTo - 9] = ' ';
                    return true;
                }
            }
        }

        else if (state == 2)
        {
            if (onLeft)
            {
                if (field[moveFrom] == 'o' && field[moveTo] == ' ' && moveFrom - moveTo == 7)
                    return true;
                else
                    return false;
            }

            if (onRight)
            {
                if (field[moveFrom] == 'o' && field[moveTo] == ' ' && moveFrom - moveTo == 9)
                    return true;
                else
                    return false;
            }

            else
            {
                if (field[moveFrom] == 'o' && field[moveTo] == ' ' && (moveFrom - moveTo == 7 || moveFrom - moveTo == 9))
                    return true;
            }
        }

        else if (state == 3)
        {
            if (onLeft)
            {
                if (field[moveTo] == ' ' && moveFrom - moveTo == 14 && field[moveTo + 7] == 'x')
                {
                    field[moveTo + 7] = ' ';
                    return true;
                }
                else
                    return false;
            }

            if (onRight)
            {
                if (field[moveTo] == ' ' && moveFrom - moveTo == 18 && field[moveTo + 9] == 'x')
                {
                    field[moveTo + 9] = ' ';
                    return true;
                }
                else
                    return false;
            }

            else
            {
                if (field[moveTo] == ' ' && moveFrom - moveTo == 14 && field[moveTo + 7] == 'x')
                {
                    field[moveTo + 7] = ' ';
                    return true;
                }
                else if (field[moveTo] == ' ' && moveFrom - moveTo == 18 && field[moveTo + 9] == 'x')
                {
                    field[moveTo + 9] = ' ';
                    return true;
                }
            }
        }
        return false;
    }

    else
        return false;
}

void Board::makeMove(bool xplays, int moveFrom, int moveTo)
{
    onSiteLeft = false;
    onSiteRight = false;
    onSiteRightTake = false;
    onSiteLeftTake = false;
    if (moveFrom % 8 == 0)
    {
        onSiteLeft = true;
    }
    else if (moveFrom % 8 == 7)
    {
        onSiteRight = true;
    }
    else if (moveFrom % 8 == 6)
    {
        onSiteRightTake = true;
    }
    else if (moveFrom % 8 == 1)
    {
        onSiteLeftTake = true;
    }

    if (xplays)
    {
        if (checkIfLegal(0, moveFrom, moveTo, onSiteLeft, onSiteRight))
        {
            field[moveFrom] = ' ';
            field[moveTo] = 'x';
        }
        else if (checkIfLegal(1, moveFrom, moveTo, onSiteLeftTake, onSiteRightTake))
        {
            Opawns -= 1;
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
        if (checkIfLegal(2, moveFrom, moveTo, onSiteLeft, onSiteRight))
        {
            field[moveFrom] = ' ';
            field[moveTo] = 'o';
        }
        else if (checkIfLegal(3, moveFrom, moveTo, onSiteLeftTake, onSiteRightTake))
        {
            Xpawns -= 1;
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

bool Board::checkForWin(bool xplays)
{
    if (xplays)
    {
        if (Opawns < 1)
            return true;
        else
            return false;
    }
    else
    {
        if (Xpawns < 1)
            return true;
        else
            return false;
    }
}

int main()
{
    bool continuegame = true;
    while (continuegame)
    {
        Board b;
        Pawn pawns[64];
        Pawn x1{false, 0}, x2{false, 2}, x3{false, 4}, x4{false, 6}, x5{false, 9}, x6{false, 11}, x7{false, 13}, x8{false, 15};
        Pawn o1{false, 48}, o2{false, 50}, o3{false, 52}, o4{false, 54}, o5{false, 57}, o6{false, 59}, o7{false, 61}, o8{false, 63};
        pawns[0] = x1;
        pawns[2] = x2;
        pawns[4] = x3;
        pawns[6] = x4;
        pawns[9] = x5;
        pawns[11] = x6;
        pawns[13] = x7;
        pawns[15] = x8;
        pawns[48] = o1;
        pawns[50] = o2;
        pawns[52] = o3;
        pawns[54] = o4;
        pawns[57] = o5;
        pawns[59] = o6;
        pawns[61] = o7;
        pawns[63] = o8;
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

            if (b.checkForWin(true))
            {
                cout << "X WINS!!!\n";
                continuegame = false;
            }
            if (continuegame)
            {
                b.drawBoard();
                cout << '\n';
                cout << "Now O plays\n";
                cin >> moveFrom >> moveTo;
                cout << "\n";
                b.makeMove(false, moveFrom, moveTo);
                if (b.checkForWin(false))
                {
                    cout << "O WINS!!!\n";
                    continuegame = 0;
                }
            }
        }
        cout << "Want to play again?[yes=1/no=0]\n";
        cin >> continuegame;
    }
    return 0;
}