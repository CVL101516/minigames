// main program file

#include <iostream>
#include <vector>
#include "crack-the-code-functions.hpp"
#include "crack-the-code-functions.cpp"

int main()
{

    greet();

    std::string codeword = "thumbscrew";
    std::string answer = "__________";

    int wrong_guess = 0;

    std::vector<char> incorrect;

    bool guess = false;

    char letter = ' ';

    while (answer != codeword && wrong_guess < 7)
    {

        display_status(incorrect, answer);

        std::cout << "\nPlease enter your guess: ";
        std::cin >> letter;

        for (int i = 0; i < codeword.length(); i++)
        {

            if (letter == codeword[i])
            {

                answer[i] = letter;
                guess = true;
            }
        }

        if (guess == true)
        {
            std::cout << "Correct!\n\n";
        }
        else
        {
            std::cout << "Incorrect!\n\n";
            incorrect.push_back(letter);
            wrong_guess++;
        }

        guess = false;
    }

    end_game(answer, codeword);
}
