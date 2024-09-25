#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Initialize random seed
    int random_number = rand() % 100 + 1;
    int user_guess = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a random number between 1 and 100." << endl;
    cout << "Try to guess it!" << endl;

    while (user_guess != random_number) {
        cout << "Enter your guess: ";
        cin >> user_guess;

        if (user_guess > random_number) {
            cout << "Too high! Try again." << endl;
        } else if (user_guess < random_number) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number: " << random_number << endl;
        }
    }

    return 0;
}
