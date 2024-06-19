#include<iostream>
using namespace std;

void printSudoku(int sudoku[9][9]) {
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int sudoku[9][9], int row, int col, int dig) {
    // Check Entire Row
    for(int i=0;i<9;i++) {
        if(sudoku[i][col] == dig) {
            return false;
        }
    }

    // Check Entire Column
    for(int i=0;i<9;i++) {
        if(sudoku[row][i] == dig) {
            return false;
        } 
    }

    // Check within the box
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for(int i=startRow;i<=startRow+2;i++) {
        for(int j=startCol;j<=startCol+2;j++) {
            if(sudoku[i][j] == dig) {
                return false;
            }
        }
    }

    return true;
}

bool sudokuSolver(int sudoku[9][9], int row, int col) {
    if(row == 9) {
        printSudoku(sudoku);
        return true;
    }

    int nextRow = row;
    int nextCol = col + 1;

    if(col + 1 == 9) {
        nextRow = row + 1;
        nextCol = 0;
    }

    if(sudoku[row][col] != 0) {
        return sudokuSolver(sudoku,nextRow,nextCol);
    }

    for(int i=1;i<=9;i++) {
        if(isSafe(sudoku,row,col,i)) {
            sudoku[row][col] = i;

            bool solExists = sudokuSolver(sudoku,nextRow,nextCol);
            if(solExists) {
                return true;
            }

            sudoku[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int sudoku[9][9] = {{0, 0, 8, 0, 0, 0, 0, 0, 0},
                      {4, 9, 0, 1, 5, 7, 0, 0, 2},
                      {0, 0, 3, 0, 0, 4, 1, 9, 0},
                      {1, 8, 5, 0, 6, 0, 0, 2, 0},
                      {0, 0, 0, 0, 2, 0, 0, 6, 0},
                      {9, 6, 0, 4, 0, 5, 3, 0, 0},
                      {0, 3, 0, 0, 7, 2, 0, 0, 4},
                      {0, 4, 9, 0, 3, 0, 0, 5, 7},
                      {8, 2, 7, 0, 0, 9, 0, 1, 3}};
    
    sudokuSolver(sudoku,0,0);
}