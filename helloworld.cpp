#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string hello = "Hello World";
    char letter;
    cout << "Guess a letter" << endl;
    cin >> letter;
    for (int i = 0; i < hello.size(); i++) {
        if (hello[i] == letter) {
            cout << "Letter found!" << endl;
        }
        else {
            cout << "Letter not found!" << endl;
        }
    }
}