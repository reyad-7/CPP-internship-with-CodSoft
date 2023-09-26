#include<bits/stdc++.h>
using namespace std;

void displayBoard (char board [3][3]){
    for (int i = 0; i < 3; ++i) {
        cout << "-------------" << endl;
        cout << "| ";
            for (int j = 0; j < 3; ++j) {
                cout<<board[i][j]<<" | ";
            }
        cout << endl;
    }
    cout << "-------------" << endl;
}

bool checkForWin (char board [3][3],char player) {
    for (int i = 0; i < 3; ++i) {
//        check rows
        if (board[i][0]==player&&board[i][1]==player&&board[i][2]==player){
            return true;
        }
//        check columns
        if (board[0][i]==player&&board[1][i]==player&&board[i][2]==player){
            return true;
        }
//        check diagonal (from left to right)
        if (board[0][0]==player&&board[1][1]==player&&board[2][2]==player){
            return true;
        }
//        check diagonal (from right to left )
        if (board[0][2]==player&&board[1][1]==player&&board[2][0]==player){
            return true;
        }
        return false;
    }
}

bool checkForDraw (char board [3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j]!='X'&&board[i][j]!='O'){
                return false;
            }
        }
    }
    return true;
}


void updateBoard(char board[3][3] , int row , int col ,char player){
    board[row-1][col-1]=player;
}

bool validateMove (char board[3][3] , int row , int col){
    if ( (row<1||row>3) || (col<1||col>3) || (board[row-1][col-1]!=' ') ){
        return false;
    }
    return true;
}

int main() {
    char playAgain='y';
    while (playAgain=='y'){
        //Create a 3x3 grid as the game board.
        char board[3][3] =
                {{' ' , ' ' , ' '},
                 {' ' , ' ' , ' '},
                 {' ' , ' ' , ' '}};
        int row , col;
        char player = 'X';
        bool endGame = false;
        cout << "Welcome to Tic-Tac-Toe!" << endl;

        while (!endGame){
            displayBoard(board);
            cout << "player "<<player<<"\n" << "enter your position (row column) :\n";
            cin >> row>> col;

            if (validateMove(board,row,col)){
                updateBoard(board,row,col,player);
            }
            else if (!(validateMove(board,row,col))) {
                cout << "Invalid Position \nplayer "<<player<<" try again :\n";
                continue;
            }

            if (checkForWin(board,player)){
                displayBoard(board);
                cout<<"player "<<player<<" won :)\n";
                endGame= true;
                break;
            }

            else if (checkForDraw(board)){
                displayBoard(board);
                cout << "game ended with draw \n";
                endGame= true;
                break;
            }

            // Alternate turns between X and O players
            if (player=='X')
                player='O';
            else
                player='X';
        }
        cout <<"do you want to play again (y/n):\n";
        cin >> playAgain;
    }
}