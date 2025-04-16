#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    // If value == root->data, do nothing (no duplicates)
    return root;
}

// Pre-order traversal
void PreOrder(struct Node* root) {
    if (root == NULL)
        return;
    printf("| %d | ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

// In-order traversal
void InOrder(struct Node* root) {
    if (root == NULL)
        return;
    InOrder(root->left);
    printf("| %d | ", root->data);
    InOrder(root->right);
}

// Post-order traversal
void PostOrder(struct Node* root) {
    if (root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    printf("| %d | ", root->data);
}

// Main function for testing
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Insert Node\n2. Pre-Order Traversal\n3. In-Order Traversal\n4. Post-Order Traversal\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;

            case 2:
                printf("Pre-order Traversal: ");
                PreOrder(root);
                printf("\n");
                break;

            case 3:
                printf("In-order Traversal: ");
                InOrder(root);
                printf("\n");
                break;

            case 4:
                printf("Post-order Traversal: ");
                PostOrder(root);
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
