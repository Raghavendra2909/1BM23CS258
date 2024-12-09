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

struct node* reverse(struct node* start){
    struct node* prev = NULL;
    struct node* current = start;
    struct node* next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

struct node* concatenate(struct node* start1, struct node* start2){
    if(start1 == NULL) return start2;
    if(start2 == NULL) return start1;
    struct node* temp = start1;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = start2;
    return start1;
}

struct node* sort(struct node* start){
    struct node* a = start;
    struct node* b;
    while(a != NULL){
        b = a->next;
        while(b != NULL){
            if(a->data > b->data){
                int temp = a->data;
                a->data = b->data;
                b->data = temp;
            }
            b = b->next;
        }
        a = a->next;
    }
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
int main(){
    start1 = create(start1);
    display(start1);
    start2 = create(start2);
    display(start2);
    start1= concatenate(start1,start2);
    display(start1);
    start1 = sort(start1);
    display(start1);
    start1 = reverse(start1);
    display(start1);
}
/*
Enter the values for linked list:
1
Enter the next value for linked list (-1 to stop):
4
Enter the next value for linked list (-1 to stop):
2
Enter the next value for linked list (-1 to stop):
3
Enter the next value for linked list (-1 to stop):
7
Enter the next value for linked list (-1 to stop):
-1
1-> 4-> 2-> 3-> 7-> NULL 
Enter the values for linked list:
4
Enter the next value for linked list (-1 to stop):
6
Enter the next value for linked list (-1 to stop):
7
Enter the next value for linked list (-1 to stop):
9
Enter the next value for linked list (-1 to stop):
2 
Enter the next value for linked list (-1 to stop):
-1
4-> 6-> 7-> 9-> 2-> NULL 
1-> 4-> 2-> 3-> 7-> 4-> 6-> 7-> 9-> 2-> NULL
1-> 2-> 2-> 3-> 4-> 4-> 6-> 7-> 7-> 9-> NULL
9-> 7-> 7-> 6-> 4-> 4-> 3-> 2-> 2-> 1-> NULL
*/
