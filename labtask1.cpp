#include <iostream>
#include <cctype>
using namespace std;

bool isNumericConstant(string s) {
    if (s.empty()) return false;

    for (char c : s) {
        if (!isdigit(c))
            return false;
    }
    return true;
}
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' ||
            c == '/' || c == '%' || c == '=');
}
bool isComment(string s) {
    if (s.size() >= 2) {
        if (s.substr(0, 2) == "//")
            return true;
        if (s.substr(0, 2) == "/" && s.substr(s.size() - 2) == "/")
            return true;
    }
    return false;
}
bool isIdentifier(string s) {
    if (s.empty())

    return false;

    if (!(isalpha(s[0]) || s[0] == '_'))
        return false;

    for (int i = 1; i < s.length(); i++) {
        if (!(isalnum(s[i]) || s[i] == '_'))
            return false;
    }
    return true;
}
int main() {
    string input;
    char op;


    cout << "Enter a value to check numeric constant: ";
    cin >> input;
    cout << (isNumericConstant(input) ? "Numeric Constant\n" : "Not Numeric\n");


    cout << "Enter a character to check operator: ";
    cin >> op;
    cout << (isOperator(op) ? "Operator\n" : "Not Operator\n");


    cout << "Enter a comment line: ";
    cin.ignore();
    getline(cin, input);
    cout << (isComment(input) ? "Comment Line\n" : "Not a Comment\n");


    cout << "Enter an identifier: ";
    cin >> input;
    cout << (isIdentifier(input) ? "Valid Identifier\n" : "Invalid Identifier\n");

    return 0;
}
