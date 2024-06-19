#include<iostream>
using namespace std;

class Person {
    protected:
        string name;
        int age;

    public: 
        Person(string name, int age) {
            this->name = name;
            this->age = age;
        }
};

class Student: public Person {
    protected:
        string studentId;
    
    public:
        Student(string name, int age, string id): Person(name, age) {
            studentId = id;
        }

        void displayStudentInfo() {
            cout << "Student Name: " << name << endl;
            cout << "Student Age: " << age << endl;
            cout << "Student Id: " << studentId << endl;
        }
};



int main() {
    Student s1("Alice", 20, "S12345");

    s1.displayStudentInfo();
    return 0;
}