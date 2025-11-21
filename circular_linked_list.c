#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* next;
};
// Global pointers
struct node *first = NULL;
struct node *last = NULL;
int count = 0,i;
// Function prototypes
void create();
void display();
int main() {
    int ch;
    while (1) {
        printf("\n1. Create\n2. Display\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
switch (ch) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function to create a new node at the end
void create() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("Enter data: ");
    scanf("%d", &newnode->data);
	newnode->next = NULL;

    if (first == NULL) {
        first = last = newnode;
    } else {
        last->next = newnode;
        last = newnode;
    }
    last->next=first;
}

// Function to display the linked list
void display() {
    if (first == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node* temp = first;
    printf("Linked List: ");
   do {
        printf("%d->", temp->data);
        temp = temp->next;
    } while (temp != first);
    printf("Back to first %d",temp->data);
}
void insert() {
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	int pos;
	scanf("%d",&pos);
	if(pos==1) {
		newnode->next=first;
		newnode->prev=last;
		first=newnode;
		last->next=newnode;
	}
	else {
	   	struct node* temp=first;
		   for(i=1;i<pos-1;i++) {
		   	temp=temp->next;
		   }	
		   newnode->next=temp->next;
		   newnode->prev=temp;
		   temp->next->prev=newnode;
		   temp->next=newnode;
	}
	if(pos==count+1) {
		last=newnode;
		
	}
}
