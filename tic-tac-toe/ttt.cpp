// main program file

#include <iostream>
using namespace std;
#include "tic-tac-toe-functions.hpp"
#include "tic-tac-toe-functions.cpp"

int main()
{

    greet();

    while (is_Winner())
    {
        game_board();
        gameplay();
        is_Winner();
    }
    if (token == 'x' && is_tie == false)
    {
        cout << p2 << " is the winner!!!" << endl;
    }
    else if (token == 'o' && is_tie == false)
    {
        cout << p1 << " is the winner!!!" << endl;
    }
    else
    {
        game_board();
        cout << "This game is a draw!";
    }
}
