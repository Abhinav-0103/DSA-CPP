#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Row {
    public :
        int count;
        int idx;

        Row(int c, int idx) {
            this->count = c;
            this->idx = idx;
        }

        bool operator < (const Row &obj) const {
            if(this->count == obj.count) {
                return this->idx > obj.idx;
            }

            return this->count > obj.count;
        }
};

void weakestSoldier(vector<vector<int>> matrix, int K) {
    vector<Row> rows;

    for(int i=0;i<matrix.size();i++) {
        int count = 0;
        for(int j=0;j<matrix[i].size();j++) {
            if(matrix[i][j] == 1) {
                count++;
            } else {
                break;
            }
        }

        rows.push_back(Row(count,i));
    }

    priority_queue<Row> pq(rows.begin(), rows.end());

    for(int i=0;i<K;i++) {
        cout << "Row " << pq.top().idx << endl;
        pq.pop();
    }
}

int main() {
    vector<vector<int>> matrix = {{1,0,0,0},
                                  {1,1,1,1},
                                  {1,0,0,0},
                                  {1,0,0,0},};

    int K = 2;

    weakestSoldier(matrix, K);
}   