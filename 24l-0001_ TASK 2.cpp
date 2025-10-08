#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
class hangman {
private:
    string words[100];
    int word_c;
    string play_c;
    string display_c;
    int mistakes;
    int max_m;
public:
    hangman() {
        srand(time(0));
        word_c = 0;
        mistakes = 0;
        max_m = 7;
        loadWords();
        selectWord();
        createDisplay();
    }
    void loadWords() {
        ifstream file("words.txt");
        string word;
        while (getline(file, word) && word_c < 100) {
            words[word_c] = word;
            word_c++;
        }
        file.close();
    }
    void selectWord() {
        play_c = words[rand() % word_c];
    }
    void createDisplay() {
        display_c = "";
        for (int i = 0; i < play_c.length(); i++) {
            display_c += '_';
        }
    }
    void playGame() {
        while (mistakes < max_m) {
            displayStatus();
            char guess;
            cin >> guess;

            bool found = false;
            for (int i = 0; i < play_c.length(); i++) {
                if (play_c[i] == guess) {
                    display_c[i] = guess;
                    found = true;
                }
            }

            if (!found) {
                mistakes++;
                cout << "wrong! ";
            }

            if (display_c == play_c) {
                cout << "u won! The word was: " << play_c << endl;
                return;
            }
        }

        cout << "u lost! the word was: " << play_c << endl;
    }

    void displayStatus() {
        cout << "word: " << display_c << endl;
        cout << "Mistakes remaining: " << max_m - mistakes << endl;
        cout << "Guess a letter: ";
    }
};
int main() {
    hangman game;
    game.playGame();
    return 0;
}