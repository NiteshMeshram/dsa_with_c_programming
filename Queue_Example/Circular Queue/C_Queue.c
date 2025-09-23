#include <stdio.h>
#define SIZE 8

void push(int); // prototype
void delete();
void traverse();

int isFull(); // Before push check
int isEmpty(); // Before delete check
void peek(); // show front element

int c_queue[SIZE], front=0, rear=-1;

int main() 
{
    int ch, ele; 

    while(1)
    {
        printf("1. push \n");
        printf("2. delete \n");
        printf("3. traverse \n");
        printf("4. peek \n");
        printf("5. exit \n");
        
        printf("Enter your choice : ");
        scanf("%d", &ch); 

        if (ch==1)  {
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
}

int isFull()
{
    if(front==0 && rear == SIZE-1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(front == -1)
        return 1;
    else
        return 0;
}

void push(int ele)
{
    if(isFull())
    {
        printf("Circular Queue is Full \n");
    }
    else
    {
        if(front == -1) // for first element
            front = 0;
        
        rear = (rear + 1) % SIZE; // circular increment
        c_queue[rear]=ele;
        printf("%d pushed \n", ele);
    }
}

void delete()
{
    if(isEmpty())
    {
        printf("Circular Queue is Empty \n");
    }
    else
    {
        int deleted_ele = c_queue[front];
        if(front == rear) // only one element
            front = rear = -1; // reset queue after deletion
        else
            front = (front + 1) % SIZE; // circular increment

        printf("Deleted : %d \n", deleted_ele);
    }
}

void traverse()
{
    if(isEmpty())
    {
        printf("Circular Queue is Empty \n");
    }
    else
    {
        int i;
        printf("Circular Queue elements : \n");
        for(i=front ; ; i=(i+1)%SIZE) // circular increment
        {
            printf("%d \n", c_queue[i]);
            if(i == rear)
                break;
        }
    }
}

void peek()
{
    if(isEmpty())
    {
        printf("Circular Queue is Empty \n");
    }
    else
    {
        printf("Front element : %d \n", c_queue[front]);
    }
}