
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <cctype>
using namespace std;

// Get a valid number within a given range
int getValidNumber(string message, int min, int max) {
    int number;

    while (true) {
        cout << message;

        if (cin >> number && number >= min && number <= max) {
            return number;
        }

        cout << "Invalid input! Enter a number between "
             << min << " and " << max << ".\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Display game title
void displayTitle() {
    cout << "\n";
    cout << "====================================\n";
    cout << "       NUMBER GUESSING GAME\n";
    cout << "====================================\n";
    cout << "      Test Your Guessing Skills!\n";
    cout << "====================================\n\n";
}

// Play one round
int playGame(int& bestScore) {

    cout << "\nChoose Difficulty:\n";
    cout << "1. Easy   (1 - 50)\n";
    cout << "2. Medium (1 - 100)\n";
    cout << "3. Hard   (1 - 200)\n\n";

    int difficulty = getValidNumber("Enter choice: ", 1, 3);

    int maxNumber;

    if (difficulty == 1)
        maxNumber = 50;
    else if (difficulty == 2)
        maxNumber = 100;
    else
        maxNumber = 200;

    int secretNumber = (rand() % maxNumber) + 1;

    int guess;
    int attempts = 0;

    cout << "\nI have selected a number between 1 and "
         << maxNumber << ".\n";

    cout << "Try to guess the number!\n\n";

    while (true) {

        guess = getValidNumber("Enter your guess: ", 1, maxNumber);
        attempts++;

        if (guess == secretNumber) {
            cout << "\nCongratulations! You guessed correctly!\n";
            break;
        }

        if (guess < secretNumber) {
            cout << "Too LOW! Try a higher number.\n";
        }
        else {
            cout << "Too HIGH! Try a lower number.\n";
        }

        int difference = abs(secretNumber - guess);

        if (difference <= 5)
            cout << "Hint: You are VERY CLOSE!\n";
        else if (difference <= 15)
            cout << "Hint: You are getting closer!\n";
        else
            cout << "Hint: You are FAR from the number!\n";

        cout << "Attempts so far: " << attempts << "\n\n";
    }

    int score = 1000 / attempts;

    cout << "\n---------- GAME RESULTS ----------\n";
    cout << "Secret Number : " << secretNumber << "\n";
    cout << "Total Attempts: " << attempts << "\n";
    cout << "Your Score   : " << score << "\n";

    if (score > bestScore) {
        bestScore = score;
        cout << "New Personal Best!\n";
    }

    cout << "Best Score   : " << bestScore << "\n";
    cout << "----------------------------------\n";

    return score;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int bestScore = 0;
    char playAgain;

    displayTitle();

    do {
        playGame(bestScore);

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

        playAgain = toupper(
            static_cast<unsigned char>(playAgain)
        );

        while (playAgain != 'Y' && playAgain != 'N') {
            cout << "Please enter Y or N: ";
            cin >> playAgain;

            playAgain = toupper(
                static_cast<unsigned char>(playAgain)
            );
        }

    } while (playAgain == 'Y');

    cout << "\n====================================\n";
    cout << "       THANK YOU FOR PLAYING!\n";
    cout << "====================================\n";

    return 0;
}
