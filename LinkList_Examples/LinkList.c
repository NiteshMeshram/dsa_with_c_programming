#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void append(int new_data);
void display();


int main() 
{
    struct  Node* head = (struct Node*)malloc(sizeof(struct Node));

    int ch, ele;
    while(1)
    {
        printf("1. Append \n");
        printf("2 Display List: \n");
        printf("3 Exis: \n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        
        if(ch==1)
        {
            printf("Enter ele to push : ");
            scanf("%d", &ele);
            append(ele);
        }
        else if(ch==2)
        {
           display();
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


void append(int new_data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
   
    temp->data = new_data;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        return;
    }
    else {
        struct Node* last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = temp;
        return;
    }

}

void display() {
    struct Node* ptr = head;
    printf("Link List Items : ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}