#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Calculator {
public:
    float add(float a, float b) {
        return a + b;
    }
    float subtract(float a, float b) {
        return a - b;
    }
    float multiply(float a, float b) {
        if (a == 0 || b == 0) {
            return 0;
        }
        return a * b;
    }
    float divide(float a, float b) {
        if (b != 0) {
            return a / b;
        }
        else {
            cout << "Encountered Division by Zero!" << endl;
            return 0;
        }
    }
};

void printHistory(const vector<string>& history) {
    cout << "Calculation History:" << endl;
    for (const string& record : history) {
        cout << record << endl;
    }
}

int main() {
    Calculator c;
    float num1, num2;
    char op, choice, showHistoryChoice;
    vector<string> history;

    do {
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;

        cout << "Enter operator (+, -, *, /): ";
        cin >> op;

        string resultStr;
        switch (op) {
        case '+':
            resultStr = to_string(num1) + " + " + to_string(num2) + " = " + to_string(c.add(num1, num2));
            cout << resultStr << endl;
            history.push_back(resultStr);
            break;
        case '-':
            resultStr = to_string(num1) + " - " + to_string(num2) + " = " + to_string(c.subtract(num1, num2));
            cout << resultStr << endl;
            history.push_back(resultStr);
            break;
        case '*':
            resultStr = to_string(num1) + " * " + to_string(num2) + " = " + to_string(c.multiply(num1, num2));
            cout << resultStr << endl;
            history.push_back(resultStr);
            break;
        case '/':
            if (num2 != 0) {
                resultStr = to_string(num1) + " / " + to_string(num2) + " = " + to_string(c.divide(num1, num2));
                cout << resultStr << endl;
                history.push_back(resultStr);
            }
            else {
                cout << "Encountered Division by Zero!" << endl;
                history.push_back(to_string(num1) + " / " + to_string(num2) + " = Division by Zero");
            }
            break;
        default:
            cout << "Invalid operator" << endl;
            break;
        }

        cout << "Do you want to see the calculation history? (y/n): ";
        cin >> showHistoryChoice;
        if (showHistoryChoice == 'y') {
            printHistory(history);
        }

        cout << "Press q to quit or any other key to continue! ";
        cin >> choice;
    } while (choice != 'q');

    return 0;
}
