#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int model_num;
    struct node* left;
    struct node* right;
    int price;
    char name[255];
};

struct node* createnode(int model_number, int model_price, char* model_name) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("memory allocation failed");
        exit(1);
    }
    newnode->model_num = model_number;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->price = model_price;
    strcpy(newnode->name, model_name);
    return newnode;
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

void add(struct node** root, struct node* node) {
    if ((*root) == NULL) {
        *root = node;
        return;
    }
    if ((*root)->model_num == node->model_num) {
        return;
    }
    if ((*root)->model_num > node->model_num) {
        add(&(*root)->left, node);
    } else if ((*root)->model_num < node->model_num) {
        add(&(*root)->right, node);
    }
}

void inorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d %s %d\n", root->model_num, root->name, root->price);
    inorder(root->right);
}

struct node* search(struct node* root , int model_n){
    if(root == NULL){
        return NULL;
    }
    if (root->model_num==model_n){
        return root;
    }
    if(model_n<root->model_num){
        search(root->left,model_n);
    }
    else{
        search(root->right, model_n);
    }
}

void preorder(struct node* root){
    if (root == NULL){
        return;
    }
    printf("%d %s %d\n",root->model_num, root->name, root->price);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root){
    if (root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d %s %d\n",root->model_num, root->name, root->price);

}

void modify(struct node* root, int model_n, int new_price){
    struct node*  n1 = search(root, model_n);
    if (n1 == NULL){
        printf("element not present in BST\n");
        return;
    }
    n1->price = new_price;
    return;
}

struct node* minval(struct node* root){
    struct node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

void delete(struct node** root, struct node* element){
    struct node* temp;
    if(*root == NULL){
        return;
    }
    if (element->model_num < (*root)->model_num){
        delete(&(*root),element);
    }
    else if(element->model_num > (*root)->model_num){
        delete(&(*root)->right, element);
    }
    else{
        if((*root)->left == NULL){
            temp=*root;
            *root = (*root)->right;
            free(temp);
        }
        else if ((*root)->right ==NULL){
            temp=*root;
            *root=(*root)->left;
            free(temp);
        }
        else{
            temp = minval((*root)->right);
            (*root)->model_num = temp->model_num;
            strcpy((*root)->name,temp->name);
            (*root)->price = temp->price;
            delete(&(*root)->right,temp);
        } 
    }
}


int main() {
    struct node* root = NULL; // Initialize root to NULL
    struct node* x;
    int model_num, price;
    char name[255];
    char ch = 'i';
    struct node* s ;
    while (ch != 'e') {
        printf("input choice: ");
        scanf(" %c", &ch); // Add space before %c to consume any leftover whitespace
        switch (ch) {
            case 'a':
                scanf("%d", &model_num);
                scanf("%s", name);
                scanf("%d", &price);
                x = createnode(model_num, price, name);
                add(&root, x);
                break;
            case 'i':
                inorder(root);
                break;
            case 't':
                postorder(root);
                break;
            case 'p':
                preorder(root);
                break;
            case 'm':
                int new_price;
                //printf("enter model number:");
                scanf("%d",&model_num);
                //printf("enter new price:");
                scanf("%d",&new_price);
                modify(root,model_num,new_price);
                break;
            case 's':
                scanf("%d",&model_num);
                s = search(root,model_num);
                if (s==NULL){
                    printf("-1\n");
                }
                else{
                    printf("%d %s %d\n",s->model_num,s->name,s->price);
                }
                break;
            case 'd':
                int model_num;
                scanf("%d",&model_num);
                s = search(root,model_num);
                if (s==NULL){
                    printf("-1\n");
                }
                else{
                    delete(&root,s);
                }
                break;
            case 'e':
                break;
        }
    }
    freeall(&root);
    return 0;
}
