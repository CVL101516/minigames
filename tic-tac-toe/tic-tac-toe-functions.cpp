// file for function definitions

#include <iostream>
char board_space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}; // Created a 3x3 array. Char because the input is 'x' or 'o'
int row, column;
char token = 'x'; // used to change the # of the space to a letter.
string p1 = "";   // name of player
string p2 = "";
bool is_tie = false;
int choice;

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
    cout << "Below is the game board. Note how each square is numbered. You will be asked to input the number of the square you would like to draw in.\n\n";

    cout << "           |           |      \n";
    cout << "           |           |      \n";
    cout << "     " << board_space[0][0] << "     |     " << board_space[0][1] << "     |     " << board_space[0][2] << "\n"; // Giving the array its spot. Will show the 1, 2, 3 etc etc spaces.
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
    if (token == 'x')
    {
        cout << p1 << " please enter the number of the square you would like to draw in: ";
    }
   else if (token == 'o')
    {
        cout << p2 << " please enter the number of the square you would like to draw in: ";
    }

     cin >> choice;

     switch(choice) {
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout << "Invalid Square!" << endl;
     }

    if (token == 'x' && board_space[row][column] != 'x' && board_space[row][column] != 'o') // This is what changes the number to the letter x or o and then switches turns.
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
        cout << "This space is already taken!" << endl;
        gameplay();
    }
    game_board(); // In case a repeat number is chosen, this will reshow the current state of the game board.
}

bool is_Winner()
{
    for (int i = 0; i < 3; i++) // Checks all positions. Rows. Columns, Diags. For a winner. It will then exit the while loop in ttt.cpp
    {

        if (board_space[i][0] == board_space[i][1] && board_space[i][0] == board_space[i][2] || board_space[0][i] == board_space[1][i] && board_space[0][i] == board_space[2][i])
        {
            return false;
        }
        if (board_space[0][0] == board_space[1][1] && board_space[1][1] == board_space[2][2] || board_space[0][2] == board_space[1][1] && board_space[1][1] == board_space[2][0])
        {
            return false;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board_space[i][j] != 'x' || board_space[i][j] != 'o') // Checks all positions for an X or an O. If there is one filled. Returns false, so game continues (while loop in ttt.cpp continues)
            {
                return true;
            }
            else //if (board_space[i][j] == 'x' || board_space[i][j] == 'o') // When/if all spaces are filled, this should exit the while loop. setting is_tie to true. Which would move to the if else/if which sees the is_true==true and runs that.
            {
                is_tie = true;
                return false;
            }
        }
    }
    //  is_tie = true;
     return false;
}