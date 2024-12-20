#include<stdio.h>

#define MAX 4
int queue[MAX];
int rear = -1;
int front = -1;

void insert(int n){
    if(rear == MAX-1){
        printf("Queue Overflow \n");
        return;
    }
    if(rear == -1){
        front = 0;
        rear = 0;
        queue[rear] = n;
    }
    else{
        rear = (rear + 1) % MAX;
        queue[rear] = n;
    }
    printf("Element inserted \n");
}

void deleteel(){
    if(front == -1 || front == rear){
        printf("Queue underflow \n");
        return;
    }
    int temp = queue[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front = (front + 1) % MAX;
    }
    printf("Deleted element is = %d \n",temp);
}

void display(){
    if(front == -1){
        printf("Queue is empty \n");
        return;
    }
    if(rear >= front){
        for(int i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
    }
    else{
        for(int i = front; i < MAX; i++){
            printf("%d ", queue[i]);
        }
        for(int i = 0; i <= rear; i++){
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main(){
    int k;

    k = 0;
    while(k != 4){
        printf("Enter your choice \n");
        printf("1.Insert \n 2. delete \n 3.Display \n 4.Exit \n");

        scanf("%d",&k);
        if(k == 1){
            printf("Enter the element to be inserted = ");
            int n;
            scanf("%d",&n);
            insert(n);
            continue;
        }
        else if(k == 2){
            deleteel();
            continue;
        }
        else if(k == 3){
            display();
            continue;
        }
        else if(k == 4){
            printf("Thank you");
            break;
        }
    }
    return 0;
}

/*
OUTPUT
Enter your choice 
1.Insert 
 2. delete 
 3.Display 
 4.Exit 
1
Enter the element to be inserted = 56
Element inserted 
Enter your choice 
1.Insert 
 2. delete 
 3.Display 
 4.Exit 
1
Enter the element to be inserted = 78
Element inserted 
Enter your choice 
1.Insert 
 2. delete 
 3.Display 
 4.Exit 
1
Enter the element to be inserted = 69
Element inserted 
Enter your choice 
1.Insert 
 2. delete 
 3.Display 
 4.Exit 
1
Enter the element to be inserted = 45
Element inserted 
Enter your choice 
1.Insert 
 2. delete 
 3.Display 
 4.Exit 
1
Enter the element to be inserted = 47
Queue Overflow 
Enter your choice 
1.Insert 
 2. delete
 3.Display
 4.Exit
3
56 78 69 45 
Enter your choice
1.Insert
 2. delete
 3.Display
 4.Exit
2
Deleted element is = 56 
Enter your choice
1.Insert
 2. delete
 3.Display
 4.Exit
2
Deleted element is = 78 
Enter your choice
1.Insert
 2. delete
 3.Display
 4.Exit
2
Deleted element is = 69 
Enter your choice
1.Insert
 2. delete
 3.Display
 4.Exit
2
Queue underflow 
Enter your choice
1.Insert
 2. delete
 3.Display
 4.Exit
3
45
Enter your choice 
1.Insert
 2. delete
 3.Display
 4.Exit
2
Queue underflow 
Enter your choice
1.Insert
 2. delete
 3.Display
 4.Exit
3
45 
Enter your choice
1.Insert
 2. delete
 3.Display
 4.Exit
4
Thank you
*/