#include <iostream>
using namespace std;

class Complex {
    int real, imag;
public:
    void getData() { 
        cin>>real>>imag; 
    }
    friend Complex operator+(Complex, Complex);
    void display() {
         cout<<real<<" + "<<imag<<"i\n"
		 ; 
    }
};

Complex operator+(Complex c1, Complex c2) {
    Complex temp;
    temp.real=c1.real+c2.real;
    temp.imag=c1.imag+c2.imag;
    return temp;
}

int main() {
    Complex c1, c2, c3;
    cout<<"Enter 1st complex numbers: ";
    c1.getData();
    cout<<"Enter 2nd complex numbers: ";
	c2.getData();
    c3=c1+c2;
    cout<<"Result complex number: ";
    c3.display();
    return 0;
}

