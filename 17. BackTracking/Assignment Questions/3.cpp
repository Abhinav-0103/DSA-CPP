#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<vector<int>> board, int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int row, int col, vector<vector<int>> board, int n) {
    return (row >=0 && row < n && col >= 0 && col < n) && (board[row][col] == -1);
}

bool knightTourUtil(int n, int row, int col, int xMove[], int yMove[], int countVisited, vector<vector<int>> board) {
    if(countVisited == (n * n)) {
        return true;
    }
    int nextRow, nextCol;

    for(int i=0;i<8;i++) {
        nextRow = row + xMove[i];
        nextCol = col + yMove[i];

        if(isSafe(nextRow,nextCol,board,n)) {
            board[nextRow][nextCol] = countVisited;
            if(knightTourUtil(n,nextRow,nextCol,xMove,yMove,countVisited+1,board)) {
                return true;
            } else {
                board[nextRow][nextCol] = -1;
            }
        }
    }

    return false;
} 

bool knightTour(int n) {
    vector<vector<int>> board;

    for(int i=0;i<n;i++) {
        vector<int> temp1;
        for(int j=0;j<n;j++) {
            temp1.push_back(-1);
        }
        board.push_back(temp1);
    }

    int xMove[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[] = {1, 2, 2, 1, -1, -2, -2, -1};

    int countVisited = 1;

    board[0][0] = 0;

    printArray(board,n);

    if(!knightTourUtil(n,0,0,xMove,yMove,countVisited,board)) {
        cout << "Solution Does not Exist" << endl;
        return false;
    }

    printArray(board,n);

    return true;
}

int main() {
    int n = 5;

    knightTour(n);
}