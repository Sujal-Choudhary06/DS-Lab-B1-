/*
2) Implement a function to 
a)Count the total no of nodes
b)Count the no of leaf nodes
c)Find the height of the Binary tree.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* nNode = (struct Node*)malloc(sizeof(Node));
    nNode->data = value;
    nNode->left = NULL;
    nNode->right = NULL;
    return nNode;
}

// Count total number of nodes
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Count number of leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Find the height of the binary tree
int findHeight(struct Node* root) {
    if (root == NULL)
        return 0;
    int lHeight = findHeight(root->left);
    int rHeight = findHeight(root->right);
    return 1 + (lHeight > rHeight ? lHeight : rHeight);
}

int main() {

    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Total number of nodes: %d\n", countNodes(root));
    printf("Number of leaf nodes: %d\n", countLeafNodes(root));
    printf("Height of the tree: %d\n", findHeight(root));

    return 0;
}

/*
Output:
Total number of nodes: 5
Number of leaf nodes: 3
Height of the tree: 3
*/