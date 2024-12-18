// 1)Creation and insertion of node
// 2)Searching of node
// 3)Traversing -Preorder ,Inorder ,Post order IN A TREE

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *create(int data) 
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL) 
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    n->data = data;
    n->left = n->right = NULL;
    return n;
}
struct Node *insert(struct Node *root, int data) {
    if (root == NULL) {
        root = create(data);
    } else {
        if (data <= root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
    }
    return root;
}
struct Node *search(struct Node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int main() {
    struct Node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    int searchData ;
    printf("Enter the value to search: ");
    scanf("%d", &searchData);
    struct Node *searchResult = search(root, searchData);
    if (searchResult != NULL) {
        printf("Node with data %d found in the tree.\n", searchData);
    } else {
        printf("Node with data %d not found in the tree.\n", searchData);
    }
    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    return 0;
}
