#include <iostream>
using namespace std;

class Student {
    int id;

public:
    // Default Constructor
    Student() {
        id = 0;
        cout << "Default Constructor called\n";
    }

    // Parameterized Constructor
    Student(int x) {
        id = x;
        cout << "Parameterized Constructor called\n";
    }

    // Copy Constructor
    Student(const Student &s) {
        id = s.id;
        cout << "Copy Constructor called\n";
    }

    void display() {
        cout << "Student ID: " << id << endl;
    }
};

int main() {
    Student s1;            // Calls Default Constructor
    Student s2(101);       // Calls Parameterized Constructor
    Student s3 = s2;       // Calls Copy Constructor

    cout << "\nDisplaying Objects:\n";
    s1.display();
    s2.display();
    s3.display();

    return 0;
}

