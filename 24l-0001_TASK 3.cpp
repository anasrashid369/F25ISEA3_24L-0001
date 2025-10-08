#include <iostream>
using namespace std;
class game {
private:
    char grid[3][3];
    char player;
public:
    game() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                grid[i][j] = ' ';
            }
        }
        player = 'x';
    }
    void displaygrid() {
        cout << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << grid[i][j];
                if (j < 2) cout << "|";
            }
            cout << endl;
            if (i < 2) cout << "-----" << endl;
        }
        cout << endl;
    }
    bool move(int row, int col) {
        if (row < 0 || row > 2 || col < 0 || col > 2 || grid[row][col] != ' ') {
            return false;
        }
        grid[row][col] = player;
        return true;
    }

    bool win() {
        for (int i = 0; i < 3; i++) {
            if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player) {
                return true;
            }
            if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player) {
                return true;
            }
        }
        if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) {
            return true;
        }
        if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player) {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool draw() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void switchPlayer() {
        if (player == 'x') {
            player = 'o';
        }
        else {
            player = 'x';
        }
    }

    void playGame() {
        cout << "Tic-Tac-Toe Game!" << endl;
        cout << "Player 1: x, Player 2: o ";
        while (true) {
            displaygrid();
            cout << "Player " ;
            if (player == 'x') {
                cout << "1 (x)";
            }
            else {
                cout << "2 (o)";
            }
            cout << "row and column (0-2): ";
            int row, col;
            cin >> row >> col;
            if (!move(row, col)) {
                cout << "Invalid move " << endl;
                continue;
            }
            if (win()) {
                displaygrid();
                if (player == 'x') {
                    cout << "player 1 wins" << endl;
                }
                else {
                    cout << "player 2 wins" << endl;
                }
                break;
            }
            if (draw()) {
                displaygrid();
                cout << "game drawn" <<endl;
                break;
            }
            switchPlayer();
        }
    }
};
int main() {
    game game;
    game.playGame();
    return 0;
}