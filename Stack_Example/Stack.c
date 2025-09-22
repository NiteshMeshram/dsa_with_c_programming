#include <stdio.h>
#define SIZE 5

void push(int); // prototype
int isFull();
void pop();
int isEmpty();
void traverse();
void peek();

int stack[SIZE], top=-1;

int main() 
{
    int ch, ele;
    while(1)
    {
        printf("1. push \n");
        printf("2. pop \n");
        printf("3. traverse \n");
        printf("4. peek \n");
        printf("5. exit \n");
        
        printf("Enter your choice : ");
        scanf("%d", &ch);
        
        if(ch==1)
        {
            printf("Enter ele to push : ");
            scanf("%d", &ele);
            push(ele);
        }
        else if(ch==2)
        {
            pop();
        }
        else if(ch==3)
        {
            traverse();
        }
        else if(ch==4)
        {
            peek();
        }
        else if(ch==5)
        {
            printf("End \n");
            break;
        }
        else
        {
            printf("Error : Invalid choice \n");
        }
    }
    return 0;
}
void push(int ele)
{
    if(isFull())
    {
        printf("Stack is Full");
    }
    else
    {
        stack[++top] = ele;
        printf("Element pushed \n");
    }
}
int isFull()
{
    if(top == SIZE-1)
        return 1;
    else
        return 0;
}
void pop()
{
    if(isEmpty())
    {
        printf("Stack is Empty \n");
    }
    else
    {
        printf("Pop : %d \n", stack[top--]);
    }
}
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
void traverse()
{
    if(isEmpty())
    {
        printf("Stack is Empty \n");
    }
    else
    {
        int i;
        printf("Stack elements : \n");
        for(i=top ; i>=0 ; i--)
            printf("%d \n", stack[i]);
    }
}
void peek()
{
    if(isEmpty())
    {
        printf("Stack is Empty \n");
    }
    else
    {
        printf("Peek : %d \n", stack[top]);
    }
}