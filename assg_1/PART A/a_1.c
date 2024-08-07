#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    struct node* left;
    struct node* right;
};

struct node* createnode(int num){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL){
        printf("memeory allocation failed");
        exit(1);
    }
    newnode->num = num;
    newnode->left =NULL;
    newnode->right = NULL;
    return newnode;
}

void insert(struct node** root, int num){
    if ((*root) == NULL){
        (*root) = createnode(num);
        return;
    }
    if ((*root)->num == num){
        return ;
    }
    if ((*root)->num > num){
        insert(&(*root)->left, num );
    }
    else if((*root)->num < num){
        insert(&(*root)->right, num);
    }
}

struct node* search( struct node* root, int key){
    if((root) == NULL){
        printf("not found\n ");
        return NULL;
    }
    if((root)->num == key){
        return (root);
    }
    if ((root)->num > key){
        search(root->left , key);
    }
    else if (root->num < key){
        search(root->right , key);
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
        return;
    }
    freeall(&(*root)->left);
    freeall(&(*root)->right);
    free(*root);
    return;
}

struct node* successor_func(struct node* root ,struct node* key)
{
    struct node* temp =root;
    if(root == NULL){
        printf("NULL\n");
        return NULL;
    }
    if(key == NULL){
        printf("key does not exist\n ");
        return NULL;
    }
    while(root!=NULL){
        if( root->num > key->num){
            temp =root;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return temp;
}

int main()
{
    struct node* root = NULL;
    insert(&root,20);
    insert(&root,10);
    insert(&root,50);
    insert(&root,9);
    insert(&root,12);
    insert(&root,11);
    insert(&root,13);
    insert(&root,30);
    insert(&root,40);
    insert(&root,25);
    insert(&root,15);
    insert(&root,27);
    insert(&root,14);
    insert(&root,16);
    inorder(root);
    printf("\n");
    struct node* successor;struct  node* key;
    key = search(root,13);
    successor = successor_func(root,key);
    printf("%d",successor->num);
    return 1;
}

