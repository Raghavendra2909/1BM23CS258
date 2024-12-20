#include<stdio.h>
//stack operations;
int n;
int stack[20];
int top=-1;
void push(int x){
    if(top<=(n-1)){
        top++;
        stack[top]=x;
    }
    else{
        printf("Stack Overflow \n");
    }
}
void pop(){
    if(top>=0 ){
        int a = stack[top];
        stack[top]=0;
        printf("Deleted element is %d",a);
        top--;
    }
    else{
        printf("Stack Underflow");
    }
}
void display(){
    for(int i=0; i<=top; i++){
        printf("%d",stack[i]);
    }
}

void main(){
    int choice,num;
    printf("Enter the size");
    scanf("%d",&n);
    printf("Enter the choice \n");
    printf("1.Push \n 2.POP \n 3.Display \n 4.Exit \n");
    scanf("%d",&choice);
    while(choice<4){
        if(choice==1){
            printf("Enter the number to push");
            scanf("%d",&num);
            push(num);
        }
        else if(choice == 2){
            pop();
        }
        else if(choice ==3){
            display();
        }
        else{
            break;
        }
        printf(" \n Enter the choice \n");
        scanf("%d",&choice);
    }
}
