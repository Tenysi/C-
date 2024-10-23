// Quiz game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string> 
#include <cstdlib>
#include <ctime>

int randomNum(int size)
{
    return std::rand() % size;
}

void correct(int& count, std::string q[2][20], int correctArr[], int& size, int n, int& good)
{
    for (int i = n; i < size - 1; ++i)
    {
        q[0][i] = q[0][i + 1];
        q[1][i] = q[1][i + 1];
        correctArr[i] = correctArr[i + 1];
    }
    std::cout << "\nCorrect\n\n";
    size--;
    count++;
    good++; 
}

void incorrect(int& count, std::string q[2][20], int correctArr[], int& size, int n, int& good)
{
    for (int i = n; i < size - 1; ++i)
    {
        q[0][i] = q[0][i + 1];
        q[1][i] = q[1][i + 1];
        correctArr[i] = correctArr[i + 1];
    }
    std::cout << "\nIncorrect\n\n";
    size--;
    count++;  
}

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int count = 0; //number of questions
    std::string q[2][20] = {
        {
            "Spaghetti is a type of what?", "Duck is a type of what?",
            "Sushi originates from which country?", "What fruit is known for being the main ingredient in guacamole?",
            "What type of food is Brie?", "Which of these is a citrus fruit?",
            "What is the main ingredient in hummus?", "What type of dish is Paella?",
            "Which nut is used to make marzipan?", "Which vegetable is used to make sauerkraut?",
            "What is the primary ingredient in miso soup?", "What type of food is a baguette?",
            "What kind of fish is commonly used in fish and chips?", "Which grain is used to make couscous?",
            "Which of these is a root vegetable?", "What is the main ingredient in pesto sauce?",
            "Which fruit has the highest Vitamin C content?", "What kind of food is tofu made from?",
            "Which herb is typically used in a Caprese salad?", "Which country is famous for its feta cheese?"
        },
        {
            "Pasta, Bread, Vegetable, Poultry", "Carbs, Protein, Fat, Sugar",
            "Japan, China, Thailand, Korea", "Apple, Banana, Avocado, Tomato",
            "Cheese, Bread, Meat, Fish", "Apple, Lemon, Grape, Pineapple",
            "Chickpeas, Lentils, Beans, Rice", "Soup, Salad, Rice, Pasta",
            "Almonds, Peanuts, Cashews, Walnuts", "Carrots, Cabbage, Kale, Spinach",
            "Tofu, Seaweed, Soybeans, Rice", "Bread, Pastry, Rice, Pasta",
            "Salmon, Cod, Tuna, Haddock", "Rice, Barley, Quinoa, Wheat",
            "Potato, Broccoli, Eggplant, Zucchini", "Basil, Pine nuts, Cheese, Garlic",
            "Orange, Strawberry, Kiwi, Guava", "Soybeans, Wheat, Rice, Beans",
            "Basil, Cilantro, Thyme, Mint", "Greece, France, Italy, Spain"
        }
    };

    int correctArr[20] = { 1, 2, 1, 3, 1, 2, 1, 3, 1, 2, 3, 1, 2, 1, 1, 1, 4, 1, 1, 1 };
    int good = 0; //correct answers
    int size = sizeof(correctArr) / sizeof(correctArr[0]); //size of the questions

    std::cout << "Welcome to the food quiz!\n";
    std::cout << "Press any button to start!\n";
    std::cin.get();

    int answer; //input
    std::cout << "You started!\n\n";

    while (count < 8 && size > 0)
        int n = randomNum(size); //needs to update constantly
        std::cout << q[0][n] << "\n"; 
        std::cout << q[1][n] << "\n";
        std::cin >> answer;

        if (answer == correctArr[n])
        {
            correct(count, q, correctArr, size, n, good); //no need to redeclare arrays or types here
        }
        else
        {
            incorrect(count, q, correctArr, size, n, good); 
        }
    }

    int percent = (static_cast<float>(good) / 8) * 100;
    std::cout << "\nYou got " << percent << "% correct!\nWell done!" << std::endl;
}
