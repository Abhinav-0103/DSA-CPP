#include<iostream>
#include<queue>
#include<string>
using namespace std;

class Student {
    public :
        string name;
        int marks;

        Student(string name, int marks) {
            this->name = name;
            this->marks = marks;
        }

        bool operator < (const Student &obj) const {
            return this->marks < obj.marks;
        }
};

int main() {
    priority_queue<Student> pq;

    pq.push(Student("Aman", 65));
    pq.push(Student("Ram", 75));
    pq.push(Student("Shyam", 85));

    while(!pq.empty()) {
        cout << pq.top().name << ": " << pq.top().marks << endl;
        pq.pop();
    }
}