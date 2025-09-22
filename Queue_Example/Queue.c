#include <stdio.h>
#define SIZE 5

void push(int); // prototype
void delete();
void traverse();

int isFull(); // Before push check
int isEmpty(); // Before delete check
void peek(); // show front element

int queue[SIZE], front=0, rear=-1;

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
        
        if(ch==1)  {
            printf("Enter ele to push : ");
            scanf("%d", &ele);
            push(ele);
        }
        else if (ch==2)
        {
            delete();
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
        printf("Stack is Full \n");
    }
    else
    {
        queue[++rear]=ele;
        printf("%d pushed \n", ele);
    }
}

int isFull()
{
    if(rear == SIZE-1)
        return 1;
    else
        return 0;
}


int isEmpty()
{
    if(front > rear)
        return 1;
    else
        return 0;
}

void delete()
{
    if(isEmpty())
    {
        printf("Queue is Empty \n");
    }
    else
    {
        printf("Delete : %d \n", queue[front++]);
    }
}

void traverse()
{
    if(isEmpty())
    {
        printf("Queue is Empty \n");
    }
    else
    {
        printf("Queue elements : \n");
        for(int i=front; i<=rear; i++)
        {
            printf("%d \n", queue[i]);
        }
    }
}

void peek()
{
    if(isEmpty())
    {
        printf("Queue is Empty \n");
    }
    else
    {
        printf("Front element : %d \n", queue[front]);
    }
}
