#include<iostream>
#include<vector>
using namespace std;

class Heap {
    vector<int> heap;

    public :
        void push(int val) {
            heap.push_back(val);

            int childIdx = heap.size() - 1;
            int parIdx = (childIdx - 1) / 2;

            while(parIdx >= 0 && heap[childIdx] > heap[parIdx]) {
                swap(heap[childIdx], heap[parIdx]);

                childIdx = parIdx;
                parIdx = (childIdx - 1) / 2;
            }
        }

        void heapify(int i) {
            if(i >= heap.size()) {
                return;
            }

            int l = 2 * i + 1;
            int r = 2 * i + 2;

            int maxI = i;

            if(l < heap.size() && heap[l] > heap[maxI]) {
                maxI = l;
            }

            if(r < heap.size() && heap[r] > heap[maxI]) {
                maxI = r;
            }

            swap(heap[i], heap[maxI]);

            if(i != maxI) {
                heapify(maxI);
            }
        }

        void pop() {
            swap(heap[0], heap[heap.size()-1]);

            heap.pop_back();

            heapify(0);
        }

        int top() {
            if(empty()) {
                return -1;
            }
            return heap[0];
        }

        bool empty() {
            return heap.size() == 0;
        }
};

int main() {
    Heap hp;

    hp.push(8);
    hp.push(4);
    hp.push(5);
    hp.push(1);
    hp.push(2);
    hp.push(9);

    while(!hp.empty()) {
        cout << hp.top() << endl;
        hp.pop();   
    }
}