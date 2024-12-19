#include<stdio.h>
#define SIZE 10
void push(int value);
void pop(void);
void display();
void peek();
int top=-1;
int stack[SIZE]={0};
int main()
{  
    push(6);
    push(7);
    push(8);
    push(5);
    push(3);
    pop();
    push(10);
    pop();
    pop();
    display();
    peek();
    return 0;
}

void push(int value)
{
    if(top==SIZE-1)
    printf("\nStack Overflow\n");
    else
    {
        top++;
        stack[top]=value;
    }
}

void pop(void)
{
    int value;
    if(top==-1)
    printf("Stack Underflow\n");
    else
    {
        value=stack[top];
        top--;
    }
}
void display()
{
    for(int i=0;i<=top;i++)
    {
        printf("%-3d",stack[i]);
    }
}
void peek()
{
    printf("\n%d",stack[top]);

} 