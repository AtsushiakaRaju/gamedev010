// Game1 - [Tic-Tac-Toe], its a simple game where one can challange the bot or
// your friend near by

#include <iostream>
#include <random>
#include <string>
using namespace std;

class TicTacToe {
    char board[3][3];
    int moves;
    string player1,player2;
public:
int multi;
    TicTacToe() {
        resetBoard();
    }
    void disboardmoves(){
          cout<<"\t0 0\t|\t0 1\t|\t0 2\t"<<endl;
          cout<<"\t1 0\t|\t1 1\t|\t1 2\t"<<endl;
          cout<<"\t2 0\t|\t2 1\t|\t2 2\t"<<endl;
    }
    void resetBoard() {
        moves = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = '-';
    }

    void displayBoard() {
        cout << "\nCurrent Board:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << "\t" << board[i][j];
            }
            cout << endl;
        }
    }

    bool isValidMove(int x, int y) {
        return x >= 0 && x < 3 && y >= 0 && y < 3 && board[x][y] == '-';
    }

    void player1Move() {
        int x, y;
        while (true) {
            cout << player1<<" Enter your move (row and column): ";
            cin >> x >> y;
            if (isValidMove(x, y)) {
                board[x][y] = 'X';
                moves++;
                break;
            } else {
                cout << "Invalid move! Try again.\n";
            }
        }
    }
    void player2Move() {
        int x, y;
        while (true) {
            cout <<player2<<" Enter your move (row and column): ";
            cin >> x >> y;
            if (isValidMove(x, y)) {
                board[x][y] = 'O';
                moves++;
                break;
            } else {
                cout << "Invalid move! Try again.\n";
            }
        }
    }

    void botMove() {
    // All possible winning lines
    int winPatterns[8][3][2] = {
        {{0,0},{0,1},{0,2}}, {{1,0},{1,1},{1,2}}, {{2,0},{2,1},{2,2}}, // Rows
        {{0,0},{1,0},{2,0}}, {{0,1},{1,1},{2,1}}, {{0,2},{1,2},{2,2}}, // Cols
        {{0,0},{1,1},{2,2}}, {{0,2},{1,1},{2,0}}                        // Diagonals
    };

    auto canWin = [&](char mark)->pair<int,int> {
        // Check if 'mark' can win in next move
        for (auto &pattern : winPatterns) {
            int countMark = 0, countEmpty = 0;
            pair<int,int> emptyCell;
            for (auto &p : pattern) {
                int x = p[0], y = p[1];
                if (board[x][y] == mark) countMark++;
                else if (board[x][y] == '-') { countEmpty++; emptyCell = {x,y}; }
            }
            if (countMark == 2 && countEmpty == 1) return emptyCell;
        }
        return make_pair(-1,-1);
    };

    // 1️⃣ Try to win
    auto move = canWin('O');
    if (move.first != -1) {
        board[move.first][move.second] = 'O';
        moves++;
        cout << "Bot plays to WIN at: " << move.first << ", " << move.second << endl;
        displayBoard();
        return;
    }

    // 2️⃣ Block player
    move = canWin('X');
    if (move.first != -1) {
        board[move.first][move.second] = 'O';
        moves++;
        cout << "Bot BLOCKS at: " << move.first << ", " << move.second << endl;
        displayBoard();
        return;
    }

    // 3️⃣ Take center
    if (board[1][1] == '-') {
        board[1][1] = 'O';
        moves++;
        cout << "Bot takes CENTER" << endl;
        displayBoard();
        return;
    }

    // 4️⃣ Take a corner
    int corners[4][2] = {{0,0},{0,2},{2,0},{2,2}};
    for (auto &c : corners) {
        if (board[c[0]][c[1]] == '-') {
            board[c[0]][c[1]] = 'O';
            moves++;
            cout << "Bot takes CORNER at: " << c[0] << ", " << c[1] << endl;
            displayBoard();
            return;
        }
    }

    // 5️⃣ Take any side
    int sides[4][2] = {{0,1},{1,0},{1,2},{2,1}};
    for (auto &s : sides) {
        if (board[s[0]][s[1]] == '-') {
            board[s[0]][s[1]] = 'O';
            moves++;
            cout << "Bot takes SIDE at: " << s[0] << ", " << s[1] << endl;
            displayBoard();
            return;
        }
    }
}


    bool checkWin(char player) {
        // Check rows and columns
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
                (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
                return true;
            }
        }
        // Check diagonals
        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
            return true;
        }
        return false;
    }
    void getnames(){
        cout<<"Enter player-1 name: ";
        cin>>player1;
        cout<<"Enter player-2 name: ";
        cin>>player2;
    }
void getname(){
    cout<<"Enter player name: ";
    cin>>player1;
}
    void play() {
        resetBoard();
        cout << "---------- Game Started ----------\n";

        while (moves < 9) {
            player1Move();
            displayBoard();
            if (checkWin('X')) {
                cout << "\n🎉 "<<player1<<" WON! 🎉\n";
                return;
            }
            if (moves >= 9) break; // Prevent bot move if board is full
           if(multi == 1){
            player2Move();
            if (checkWin('O')) {
                displayBoard();
                cout << "\n🎉 "<<player2<<" WON! 🎉\n";
                return;
            }
           }
           else{
            botMove();
            if (checkWin('O')) {
                displayBoard();
                cout << "\n💀 Bot WON! 💀\n";
                return;
            }
           }
        }

        displayBoard();
        cout << "\n🤝 It's a Tie! 🤝\n";
    }
};

int main() {
    TicTacToe game;
    int choice;

    while (true) {
        cout << "Enter 1 to start or 2 to exit: ";
        cin >> choice;
        if (choice == 1) {
            cout<<"Enter 1 for Player vs Player or 2 for Player vs Bot: ";
            cin>>game.multi;
            if(game.multi==1){
            game.getnames();}
            else {game.getname();}
            game.disboardmoves();
            game.play();
        } else if (choice == 2) {
            cout << "Thanks for playing! Goodbye! 😊\n";
            break;
        } else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}