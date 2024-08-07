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

int main() {
    struct node* root = NULL; // Initialize root to NULL
    struct node* x;
    int model_num, price;
    char name[255];
    char ch = 'i';
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
            case 'e':
                break;
        }
    }
    return 0;
}
