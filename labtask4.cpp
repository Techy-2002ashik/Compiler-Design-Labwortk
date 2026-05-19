#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool matchExpr1(string s) {
    return (s == "a" || s == "b");
}


bool matchExpr2(string s) {
    for (char c : s) {
        if (c != 'a' && c != 'b') return false;
    }
    return true;
}


bool matchExpr3(string s) {
    if (s.length() != 3) return false;

    bool firstMatch = (s[0] == 'a');
    bool secondMatch = (s[1] == 'a' || s[1] == 'b');
    bool thirdMatch = (s[2] == 'b');

    return (firstMatch && secondMatch && thirdMatch);
}

void test(string input) {
    cout << "Testing: \"" << input << "\"" << endl;
    cout << "  (a + b)    : " << (matchExpr1(input) ? "ACCEPT" : "REJECT") << endl;
    cout << "  (a + b)* : " << (matchExpr2(input) ? "ACCEPT" : "REJECT") << endl;
    cout << "  a(a + b)b  : " << (matchExpr3(input) ? "ACCEPT" : "REJECT") << endl;
    cout << "-----------------------" << endl;
}

int main() {

    test("a");
    test("ab");
    test("aab");
    test("abb");
    test("aaab");
    test("");

    return 0;
}
