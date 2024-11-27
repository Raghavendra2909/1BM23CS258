#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *start = NULL;

// creation of linked list

struct node *create(struct node *start)
{
    int data;
    scanf("%d", &data);
    while (data != -1)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = data;
        if (start == NULL)
        {
            start = new_node;
            new_node->next = NULL;
            new_node->prev = NULL;
        }
        else
        {
            struct node *temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev = temp;
            new_node->next = NULL;
        }
        scanf("%d", &data);
    }
    return start;
}

// insertion at the left of the dll
struct node *insert_left(struct node *start, int data, int val)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    if (start == NULL)
    {
        start = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
        return start;
    }
    struct node *temp = start;
    while (temp->next != NULL && temp->next->data != val)
    {
        temp = temp->next;
    }
    if (start->data == val)
    {
        temp = start;
        new_node->next = temp;
        temp->prev = new_node;
        start = new_node;
    }
    else if (temp->next == NULL)
    {
        printf("Invalid entry \n");
    }
    else
    {
        new_node->next = temp->next;
        temp->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
    }

    return start;
}

// deletion of particular node
struct node *delete_node(struct node *start, int val)
{
    if (start == NULL)
    {
        return start;
    }
    if (start->data == val)
    {
        struct node *temp = start;
        start = start->next;
        if (start != NULL)
        {
            start->prev = NULL;
        }
        free(temp);
        return start;
    }
    struct node *temp = start;
    while (temp->next != NULL && temp->next->data != val)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        return start;
    }
    struct node *del = temp->next;
    temp->next = temp->next->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp;
    }
    free(del);
    return start;
}

// display

void display(struct node *start)
{
    struct node *temp = start;
    while (temp != NULL)
    {
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf(" NULL \n");
}

int main()
{
    struct node *start = NULL;
    printf("Create the linked list: \n");
    printf("Enter the data to be inserted next press -1 to exit \n");
    start = create(start);
    printf("Linked list created \n");
    display(start);
    printf("Please enter your choice:\n"
           "1. Insert at the left\n"
           "2. Delete Node\n"
           "3. Display\n"
           "4. Exit\n");
    int choice;
    scanf("%d", &choice);
    while (choice != 4)
    {
        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted: ");
            int data;
            scanf("%d", &data);
            printf("Enter the val before whitch to be inserted \n");
            int val;
            scanf("%d", &val);
            start = insert_left(start, data, val);
            break;
        case 2:
            printf("Enter the value to be deleted  \n");
            scanf("%d", &val);
            start = delete_node(start, val);
            break;
        case 3:
            display(start);
            break;
        default:
            printf("Invalid choice\n");
        }
        scanf("%d",&choice);
    }
}

/*
Create the linked list: 
Enter the data to be inserted next press -1 to exit 
89
10
20
30
40
-1
Linked list created 
89-> 10-> 20-> 30-> 40->  NULL 
Please enter your choice:
1. Insert at the left
2. Delete Node
3. Display
4. Exit
1
Enter the data to be inserted: 45
Enter the val before whitch to be inserted 
20
3
89-> 10-> 45-> 20-> 30-> 40->  NULL 
2
Enter the value to be deleted  
30
3
89-> 10-> 45-> 20-> 40->  NULL 
4
*/
