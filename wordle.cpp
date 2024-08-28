#include <set>
#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <array>

using namespace std;

void parseFileInput(vector<string>& contents);
string randomWord(const vector<string>& dictionary);

int main(void) {
    vector<string> dictionary;
    parseFileInput(dictionary);

    string correctWord = randomWord(dictionary);

    const string GREEN = "\033[1;32m";
    const string YELLOW = "\033[1;33m";
    const string GREY = "\033[0m";

    cout << "WELCOME TO WORDLE!" << endl;

    int num_tries = 5;
    while (num_tries <= 5) {
        string cheat = correctWord;
        cout << "Cheat word: " << cheat << endl;
        cout << "Guess the five-letter word: " << endl;
        string word;
        cin >> word;
        cout << "You have " << num_tries << " tries remaining: " << endl;
        num_tries--;

    set<char> correctLetters;

    for (int i = 0; i < correctWord.length(); i++) {
        if (i < word.length() && word[i] == correctWord[i]) {
            cout << GREEN << word[i] << GREY << endl;
            correctLetters.insert(word[i]);
        }
        else if (correctWord.find(word[i]) != string::npos && correctLetters.find(word[i]) == correctLetters.end()) {
            cout << YELLOW << word[i] << GREY << endl;
            correctLetters.insert(word[i]);
        }
        else {
            cout << word[i] << endl;
        }
    }

        if (word == correctWord) {
            cout << "You guessed the right word!" << endl;
            break;
        }
            if (num_tries == -1) {
                cout << "You ran out of tries! The correct word was " << correctWord << "!" << endl;
                break;
        }
    }
    cout << endl;
    return 0;
}

void parseFileInput(vector<string>& contents) {
    ifstream filename("Projects/Wordle/dictionary.txt");

    if (filename.fail()) {
        cout << "File failed to open." << endl;
        return;
    }

    string line;
    while (getline(filename, line)) {
        contents.push_back(line);
    }

    filename.close();
}

string randomWord(const vector<string>& dictionary) {
    srand(time(0));
    int randomIndex = rand() % dictionary.size();
    return dictionary[randomIndex];
}
