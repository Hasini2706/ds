//Create a class Calculator with inline functions for add, subtract, and multiply two integers.
#include<iostream>
using namespace std;
class calculator{
	public:
		int x;
		int y;
	calculator(int a,int b) {
		x=a;
		y=b;
	}
	int add() {
		return x+y;
	} 
	int sub() {
		return x-y;
	}
	int mul() {
		return x*y;
	} 
	int div() {
		return x/y;
	}
};
int main() {
	calculator c(4,2);
	cout<<"Addition: "<<c.add()<<endl;
	cout<<"Subtraction: "<<c.sub()<<endl;
	cout<<"Multiplication: "<<c.mul()<<endl;
	cout<<"Division: "<<c.div()<<endl;
	
}
