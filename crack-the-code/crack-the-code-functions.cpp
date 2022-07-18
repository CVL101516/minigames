// file for function definitions

#include <iostream>
#include <vector>

void greet()
{
    std::cout << "\n==============\n";
    std::cout << "Crack The Code\n";
    std::cout << "==============\n";
    std::cout << "Instructions: Unlock the vault of riches by guessing the codeword.\n\n";
}

void end_game(std::string answer, std::string codeword)
{

    if (answer == codeword)
    {

        std::cout << "Congratulations on unlocking the vault!\n\n";
    }
    else
    {

        std::cout << "Uh oh! The alarm triggered. Run!!!\n\n";
    }
}

void display_status(std::vector<char> incorrect, std::string answer)
{
    std::cout << "Incorrect Guesses:";

    for (int i = 0; i < incorrect.size(); i++)
    {
        std::cout << incorrect[i] << ' ';
    }

    std::cout << "\nCodeword:";

    for (int i = 0; i < answer.length(); i++)
    {
        std::cout << answer[i] << ' ';
    }
}