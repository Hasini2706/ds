#include<bits/stdc++.h>
using namespace std;
class Student;
class Teacher{
 public:
  void evaluate(Student s);
};

class Student{
    private:
    int marks=95;
    friend class Teacher;
    friend void Teacher:: evaluate(Student s);
    
};
void Teacher::evaluate(Student s) {
    cout<<"student marks: "<<s.marks<<endl;
}
int main() {
Student s;
Teacher t1;
t1.evaluate(s);
return 0;
}


