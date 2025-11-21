#include <iostream>
using namespace std;

class Complex {
    int real, imag;
public:
    void getData() { 
        cin>>real>>imag; 
    }
    Complex operator+(Complex c) {
        Complex temp;
        temp.real=real+c.real;
        temp.imag=imag+c.imag;
        return temp;
    }
    void display() { 
	cout<<real<<" + "<<imag<<"i\n"; 
	}
};

int main() {
    Complex c1,c2,c3;
    cout<<"Enter first complex: ";
    c1.getData();
    cout<<"Enter second complex: ";
    c2.getData();
    c3=c1+c2;
    cout<<"Result complex number: ";
    c3.display();
    return 0;
}

