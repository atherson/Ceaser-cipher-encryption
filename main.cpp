#include <iostream>
#include <string>

using namespace std;

string encrypt(const string& text, int key) {
    string result;
    for (char c : text) {
        result += char((unsigned char)(c + key) % 256);
    }
    return result;
}


string decrypt(const string& text, int key) {
    string result;
    for (char c : text) {

        result += char((unsigned char)(c - key + 256) % 256);
    }
    return result;
}

int main() {
    string message;
    int key = 0;
    int choice = 0;

    cout << "== Extended Caesar Cipher ==" << endl;
    cout << "1. Encrypt Message" << endl;
    cout << "2. Decrypt Message" << endl;
    cout << "Enter choice [1/2]: ";
    cin >> choice;

    if (choice != 1 && choice != 2) {
        cout << "Invalid choice." << endl;
        return 1;
    }

    cout << "Enter shift key (1-255): ";
    cin >> key;

    cin.ignore(); 

    cout << "Enter your sentence: ";
    getline(cin, message);

    if (choice == 1) {
        cout << "Cipher Text: " << encrypt(message, key) << endl;
    } else {
        cout << "Decrypted: " << decrypt(message, key) << endl;
    }

    return 0;
}
