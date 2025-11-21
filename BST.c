#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct node {
    struct node *left;
    int data;
    struct node *right;
};

typedef struct node NODE;
NODE *root = NULL; // Global root pointer for the BST

// Function declarations
void create(int);                   // Creates and inserts a new node
void insert(NODE*, NODE*);          // Recursively inserts a node into the BST
NODE* delete_node(NODE*, int);      
int search(NODE*, int);             
void traverse(NODE*);               // In-order traversal
NODE* find_max(NODE*);              // Finds the maximum value node (used during deletion)

// Function to create and insert a new node with given value
void create(int value) {
    NODE *newnode = (NODE *)malloc(sizeof(NODE)); // Allocate memory
    if (newnode == NULL) {
        printf("Memory not allocated\n");
        return;
    }

    // Initialize node
    newnode->data = value;
    newnode->left = newnode->right = NULL;

    // If tree is empty, set root
    if (root == NULL)
        root = newnode;
    else
        insert(root, newnode); // Otherwise, insert into the tree
}

// Recursive function to insert a node into the BST
void insert(NODE *root, NODE *newnode) {
    if (newnode->data < root->data) {
        if (root->left == NULL)
            root->left = newnode;
        else
            insert(root->left, newnode);
    } else {
        if (root->right == NULL)
            root->right = newnode;
        else
            insert(root->right, newnode);
    }
}

// Function to search for a value in the BST
int search(NODE* root, int key) {
    if (root == NULL)
        return 0; // Value not found
    if (root->data == key)
        return 1; // Value found
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Function to find the node with maximum value in a subtree
NODE* find_max(NODE* root) {
    if (root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

// Function to delete a node from the BST
NODE* delete_node(NODE *root, int value) {
    NODE *temp;
    if (root == NULL)
        return NULL; // Base case: not found

    if (value < root->data) {
        root->left = delete_node(root->left, value);
    } else if (value > root->data) {
        root->right = delete_node(root->right, value);
    } else {
        // Node to be deleted found

        // Case 1: Node with no children
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: Node with one child (right)
        else if (root->left == NULL) {
            temp = root;
            root = root->right;
            free(temp);
        }

        // Case 3: Node with one child (left)
        else if (root->right == NULL) {
            temp = root;
            root = root->left;
            free(temp);
        }

        // Case 4: Node with two children
        else {
            temp = find_max(root->left); // Find in-order predecessor
            root->data = temp->data; // Replace with predecessor's data
            root->left = delete_node(root->left, temp->data); // Delete predecessor node
        }
    }
    return root;
}

// In-order traversal: Left ? Root ? Right
void traverse(NODE *root) {
    if (root != NULL) {
        traverse(root->left);
        printf("%d\t", root->data);
        traverse(root->right);
    }
}

// Main menu-driven program
int main() {
    int ch, value;
    do {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n2. Traverse (In-Order)\n3. Delete\n4. Search\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                create(value);
                break;
            case 2:
                if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    printf("In-Order Traversal: ");
                    traverse(root);
                    printf("\n");
                }
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                if (search(root, value)) {
                    root = delete_node(root, value);
                    printf("Value %d deleted from the tree.\n", value);
                } else {
                    printf("Value %d not found in the tree.\n", value);
                }
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value))
                    printf("Value %d found in the tree.\n", value);
                else
                    printf("Value %d not found in the tree.\n", value);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (1);

    return 0;
}