
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// Function to display the calculator menu
void displayMenu() {
    cout << "\n================================\n";
    cout << "       SMART CALCULATOR\n";
    cout << "================================\n";
    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";
    cout << "5. Modulus (%)\n";
    cout << "6. Clear Screen\n";
    cout << "7. Exit\n";
    cout << "================================\n";
}

// Function to get valid menu choice
int getChoice() {
    int choice;

    while (true) {
        cout << "Enter your choice: ";

        if (cin >> choice && choice >= 1 && choice <= 7) {
            return choice;
        }

        cout << "Invalid choice! Enter a number from 1 to 7.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Function to get a valid number
double getNumber(string message) {
    double number;

    while (true) {
        cout << message;

        if (cin >> number) {
            return number;
        }

        cout << "Invalid input! Please enter a valid number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {

    int choice;
    double num1, num2, result;

    cout << fixed << setprecision(2);

    cout << "\nWelcome to Smart Calculator!\n";

    while (true) {

        displayMenu();
        choice = getChoice();

        if (choice == 7) {
            cout << "\nThank you for using Smart Calculator!\n";
            break;
        }

        if (choice == 6) {
            cout << "\nCalculator cleared!\n";
            continue;
        }

        num1 = getNumber("Enter first number: ");
        num2 = getNumber("Enter second number: ");

        switch (choice) {

            case 1:
                result = num1 + num2;
                cout << "\nResult: " << num1 << " + "
                     << num2 << " = " << result << endl;
                break;

            case 2:
                result = num1 - num2;
                cout << "\nResult: " << num1 << " - "
                     << num2 << " = " << result << endl;
                break;

            case 3:
                result = num1 * num2;
                cout << "\nResult: " << num1 << " * "
                     << num2 << " = " << result << endl;
                break;

            case 4:
                if (num2 == 0) {
                    cout << "\nError: Division by zero is not allowed!\n";
                }
                else {
                    result = num1 / num2;
                    cout << "\nResult: " << num1 << " / "
                         << num2 << " = " << result << endl;
                }
                break;

            case 5:
                if (num2 == 0) {
                    cout << "\nError: Modulus by zero is not allowed!\n";
                }
                else if (num1 != static_cast<long long>(num1) ||
                         num2 != static_cast<long long>(num2)) {
                    cout << "\nError: Modulus requires whole numbers!\n";
                }
                else {
                    result = static_cast<long long>(num1) %
                             static_cast<long long>(num2);
                    cout << "\nResult: " << num1 << " % "
                         << num2 << " = " << result << endl;
                }
                break;
        }
    }

    return 0;
}
