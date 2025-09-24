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
int getCount();
void addFirst(int item);


int main() 
{
    // struct  Node* head = (struct Node*)malloc(sizeof(struct Node));
    head = (struct Node*)malloc(sizeof(struct Node));

    int ch, ele;
    while(1)
    {
        printf("1. Append \n");
        printf("2. Display List: \n");
        printf("3. GetCount: \n");
        printf("4. AddFirst: \n");
        printf("5. Exis: \n");
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
         else if(ch==3)
        {
            int count = getCount();
            printf("Total Item Count  %d: ",count);
           
        }
         else if(ch==4)
        {
            printf("Enter ele to Add at First Position  : ");
            scanf("%d", &ele);
            addFirst(ele);
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

int getCount() {
    struct Node* current = head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void addFirst(int item) {
    struct Node* temp = (struct Node*) malloc(sizeof (struct Node));
    temp->next = head;
    temp->data = item;
    head = temp;
}
