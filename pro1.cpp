//Create a class Student with roll number and name. Declare two objects and display their values using a member function
#include<iostream>
using namespace std;
class student{
    public:
    int rollno;
    string name;
    student(int r, string n) { 
        rollno = r;
        name = n;
    }
};

int main() {
    student s1(1,"Hasini");
    student s2(2,"Bheeme");
    cout<<"Roll no: " << s1.rollno<<"\nName: "<<s1.name<<endl;
    cout<<"Roll no: " << s2.rollno<<"\nName: "<<s2.name<<endl;
}
