#include <iostream>
using namespace std;

class Student {
    int id;
public:
    Student() {        // Default constructor
        id = 0;
        cout << "Default Constructor\n";
    }

    Student(int x) {   // Parameterized constructor
        id = x;
        cout << "Parameterized Constructor\n";
    }

    void display() {
        cout << "ID: " << id << endl;
    }
};

int main() {
    Student s1;       // Calls default constructor
    Student s2(101);  // Calls parameterized constructor

    s1.display();
    s2.display();
    return 0;
}


