//Create a class Rectangle with length and breadth. Define member functions to calculate area and perimeter.
#include<iostream>
using namespace std;
class rectangle{
	public:
		int length;
		int breadth;
	rectangle(int l,int b) {
		length=l;
		breadth=b;
	}
	int area() {
		return length*breadth;
	} 
	int perimeter() {
		return 2*(length+breadth);
	}
};
int main() {
	rectangle r(2,3);
	cout<<"area: "<<r.area()<<endl;
	cout<<"Perimeter: "<<r.perimeter()<<endl;
}
