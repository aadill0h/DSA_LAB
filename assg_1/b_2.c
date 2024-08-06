#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int model_num;
    struct node* left;
    struct node* right;
    int price;
    char name[255];
};


struct node* createnode(int model_number,int model_price ,char * model_name){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL){
        printf("memeory allocation failed");
        exit(1);
    }
    newnode->model_num = num;
    newnode->left =NULL;
    newnode->right = NULL;
    newnode->price = model_price;
    strcpy(newnode->name,model_name);
    return newnode;
}

int max(int a,int b){
    if(a>=b){
        return a;
    }
    else{
        return b;
    }
}

void add(struct node** root, struct node* node){
    if ((*root) == NULL){
        (*root) = node;
        return;
    }
    if ((*root)->model_num == node->model_num){
        return ;
    }
    if ((*root)->model_num > node->model_num){
        add(&(*root)->left, node );
    }
    else if((*root)->model_num < node->model_num){
        add(&(*root)->right, node);
    }
}


