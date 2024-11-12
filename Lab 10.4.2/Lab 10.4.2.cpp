#include <iostream>
#include <string>
using namespace std;

bool isNumeric(string s) {
    for (char c : s) {
        if (c < '0' || c > '9') {
            return false;
        }
    }
    return true;
}

bool isCorrectLength(string s) {
    return s.length() == 16;
}

bool isCardValid(int digits[], int size) {
    int sum1 = 0, sum2 = 0;

    for (int i = size - 1; i >= 0; i -= 2) {
        sum1 += digits[i];
    }

    for (int i = size - 2; i >= 0; i -= 2) {
        int doubled = digits[i] * 2;
        sum2 += (doubled / 10) + (doubled % 10);
    }

    return (sum1 + sum2) % 10 == 0;
}

int main() {
    string input;
    while (true) {
        cout << "Enter a 16-digit credit card # or Q to quit: ";
        cin >> input;

        if (input == "Q" || input == "q") {
            break;
        }

        if (!isNumeric(input)) {
            cout << "Error - Card number number must contain only digits." << endl;
            continue;
        }

        if (!isCorrectLength(input)) {
            cout << "Error - Card number number must contain exactly 16 digits." << endl;
            continue;
        }

        int digits[16];
        for (int i = 0; i < 16; i++) {
            digits[i] = input[i] - '0';
        }

        if (isCardValid(digits, 16)) {
            cout << "Card  is valid." << endl;
        }
        else {
            cout << "Card  is invalid." << endl;
        }
    }
    return 0;
}