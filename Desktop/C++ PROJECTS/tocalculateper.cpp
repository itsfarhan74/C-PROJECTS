#include <iostream>
#include <string>
#include <vector>

using namespace std;

void calculatePercentage() {
    vector<double> values;
    double total = 0;
    string choice;

    cout << "Enter values (type 'done' to finish): ";
    while (true) {
        cin >> choice;
        if (choice == "done") {
            break;
        }
        double value;
        if (cin >> value) {
            values.push_back(value);
            total += value;
        } else {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    if (values.empty()) {
        cout << "No values entered.\n";
    } else {
        cout << "Enter the value for which you want to calculate the percentage: ";
        double targetValue;
        cin >> targetValue;

        double percentage = (targetValue / total) * 100;
        cout << targetValue << " is " << percentage << "% of " << total << endl;
    }
}

int main() {
    while (true) {
        cout << "1. Calculate percentage\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                calculatePercentage();
                break;
            case 2:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
