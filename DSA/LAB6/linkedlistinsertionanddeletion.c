#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* start = NULL;

//creation of linked list
struct node* create(struct node* start){
    printf("Enter the values for linked list:\n");
    int val;
    scanf("%d",&val);
    while(val!=-1){
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->next = NULL;
        if(start == NULL){
            start = newnode;
        }
        else{
            struct node* temp = start;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newnode;
        }
        printf("Enter the next value for linked list (-1 to stop):\n");
        scanf("%d",&val);
    }
    return start;
}

//insertion at the beginning
struct node* insertatbeg(struct node* start){
    printf("Enter the val to be inserted at the beginning:\n");
    int val;
    scanf("%d",&val);
    struct node*temp = start;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data= val;
    newnode->next = temp;
    start = newnode;
    return start;
}

//insertion at the end of ll
struct node* insertend(struct node* start){
    int val;
    printf("Enter the val to be inserted at the end:\n");
    scanf("%d",&val);
    struct node*temp = start;
    while(temp->next !=NULL){
        temp = temp->next;
    }
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    temp->next = newnode;
    return start;
}

//insert at kth position of ll
struct node* insertatk(struct node* start,int k){
    int val;
    printf("Enter the val to be inserted at %dth posn \n",k);
    scanf("%d",&val);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    struct node*temp = start;
    while(k>1){
        k--;
        temp = temp->next;

    }
    newnode->next = temp->next;
    temp->next = newnode;
    return start;
}

void display(struct node* start)
{
   struct node* temp = start;
   while(temp != NULL){
    printf("%d-> ", temp->data);
    temp = temp->next;
   }
   printf("NULL \n");
}

//delete head
struct node* deletebeg(struct node*start){
    struct node* temp = start;
    start = start->next;
    free(temp);
    return start;
}
//delete at end
struct node* deleteend(struct node*start){
    struct node* temp = start;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    temp->next = NULL;
    return start;

}
//delete at kth posn
struct node* deletekpos(struct node*start , int k){
    struct node* temp = start;
    if(k==1){
        start = start->next;
    }
    else{
        while(k>2){
            k--;
            temp = temp->next;
        }
        temp->next = temp->next->next;

    }
    return start;
}


int main(){
    start = create(start);
    display(start);
    start=insertatbeg(start);
    display(start);
    start = insertend(start);
    display(start);
    start = insertatk(start,3);
    display(start);
    start = deletebeg(start);
    display(start);
    start = deleteend(start);
    display(start);
    start = deletekpos(start, 2);
    display(start);

}

/*
Enter the values for linked list:
1
Enter the next value for linked list (-1 to stop):
2
Enter the next value for linked list (-1 to stop):
3
Enter the next value for linked list (-1 to stop):
4
Enter the next value for linked list (-1 to stop):
5
Enter the next value for linked list (-1 to stop):
6
Enter the next value for linked list (-1 to stop):
-1
1-> 2-> 3-> 4-> 5-> 6-> NULL 
Enter the val to be inserted at the beginning:
45
45-> 1-> 2-> 3-> 4-> 5-> 6-> NULL 
Enter the val to be inserted at the end:
96
45-> 1-> 2-> 3-> 4-> 5-> 6-> 96-> NULL 
Enter the val to be inserted at 3th posn
5
45-> 1-> 2-> 5-> 3-> 4-> 5-> 6-> 96-> NULL 
1-> 2-> 5-> 3-> 4-> 5-> 6-> 96-> NULL
1-> 2-> 5-> 3-> 4-> 5-> 6-> NULL
1-> 5-> 3-> 4-> 5-> 6-> NULL
*/



