#include <iostream>
using namespace std;

class Board
{
public:
    void drawBoard();
    void restart();
    void setupBoard();
    void makeMove(bool, int, int);
    bool checkIfLegal(int, int, int, bool, bool);
    int checkForWin();

private:
    char field[64];
    int Xpawns;
    int Opawns;
    bool onSiteLeft;
    bool onSiteRight;
    bool onSiteLeftTake;
    bool onSiteRightTake;
};

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

bool Board::checkIfLegal(int state, int moveFrom, int moveTo, bool onLeft, bool onRight)
{
    if (state == 0)
    {
        if (onLeft)
        {
            if (field[moveFrom] == 'x' && field[moveTo] == ' ' && (moveTo - moveFrom == 9))
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

int Board::checkForWin(){
    if(Xpawns==0){
        return 1;
    }
    else if(Opawns==0){
        return 2;
    }
    else return 0;
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
        switch (b.checkForWin())
        {
        case 1:
            cout<<"X WINS!";
            continuegame=0;
            break;
        case 2:
            cout<<"O WINS!";
            continuegame=0;
            break;
        default:
            continue;;
        }
    }
    return 0;
}