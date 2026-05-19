#include <iostream>
#include <string>

bool isValid(const std::string& s) {
    int n = s.length();
    if (n < 2 || s[0] != 'a') return false;

    int i = 1;


    if (i < n && s[i] == 'a') {
        while (i < n && s[i] == 'a') i++;
        if (i < n && s[i] == 'b') {
            i++;
            while (i < n && s[i] == 'a') i++;
            return i == n;
        }
    }

    else {
        while (i < n && s[i] == 'b') i++;
        while (i < n && s[i] == 'a') i++;
        return i == n;
    }

    return false;
}

int main() {
    std::string test;
    std::cout << "Enter string: ";
    std::cin >> test;

    if (isValid(test)) std::cout << "Accept" << std::endl;
    else std::cout << "Reject" << std::endl;

    return 0;
}
