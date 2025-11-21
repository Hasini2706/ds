//Create a class Account with private balance, protected accountNumber, and public holderName. Show how to access each correctly.
#include <bits/stdc++.h>
using namespace std;
class Account {
private:
    double balance;  
protected:
    int accountNumber;  
public: 
    string holderName;  
    Account(string name, int accNum, double bal) {
    	holderName=name;
    	accountNumber=accNum;
    	balance=bal;
    	
	}
	void printDetails(){
	cout<<"HolderName: "<<holderName<<endl;
	cout<<"Account Number: "<<accountNumber<<endl;
	cout<<"HolderName: "<<balance<<endl;
	}
	
};
int main() {
	Account a("Hasini",1234,10000);
	a.printDetails();
}
