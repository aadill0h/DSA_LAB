#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node* left;
    struct node* right;
};

struct node * createnode(int n){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL){
        printf("memory allocation failed");
        exit(1);
    }
    newnode->num = n;
    newnode->left = NULL;
    newnode->right =NULL;
}

void insert(struct node** root, int n){
    struct node* newnode;
    if (*root == NULL){
        *root = createnode(n);
        return;
    }
    if ((*root)->num == n){
        return ;
    }
    if ((*root)->num > n){
        insert(&(*root)->left,n);
    }
    else if((*root)->num < n){
        insert(&(*root)->right,n);
    }
}


void inorder(struct node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->num);
    inorder(root->right);
}

void freeall(struct node** root){
    if(*root == NULL){
        return ;
    }
    freeall(&(*root)->left);
    freeall(&(*root)->right);
    free(*root);
    return;
}

struct node* findmax(struct node* root){
    struct node* tempnode= root;
    while(tempnode->right != NULL){
        tempnode  = tempnode->right;
    }
    return tempnode;
}

void findPredecessor(struct node* root, struct node** pred, int key)
{
    // base case
    if (root == NULL)
    {
        *pred = NULL;
        return;
    }
    
    // if the root is our key node then the predecessor will be the largest node in its left subtree
    if (root->num == key)
    {
        if (root->left != NULL) {
            *pred = findmax(root->left);
        }
    }
 
    // if our key value is less than the root node value then we'll search in left subtree for key node
    else if (key < root->num) {
        findPredecessor(root->left, pred, key);
    }
 
    // if our key value is more than the root node value then we'll search in right subtree for key node
    else if (key > root->num) {
        // update predecessor to the current node before recursing in the right subtree
        *pred = root;
        findPredecessor(root->right, pred, key);
    }
    return;
}

int main(){
    struct node * root = NULL;
    struct node* pred;
    insert(&root,10);
    insert(&root,5);
    insert(&root,15);
    insert(&root,13);
    insert(&root,17);
    inorder(root);
    printf("\n");
    findPredecessor(root, &pred ,17);
    printf("%d",(pred)->num);
    return 1;

}