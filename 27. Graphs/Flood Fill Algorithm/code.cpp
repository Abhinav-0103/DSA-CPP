#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool inRange(vector<vector<int>>& image, int r, int c) {
        if(r >= 0 && c >=0 && r < image.size() && c < image[0].size()) {
            return true;
        }

        return false;
    }

    void fillAlgo(vector<vector<int>>& image, vector<vector<bool>>& vis, int sr, int sc, int color, int toChange) {
        image[sr][sc] = color;
        vis[sr][sc] = true;

        if(inRange(image,sr-1,sc) && !vis[sr-1][sc] && image[sr-1][sc] == toChange) {
            fillAlgo(image,vis,sr-1,sc,color,toChange);
        }

        if(inRange(image,sr,sc+1) && !vis[sr][sc+1] && image[sr][sc+1] == toChange) {
            fillAlgo(image,vis,sr,sc+1,color,toChange);
        }

        if(inRange(image,sr+1,sc) && !vis[sr+1][sc] && image[sr+1][sc] == toChange) {
            fillAlgo(image,vis,sr+1,sc,color,toChange);
        }

        if(inRange(image,sr,sc-1) && !vis[sr][sc-1] && image[sr][sc-1] == toChange) {
            fillAlgo(image,vis,sr,sc-1,color,toChange);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int toChange = image[sr][sc];
        vector<vector<bool>> vis(image.size(), vector<bool>(image[0].size(), false));

        fillAlgo(image,vis,sr,sc,color,toChange);

        return image;
    }
};

int main() {
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;

    Solution sol;

    for(vector<int> row: image) {
        for(int c: row) {
            cout << c << " ";
        }
        cout << endl;
    }

    cout << endl << endl;

    sol.floodFill(image,sr,sc,color);

    for(vector<int> row: image) {
        for(int c: row) {
            cout << c << " ";
        }
        cout << endl;
    }
}