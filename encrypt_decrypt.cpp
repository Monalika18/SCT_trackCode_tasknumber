#include <iostream>
#include <string>
#include <cctype> // For isalpha, isupper, tolower
using namespace std;

// Encrypt text using Caesar Cipher
string caesarEncrypt(const string& text, int shift) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += static_cast<char>((c - base + shift) % 26 + base);
        } else {
            result += c; // Keep non-alphabetic characters unchanged
        }
    }
    return result;
}

// Decrypt text by reversing the Caesar Cipher
string caesarDecrypt(const string& text, int shift) {
    return caesarEncrypt(text, 26 - (shift % 26));
}

// Validate shift value
bool getValidShift(int& shift) {
    cout << "Enter shift value (1-25): ";
    cin >> shift;
    if (cin.fail() || shift < 1 || shift > 25) {
        cin.clear(); // Clear error state
        cin.ignore(10000, '\n'); // Clear input buffer
        cout << "Invalid shift! Must be a number between 1 and 25." << endl;
        return false;
    }
    return true;
}

int main() {
    string message;
    int shift;
    char option;

    cout << "===== Caesar Cipher Program =====" << endl;
    cout << "Built for VSCode and MinGW" << endl;
    while (true) {
        cout << "\nChoose an option: (e)ncrypt, (d)ecrypt, or (q)uit: ";
        cin >> option;
        cin.ignore(); // Clear newline after option input

        option = tolower(option);
        if (option == 'q') {
            cout << "Exiting program." << endl;
            break;
        }
        if (option != 'e' && option != 'd') {
            cout << "Invalid option! Please enter 'e', 'd', or 'q'." << endl;
            continue;
        }

        cout << "Enter your message: ";
        getline(cin, message);
        if (message.empty()) {
            cout << "Message cannot be empty!" << endl;
            continue;
        }

        if (!getValidShift(shift)) {
            continue;
        }

        if (option == 'e') {
            string encrypted = caesarEncrypt(message, shift);
            cout << "Encrypted message: " << encrypted << endl;
        } else {
            string decrypted = caesarDecrypt(message, shift);
            cout << "Decrypted message: " << decrypted << endl;
        }
    }

    return 0;
}