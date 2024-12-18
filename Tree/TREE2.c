//SEARCHING A NODE IN A TREE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {              
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }
    }
    return root;
}

bool searchNode(struct Node* root, int key) {
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    if (key < root->data)
        return searchNode(root->left, key);
    else
        return searchNode(root->right, key);
}

int main() {
    struct Node* root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 7);                       
    root = insertNode(root, 12);

    int key;
    printf("Enter the value to search: ");
    scanf("%d", &key);

    if (searchNode(root, key))
        printf("%d is present in the tree.\n", key);
    else
        printf("%d is not present in the tree.\n", key);

    return 0;
}
