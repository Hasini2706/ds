#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node *left;
    int data;
    struct node *right;
};
typedef struct node Node;
NODE *root = NULL;
void create(int);
void insert(NODE*, NODE*);
NODE* delete_node(NODE*, int);
int search(NODE*, int);
void traverse(NODE*);
NODE* find_max(NODE*);
void create(int value) {
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    if(newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    if (root == NULL) {
        root = new_node;
    } else {
        insert(root, new_node);
    }
}
void insert(NODE* root, NODE* new_node) {
    if (new_node->data < root->data) {
        if (root->left == NULL) {
            root->left = new_node;
        } else {
            insert(root->left, new_node);
        }
    } else {
        if (root->right == NULL) {
            root->right = new_node;
        } else {
            insert(root->right, new_node);
        }
    }
}
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
NODE* find_max(NODE* root) {
    if(root==NULL) 
    return NULL;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}
NODE* delete_node(NODE* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->data) {
        root->left = delete_node(root->left, key);
    } else if (key > root->data) {
        root->right = delete_node(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            NODE* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            NODE* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        NODE* temp = find_max(root->left);
        root->data = temp->data; // Copy the inorder successor's content to this node
        root->left = delete_node(root->left, temp->data); // Delete the inorder successor
    }
    return root;
}
void traverse(NODE* root) {
    if (root != NULL) {
        traverse(root->left);
        printf("%d ", root->data);
        traverse(root->right);
    }
}
int main() {
    int choice, value;
    while (1) {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Traverse\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                create(value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value)) {
                    printf("Value found in the tree.\n");
                } else {
                    printf("Value not found in the tree.\n");
                }
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = delete_node(root, value);
                break;
            case 4:
                printf("Tree elements in sorted order: ");
                traverse(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}