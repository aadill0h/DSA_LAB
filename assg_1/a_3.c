#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int num;
    struct node* left ;
    struct node*right;
};

struct node* createnode(int n){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL){
        printf("memory allocation failed");
        exit(1);
    }
    newnode->num = n;
    newnode->left =NULL;
    newnode->right = NULL;   
    return newnode;
}

void insert(struct node** root, int num){
    if (*root == NULL){
        *root = createnode(num);
        return;
    }
    if ((*root)->num == num){
        return;
    }    
    if((*root)->num > num){
        insert(&(*root)->left, num);
    }
    else if((*root)->num < num){
        insert(&(*root)->right, num);
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

void push(char **str, int *len, const char *suffix) {
    int suffix_len = strlen(suffix);  // Calculate the length of the suffix
    *str = (char *)realloc(*str, (*len + suffix_len + 1) * sizeof(char));  // Reallocate memory
    strcpy(*str + *len, suffix);  // Copy the suffix to the end of the current string
    *len += suffix_len;  // Update the length of the 
}


void treetostr(struct node * root,char ** str,int *len){
    if(root == NULL){
        return ;
    }
    char buffer[12];
    sprintf(buffer,"%d",root->num);

    push(str,len,buffer);
    if(root->left != NULL){
        push(str, len, "(");
        treetostr(root->left, str, len);
        push(str, len, ")");
    }
    if (root->right != NULL){
        push(str,len,"(");
        treetostr(root->right,str, len );
        push(str,len,")");
    }
}

int main(){
    char * str;
    int len;
    struct node* root = createnode(20);
    root->left = createnode(10);
    root->right =createnode(15);
    root->left->left=createnode(11);
    root->left->right=createnode(14);
    treetostr(root,&str,&len);
    printf("%s",str);
    return 1;
    }