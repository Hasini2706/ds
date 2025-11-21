#include <iostream>
using namespace std;
class node {
    private:
    int data;
    node* next;
    public:
    node* temp;
    node() {
        data=0;
        next=NULL;
    } 
    void insert(int x) {
        if(head==NULL) {
            head=tail=0;
            data=x;
            next=NULL;
        } 
    } 
    void deleteElement() {
        data=0;
        next=NULL;
    }
    int display() {
        return data;
    }
};

int main() {
    node l;
    int x;
    cin>>x;
    l.insert(x);
    cout<<l.display()<<endl;
}