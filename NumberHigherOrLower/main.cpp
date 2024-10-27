#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void below(int guess, int answer, int guesses)
{
    if(guesses == 5)
    {

    }
    else
    {
        if (guess < answer)
        {
            cout << "Guess higher\n";
        }
        else
        {
            cout << "Guess lower\n";
        }
    }
}

void howClose(int guess, int answer, int guesses, int number)
{
    float percent;

    if (number != 0)
    {
        percent = (static_cast<float>(abs(guess - answer)) / number) * 100;
    }
    else
    {
        percent = 0;
    }

    if (guess == answer)
    {
        cout << "You win!\n";
        exit(0);
    }

    if (percent >= 100)
    {
        percent = 100;
    }

    if (percent >= 0 && percent < 10)
    {
        cout << "Scorching Red Hot LAVA!!!\n";
        below(guess, answer, guesses);
    }
    else if (percent >= 10 && percent < 25)
    {
        cout << "Blazing Hot!!\n";
        below(guess, answer, guesses);
    }
    else if (percent >= 25 && percent < 40)
    {
        cout << "Toasty!\n";
        below(guess, answer, guesses);
    }
    else if (percent >= 40 && percent < 55)
    {
        cout << "It's getting warm!\n";
        below(guess, answer, guesses);
    }
    else if (percent >= 55 && percent < 75)
    {
        cout << "Chilly!\n";
        below(guess, answer, guesses);
    }
    else if (percent >= 75 && percent <= 100)
    {
        cout << "You're Ice Cold!\n";
        below(guess, answer, guesses);
    }
}

int main()
{
    int number;
    cout << "Enter the max range to guess from: \n";
    cin >> number;

    srand(static_cast<unsigned>(time(NULL)));
    int answer = rand() % (number + 1);
    cout << "You have 5 guesses.\n";
    cout << "It was " << answer << endl;

    int guess;
    int guesses = 0;
    while (guesses < 5)
    {
        cout << "Whats your guess?\n";
        cin >> guess;
        howClose(guess, answer, guesses, number);
        guesses++;
    }

    cout << "This is your last guess!\n";
    cin >> guess;
    howClose(guess, answer, guesses, number);
    guesses = 5;
    cout << "It was " << answer << endl;
    cout << "Game over!\n";
}
