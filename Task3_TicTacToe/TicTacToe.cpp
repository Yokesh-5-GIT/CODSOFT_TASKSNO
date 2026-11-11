#include <iostream>
using namespace std;

char board[3][3];

void resetBoard() {
    char c = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = c++;
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool placeMove(int pos, char player) {
    if (pos < 1 || pos > 9) return false;
    int r = (pos - 1) / 3, c = (pos - 1) % 3;
    if (board[r][c] == 'X' || board[r][c] == 'O') return false;
    board[r][c] = player;
    return true;
}

bool checkWin(char p) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p) return true;
        if (board[0][i] == p && board[1][i] == p && board[2][i] == p) return true;
    }
    if (board[0][0] == p && board[1][1] == p && board[2][2] == p) return true;
    if (board[0][2] == p && board[1][1] == p && board[2][0] == p) return true;
    return false;
}

int main() {
    char again;
    do {
        resetBoard();
        char player = 'X';
        int moves = 0;
        bool won = false;

        while (moves < 9 && !won) {
            displayBoard();
            int pos;
            cout << "Player " << player << ", enter position (1-9): ";
            if (!(cin >> pos)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input! Enter a number.\n";
                continue;
            }
            if (!placeMove(pos, player)) {
                cout << "Invalid move! Try again.\n";
                continue;
            }
            moves++;
            if (checkWin(player)) {
                won = true;
                displayBoard();
                cout << "Player " << player << " wins!\n";
            } else {
                player = (player == 'X') ? 'O' : 'X';
            }
        }
        if (!won) {
            displayBoard();
            cout << "It's a draw!\n";
        }
        cout << "Play again? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}