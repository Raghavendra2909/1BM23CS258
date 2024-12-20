<<<<<<< HEAD
#include<stdio.h>
#include<malloc.h>

//Binary tree creation traversal and insertion
struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    else{
        if (data <= root->data) {
            if (root->left == NULL) {
                root->left = createNode(data);
                return root;
            }
            else{
                root->left = insert(root->left, data);
                return root;
            }
        }
        else{
            if (root->right == NULL) {
                root->right = createNode(data);
                return root;
            }
            else{
                root->right = insert(root->right, data);
                return root;
            }
        }
    }
}

//inorder traversal
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf(" %d", root->data);
        inorder(root->right);
    }
   
}

//postorder traversal
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf(" %d", root->data);
    }
    
}

//preorder traversal
void preorder(struct node* root) {
    if (root != NULL) {
        printf(" %d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
   
}
/// @return 
int main(){
    struct node* root = NULL;
    root = insert(root,50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root,58);
    root = insert(root, 42);
    printf(" \n Inorder: ");
    inorder(root);
    printf("\n Postorder: ");
    postorder(root);
    printf(" \n Preorder: ");
    preorder(root);
    return 0;
=======
#include<stdio.h>
#include<malloc.h>

//Binary tree creation traversal and insertion
struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    else{
        if (data <= root->data) {
            if (root->left == NULL) {
                root->left = createNode(data);
                return root;
            }
            else{
                root->left = insert(root->left, data);
                return root;
            }
        }
        else{
            if (root->right == NULL) {
                root->right = createNode(data);
                return root;
            }
            else{
                root->right = insert(root->right, data);
                return root;
            }
        }
    }
}

//inorder traversal
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf(" %d", root->data);
        inorder(root->right);
    }
   
}

//postorder traversal
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf(" %d", root->data);
    }
    
}

//preorder traversal
void preorder(struct node* root) {
    if (root != NULL) {
        printf(" %d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
   
}
/// @return 
int main(){
    struct node* root = NULL;
    root = insert(root,50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root,58);
    root = insert(root, 42);
    printf(" \n Inorder: ");
    inorder(root);
    printf("\n Postorder: ");
    postorder(root);
    printf(" \n Preorder: ");
    preorder(root);
    return 0;
>>>>>>> 764cd599522ed33f47914d1668d8dc8dc51f31d0
}