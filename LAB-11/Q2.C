#include <stdio.h>
#include <stdlib.h>

int arr[100];      // Array to store inorder traversal
int ind = 0;     // Index for array

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert into BST
struct Node* insert(struct Node* root, int val) {

    if (root == NULL)
        return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Use inorder traversal of bst and store elements in array.
void inorder(struct Node* root) {

    if (root == NULL) return;

    inorder(root->left);
    arr[ind++] = root->data;
    inorder(root->right);

}

// Find pair with given sum.
void findPair(int target) {

    int i = 0, j = ind - 1;

    while (i < j) {

        int sum = arr[i] + arr[j];

        if (sum == target) {
            printf("Numbers are: %d %d\n", arr[i], arr[j]);

            return;
        }
        if (sum < target)
            i++;
        else
            j--;
    }
    printf("No two nodes found whose sum is equal to target\n");

}

int main() {
    struct Node* root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 18);

    int target;
    printf("Enter target sum: ");
    scanf("%d", &target);

    inorder(root);          // Fill array with sorted BST values
    findPair(target);       // Find and print the pair

    return 0;
}