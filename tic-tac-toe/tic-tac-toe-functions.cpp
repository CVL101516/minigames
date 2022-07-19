// file for function definitions

#include <iostream>
#include <vector>

char board_space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
char token = 'x';
string p1 = "";
string p2 = "";
bool tie = false;

void greet()
{

    std::cout << "\nTic...Tac...Toe...Gimme an X, Gimme an O, Gimme a Three in a Row.\n\n";

    cout << "Enter the name of Player 1: ";
    cin >> p1;
    cout << "Enter the name of Player 2: ";
    cin >> p2;
    cout << "\n";
}

void game_board()
{

    cout << "Below is the game board. Note how each square is numbered. You will need to first input either X or O depending on which player you are, followed by the number of the square you would like to put your letter in.\n\n";

    cout << "           |           |      \n";
    cout << "           |           |      \n";
    cout << "     " << board_space[0][0] << "     |     " << board_space[0][1] << "     |     " << board_space[0][2] << "\n";
    cout << "           |           |      \n";
    cout << "___________|___________|___________\n";
    cout << "           |           |      \n";
    cout << "           |           |      \n";
    cout << "     " << board_space[1][0] << "     |     " << board_space[1][1] << "     |     " << board_space[1][2] << "\n";
    cout << "           |           |      \n";
    cout << "___________|___________|___________\n";
    cout << "           |           |      \n";
    cout << "           |           |      \n";
    cout << "     " << board_space[2][0] << "     |     " << board_space[2][1] << "     |     " << board_space[2][2] << "\n";
    cout << "           |           |      \n";
    cout << "           |           |      \n";
}

void gameplay()
{

    int digit;

    if (token == 'x')
    {

        cout << p1 << " please enter the number of the square you would like to draw in: ";
        cin >> digit;
    }

    if (token == 'o')
    {

        cout << p2 << " please enter the number of the square you would like to draw in: ";
        cin >> digit;
    }

    if (digit == 1)
    {

        row = 0;
        column = 0;
    }
    else if (digit == 2)
    {

        row = 0;
        column = 1;
    }
    else if (digit == 3)
    {

        row = 0;
        column = 2;
    }
    else if (digit == 4)
    {

        row = 1;
        column = 0;
    }
    else if (digit == 5)
    {

        row = 1;
        column = 1;
    }
    else if (digit == 6)
    {

        row = 1;
        column = 2;
    }
    else if (digit == 7)
    {

        row = 2;
        column = 0;
    }
    else if (digit == 8)
    {

        row = 2;
        column = 1;
    }
    else if (digit == 9)
    {

        row = 2;
        column = 2;
    }
    else if (digit < 1 || digit > 9)
    {

        cout << "Invalid Square!" << endl;
    }

    if (token == 'x' && board_space[row][column] != 'x' && board_space[row][column] != 'o')
    {

        board_space[row][column] = 'x';
        token = 'o';
    }
    else if (token == 'o' && board_space[row][column] != 'x' && board_space[row][column] != 'o')
    {

        board_space[row][column] = 'o';
        token = 'x';
    }
    else
    {

        cout << "There is no empty space!" << endl;
        gameplay();
    }
    game_board();
}

bool is_Winner()
{

    for (int i = 0; i < 3; i++)
    {

        if (board_space[i][0] == board_space[i][1] && board_space[i][0] == board_space[i][2] || board_space[0][i] == board_space[1][i] && board_space[0][i] == board_space[2][i])
        {
            return true;
        }
        if (board_space[0][0] == board_space[1][1] && board_space[1][1] == board_space[2][2] || board_space[0][2] == board_space[1][1] && board_space[1][1] == board_space[2][0])
        {
            return true;
        }
    }

    for (int i = 1; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board_space[i][j] != 'x' && board_space[i][j] != 'o')
            {
                return false;
            }
        }
    }
    tie = true;
    return false;
}