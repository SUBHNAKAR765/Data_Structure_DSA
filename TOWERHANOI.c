#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node* Stack;

Stack newNode(int data) {
    Stack node = (Stack) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int isEmpty(Stack stack) {
    return stack == NULL;
}

void push(Stack* stack, int data) {
    Stack node = newNode(data);
    node->next = *stack;
    *stack = node;
}

int pop(Stack* stack) {
    if (isEmpty(*stack)) {
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    int data = (*stack)->data;
    Stack node = *stack;
    *stack = (*stack)->next;
    free(node);
    return data;
}

void moveDisk(Stack* source, Stack* destination, Stack stacks[]) {
    int disk = pop(source);
    push(destination, disk);
    printf("Moved disk %d from stack %d to stack %d.\n", disk,
           source == &stacks[0] ? 1 : (source == &stacks[1] ? 2 : 3),
           destination == &stacks[0] ? 1 : (destination == &stacks[1] ? 2 : 3));
}

void hanoi(int n, Stack* source, Stack* auxiliary, Stack* destination, Stack stacks[]) {
    if (n > 0) {
        
        hanoi(n - 1, source, destination, auxiliary, stacks);

        
        moveDisk(source, destination, stacks);

        
        hanoi(n - 1, auxiliary, source, destination, stacks);
    }
}

int main() {
    
    Stack stacks[3] = {NULL, NULL, NULL};

    
    for (int i = 3; i >= 1; i--) {
        push(&stacks[0], i);
    }

    
    hanoi(3, &stacks[0], &stacks[1], &stacks[2], stacks);

    return 0;
}