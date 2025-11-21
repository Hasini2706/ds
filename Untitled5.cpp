//Create a class Employee to count how many objects are created using a static variable.
#include<iostream>
using namespace std;
class employee{
	static int count;
public:
string name;
int id;
 employee() {
 	count++;
 	cout<<"no of obj: "<<count<<endl;
 }
 static getcount() {
 	return count;
 }
};
int main() {
	employee e
}
