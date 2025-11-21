#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
	struct node* prev;
};
struct node *first=NULL;
struct node *last=NULL;
int i,count=0;
void create();
void displayforward();
void displaybackward();
void insert();
void deletenode();
int main() {
	int ch;
	while(1) {
		printf("");
		scanf("%d",&ch);
		switch(ch) {
			case 1:create(); break;
			case 2:displayforward(); break;
			case 3:displaybackward(); break;
			case 4:insert(); break;
			case 5:deletenode(); break;
			case 6:exit(0);
			default:printf("Invalid");
		}
	}
}
void create() {
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL) {
		printf("MEmory allocation failed\n");
		return;
	}
	printf("enter data");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	if(first==NULL) {
		first=last=newnode;
	}
	else {
		last->next=newnode;
		newnode->prev=last;
		last=newnode;
	}
	count++;
}
void displayforward() {
	if(first==NULL) {
		printf("List is empty");
	}
	else {
		struct node* temp=first;
		while(temp!=NULL) {
			printf("%d <-> ",temp->data);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}
void displaybackward() {
	if(last==NULL) {
		printf("List is empty");
	}
	else {
		struct node* temp=last;
		while(temp!=NULL) {
			printf("%d <-> ",temp->data);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}
void insert() {
	int pos;
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL) {
		printf("memory not allocated");
		return;
	}
	printf("enter position");
	scanf("%d",&pos);
	printf("Enter data");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	if(pos<1||pos>count+1) {
		printf("INvalid position\n");
		return;
	}
	if(pos==1) {
		newnode->next=first;
		if(first!=NULL) 
		first->prev=newnode;
		first=newnode;
		if(last==NULL)
		 last=newnode;
	}
	else {
		struct node* temp=first;
		for(i=1;i<pos-1;i++) {
			temp=temp->next;
		}
		newnode->next=temp->next;
		newnode->prev=temp;
		if(temp->next!=NULL) {
			temp->next->prev=newnode;
			temp->next=newnode;
		}
		if(pos==count+1) {
			last=newnode;
		}
	}
	count++;
}
void deletenode() {
	int pos;
	scanf("%d",&pos);
	if(pos<1||pos>count) {
		printf("INVALID");
		return;
	}
	if(pos==1) {
		first=first->next;
		if(first!=NULL) 
			first->prev=NULL;
			else last=NULL;

	}
	else {
		struct node* temp=first;
		for(i=1;i<pos;i++) {
			temp=temp->next;
		}
		temp->prev->next=temp->next;
		if(temp->next!=NULL) 
			temp->next->prev=temp->prev;
         last=temp->prev;
	}
	count--;
}


