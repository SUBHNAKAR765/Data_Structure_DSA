#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
          printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) 
{
    if (root == NULL) 
    {
        root = createNode(data);
    } 
    else 
    {
        if (data <= root->data) 
        {
            root->left = insertNode(root->left, data);
        }
         else 
        {
            root->right = insertNode(root->right, data);
        }
    }
    return root;
}
