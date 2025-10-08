#include <iostream>
#include <string>
using namespace std;
int main() {
    string word;
    char ch;
    while (true) {
        cout << "Enter a string: ";
        cin >> word;
        bool palindrome = true;
        int n = word.length();
        for (int i = 0; i < n / 2; i++) {
            if (word[i] != word[n - i - 1]) {
                palindrome = false;
                break;
            }
        }
        if (palindrome) {
            cout << "Palindrome" << endl;
        }
        else {
            cout << "Not Palindrome" << endl;
        }
        cout << "Press Esc to quit or any key to continue: ";
        cin >> ch;
        if (ch == 27) {
            break;
        }
    }
    return 0;
}