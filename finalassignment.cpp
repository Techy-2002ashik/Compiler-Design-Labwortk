#include <iostream>
#include <string>

using namespace std;


bool isAccepted(const string& str) {
    for (char ch : str) {
        if (ch != 'a' && ch != 'b') {
            return false;
        }
    }
    return true;
}

int main() {
    string input;
    cout << "DFA for (a+b)*" << endl;
    cout << "Enter strings (or 'exit' to quit):" << endl;

    while (true) {
        cout << "\nInput string: ";
        getline(cin, input);

        if (input == "exit") break;

        if (isAccepted(input)) {
            cout << "Result: ACCEPTED " << endl;
        } else {
            cout << "Result: REJECTED (Only 'a' and 'b' allowed)" << endl;
        }
    }
    return 0;
}
