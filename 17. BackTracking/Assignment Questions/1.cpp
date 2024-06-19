#include<iostream>
#include<vector>
using namespace std;

int waysInMazeUtil(int maze[][4], int n, int m, int row, int col, bool visited[][4], string ans) {
    if((row < 0) || (row >= n) || (col < 0) || (col >= m)) {
        return 0;
    }

    if((row == n-1) && (col == m-1)) {
        cout << ans << endl;
        return 1;
    }

    if(maze[row][col] == 0) {
        return 0;
    }

    int ways1, ways2, ways3, ways4;
    ways1 = ways2 = ways3 = ways4 = 0;

    if((row-1 >= 0) && !visited[row-1][col]) {
        visited[row][col] = true;
        ways1 = waysInMazeUtil(maze,n,m,row-1,col,visited,ans+"U");
        visited[row][col] = false;
    }

    if((col+1 < m) && !visited[row][col+1]) {
        visited[row][col] = true;
        ways2 = waysInMazeUtil(maze,n,m,row,col+1,visited,ans+"R");
        visited[row][col] = false;
    }

    if((row+1 < m) && !visited[row+1][col]) {
        visited[row][col] = true;
        ways3 = waysInMazeUtil(maze,n,m,row+1,col,visited,ans+"D");
        visited[row][col] = false;
    }

    if((col-1 >= 0) && !visited[row][col-1]) {
        visited[row][col] = true;
        ways4 = waysInMazeUtil(maze,n,m,row,col-1,visited,ans+"L");
        visited[row][col] = false;
    }

    return ways1 + ways2 + ways3 + ways4;
}

int waysInMaze(int maze[][4], int n, int m) {
    bool visited[4][4];

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            visited[i][j] = false;
        }      
    }
    return waysInMazeUtil(maze,n,m,0,0,visited,"");
}

int main() {
    int maze[][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = 4;
    int m = 4;

    int totalWays = waysInMaze(maze,n,m);

    cout << "Total Ways: " << totalWays << endl;
}