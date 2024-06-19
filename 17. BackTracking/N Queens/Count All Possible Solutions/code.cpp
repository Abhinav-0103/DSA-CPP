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

int nQueens(vector<vector<char>> board, int row) {
    if(row == board[0].size()) {
        return 1;
    }

    int n = board[0].size();
    int count = 0;

    for(int i=0;i<n;i++) {
        if(isSafe(board,row,i)) {
            board[row][i] = 'Q';
            count = count + nQueens(board, row+1);
            board[row][i] = '.';
        }
    }

    return count;
}

int main() {
    vector<vector<char>> board;
    int n = 7;

    for(int i=0;i<n;i++) {
        vector<char> temp;
        for(int i=0;i<n;i++) {
            temp.push_back('.');
        }

        board.push_back(temp);
    }
    
    cout << "Count = " << nQueens(board,0) << endl;

    return 0;
}