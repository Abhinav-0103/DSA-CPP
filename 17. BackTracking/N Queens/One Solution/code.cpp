#include<iostream>
#include<vector>
using namespace std;

void printBoard(vector<vector<char>> board) {
    int n = board[0].size();
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << board[i][j] << " ";
        }

        cout << endl;
    }
}

bool isSafe(vector<vector<char>> board, int row, int col) {
    int n = board[0].size();
    //Horizontal
    for(int i=0;i<n;i++) {
        if(board[row][i] == 'Q') {
            return false;
        }
    }

    //Vertical
    for(int i=0;i<row;i++) {
        if(board[i][col] == 'Q') {
            return false;
        }
    }

    //Left Diagonal
    for(int i=row,j=col;(i >= 0) && (j >= 0); i--,j--) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }

    //Right Diagonal
    for(int i=row,j=col;(i >= 0) && (j < n); i--,j++) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

bool nQueens(vector<vector<char>> board, int row) {
    if(row == board[0].size()) {
        printBoard(board);
        cout << "--------------------------------------" << endl;
        return true;
    }

    int n = board[0].size();

    for(int i=0;i<n;i++) {
        if(isSafe(board,row,i)) {
            board[row][i] = 'Q';
            bool solExists = nQueens(board, row+1);
            if(solExists) {
                return solExists;
            }
            board[row][i] = '.';
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board;
    int n = 4;

    for(int i=0;i<n;i++) {
        vector<char> temp;
        for(int i=0;i<n;i++) {
            temp.push_back('.');
        }

        board.push_back(temp);
    }
    
    nQueens(board,0);

    return 0;
}