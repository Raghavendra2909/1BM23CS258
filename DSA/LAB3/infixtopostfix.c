<<<<<<< HEAD
#include<stdio.h>
#include<string.h>

char infix[20];
int pos = -1; 
char postfix[20];
char result[20];

void push(char a) {
    pos++;
    postfix[pos] = a;
}

char pop() { 
    char temp = postfix[pos];
    postfix[pos] = 0; 
    pos--;
    return temp;
}

int precedence(char c) {
    if(c == '+' || c == '-') {
        return 1;
    } else if(c == '*' || c == '/') {
        return 2;
    } else if(c == '^') {
        return 3;
    }
    return 0; 
}

void infixtoPostfix() {
    int resind = 0;
    push('(');
    int index = 0;
    int len = strlen(infix);
    infix[len] = ')';
    len++;

    while(index < len) {
        if(infix[index] == '(') {
            push('(');
        } else if(infix[index] == ')') {
            while(postfix[pos] != '(') {
                char temp = pop();
                result[resind] = temp;
                resind++;
            }
            pop(); 
        } else if(infix[index] == '+' || infix[index] == '-' || infix[index] == '*' || infix[index] == '/' || infix[index] == '^') {
            while(pos >= 0 && precedence(infix[index]) <= precedence(postfix[pos])) {
                char temp = pop();
                result[resind] = temp;
                resind++;
            }
            push(infix[index]);
        } else {
            result[resind] = infix[index]; 
            resind++;
        }
        index++;
    }
    result[resind] = '\0'; 
}

int main() { 
    printf("Enter the value infix exp: ");
    scanf("%s", infix); 
    infixtoPostfix();
    printf("Postfix expression: ");
    for(int i = 0; i < strlen(result); i++) {
        printf("%c", result[i]); 
    }
    printf("\n");
    return 0; 
}
=======
#include<stdio.h>
#include<string.h>

char infix[20];
int pos = -1; 
char postfix[20];
char result[20];

void push(char a) {
    pos++;
    postfix[pos] = a;
}

char pop() { 
    char temp = postfix[pos];
    postfix[pos] = 0; 
    pos--;
    return temp;
}

int precedence(char c) {
    if(c == '+' || c == '-') {
        return 1;
    } else if(c == '*' || c == '/') {
        return 2;
    } else if(c == '^') {
        return 3;
    }
    return 0; 
}

void infixtoPostfix() {
    int resind = 0;
    push('(');
    int index = 0;
    int len = strlen(infix);
    infix[len] = ')';
    len++;

    while(index < len) {
        if(infix[index] == '(') {
            push('(');
        } else if(infix[index] == ')') {
            while(postfix[pos] != '(') {
                char temp = pop();
                result[resind] = temp;
                resind++;
            }
            pop(); 
        } else if(infix[index] == '+' || infix[index] == '-' || infix[index] == '*' || infix[index] == '/' || infix[index] == '^') {
            while(pos >= 0 && precedence(infix[index]) <= precedence(postfix[pos])) {
                char temp = pop();
                result[resind] = temp;
                resind++;
            }
            push(infix[index]);
        } else {
            result[resind] = infix[index]; 
            resind++;
        }
        index++;
    }
    result[resind] = '\0'; 
}

int main() { 
    printf("Enter the value infix exp: ");
    scanf("%s", infix); 
    infixtoPostfix();
    printf("Postfix expression: ");
    for(int i = 0; i < strlen(result); i++) {
        printf("%c", result[i]); 
    }
    printf("\n");
    return 0; 
}
>>>>>>> 764cd599522ed33f47914d1668d8dc8dc51f31d0
