#include <stdio.h>
#include <stdlib.h>

// Node structure for binary tree
struct node {
    int num;
    struct node* left;
    struct node* right;
};

// Node structure for linked list to store levels
struct arr_node {
    int n;
    struct arr_node* next;
};

// Function to create a new tree node
struct node* createnode(int num) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->num = num;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Function to create a new linked list node
struct arr_node* create_arrnode(int n) {
    struct arr_node* newnode = (struct arr_node*)malloc(sizeof(struct arr_node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->n = n;
    newnode->next = NULL;
    return newnode;
}

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a >= b) ? a : b;
}

// Function to free all nodes in the binary tree
void freeall(struct node** root) {
    if (*root == NULL) {
        return;
    }
    freeall(&(*root)->left);
    freeall(&(*root)->right);
    free(*root);
}

// Function to push an element into the linked list
void push(struct arr_node** head, int n) {
    struct arr_node* newnode = create_arrnode(n);
    if (*head == NULL) {
        *head = newnode;
    } else {
        struct arr_node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Function to get the levels of the tree
int levelsoftree(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(levelsoftree(root->left), levelsoftree(root->right));
}

// Function to display nodes at the nth level in reverse order
void nthLevelRev_display(struct node* root, int n, int level, struct arr_node** arr_root) {
    if (root == NULL) {
        return;
    }
    if (n == level) {
        push(arr_root, root->num);
        return;
    }
    nthLevelRev_display(root->right, n + 1, level, arr_root);
    nthLevelRev_display(root->left, n + 1, level, arr_root);
}

// Function to display nodes at the nth level in normal order
void nthLevel_display(struct node* root, int n, int level, struct arr_node** arr_root) {
    if (root == NULL) {
        return;
    }
    if (n == level) {
        push(arr_root, root->num);
        return;
    }
    nthLevel_display(root->left, n + 1, level, arr_root);
    nthLevel_display(root->right, n + 1, level, arr_root);
}

// Function to free the linked list
void free_arr(struct arr_node* head) {
    while (head != NULL) {
        struct arr_node* temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to perform zigzag level order traversal of the binary tree
void zigzag(struct node* root) {
    int level = levelsoftree(root);
    struct arr_node* ans = NULL;
    for (int i = 1; i <= level; i++) {
        if (i % 2 == 0) {
            nthLevel_display(root, 1, i, &ans);
        } else {
            nthLevelRev_display(root, 1, i, &ans);
        }
    }
    struct arr_node* temp = ans;
    while (temp != NULL) {
        printf("%d ", temp->n);
        temp = temp->next;
    }
    printf("\n");
    free_arr(ans);
}

// Function to find the index of a value in the inorder array
int search(int arr[], int strt, int end, int value) {
    for (int i = strt; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Recursive function to construct the binary tree
struct node* buildTree(int inorder[], int preorder[], int inorderStart, int inorderEnd, int* preorderIndex) {
    if (inorderStart > inorderEnd)
        return NULL;

    struct node* treeNode = createnode(preorder[*preorderIndex]);
    (*preorderIndex)++;

    if (inorderStart == inorderEnd)
        return treeNode;

    int inorderIndex = search(inorder, inorderStart, inorderEnd, treeNode->num);

    treeNode->left = buildTree(inorder, preorder, inorderStart, inorderIndex - 1, preorderIndex);
    treeNode->right = buildTree(inorder, preorder, inorderIndex + 1, inorderEnd, preorderIndex);

    return treeNode;
}

void printInorder(struct node* node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->num);
    printInorder(node->right);
}

void PostOrder(struct node* node){
    if(node == NULL){
        return;
    }
    PostOrder(node->left);
    PostOrder(node->right);
    printf("%d ",node->num);
}

//level max
struct max_arr_node{
    int capacity;
    int * arr;
};

void push_max(struct max_arr_node** array,int n){
    if((*array)->capacity==0){
        (*array)->capacity = 1;
        (*array)->arr = (int*)malloc((*array)->capacity *sizeof(int));
    }
    else{
        (*array)->capacity++;
        (*array)->arr=(int *)realloc((*array)->arr, (*array)->capacity * sizeof(int));
    }
    if((*array)->arr == NULL){
        printf("memory allocation failed");
        exit(1);
    }
    (*array)->arr[(*array)->capacity - 1] = n;
}

void level_max_helper(struct max_arr_node** array, struct node* root, int d ){
    if (root == NULL){
        return;
    }
    if(d == (*array)->capacity){
        push_max(array,root->num);
    }
    else{
        (*array)->arr[d] = max((*array)->arr[d], root->num);
    }
    level_max_helper((array),root->left,d+1);
    level_max_helper((array),root->right,d+1);

}

void levelmax(struct node *root) {
    struct max_arr_node *array = (struct max_arr_node *)malloc(sizeof(struct max_arr_node));
    array->capacity = 0;
    array->arr = NULL;

    level_max_helper(&array, root, 0);

    for (int i = 0; i < array->capacity; i++) {
        printf("%d ", array->arr[i]);
    }
    printf("\n");

    free(array->arr);
    free(array);
}

//diameter
int diameter(struct node* root){
    if ( root == NULL){
        return 0;
    }
    int left_height = levelsoftree(root->left);
    int right_height = levelsoftree(root->right);

    int left_diameter = diameter(root->left);
    int right_diameter = diameter(root->right);

    return max(left_height + right_height +1,max(left_diameter,right_diameter));
}

struct queue{
    struct node* data;
    struct queue* next;
};

struct queue* createque(struct node* data){
    struct queue* newnode = (struct queue*)malloc(sizeof(struct queue));
    if (newnode ==NULL ){
        printf("queue memory allocation failed");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void enqueue(struct queue** q_head,struct node* data){
    if((*q_head)==NULL){
        *q_head = createque(data);
        return;
    }
    struct queue* temp = *q_head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = createque(data);
    return;
}


struct node* dequeue(struct queue** q_head) {
    if (*q_head == NULL) {
        return NULL;
    }
    struct queue* temp = *q_head;
    struct node* data = temp->data;
    *q_head = (*q_head)->next;
    free(temp);
    return data;
}
int isempty(struct queue* q_head){
    if(q_head == NULL){
        return 1;
    }
    return 0;
}
int rightleafsum(struct node* root) {
    struct queue* q_head = NULL;
    int sum = 0;
    enqueue(&q_head, root);
    while (!isempty(q_head)) {
        struct node* curr = dequeue(&q_head);
        if (curr->left != NULL) {
            enqueue(&q_head, curr->left);
        }
        if (curr->right != NULL) {
            if (curr->right->right == NULL && curr->right->left == NULL) {
                sum += curr->right->num;
            }
            enqueue(&q_head, curr->right);
        }
    }
    return sum;
}

int main() {
    int n;
    scanf("%d",&n);
    int inorder[n],preorder[n];
    printf("inorder:");
    for(int i=0;i<n;i++){
        scanf("%d",&inorder[i]);
    }
    printf("preorder:");
    for(int i = 0; i < n; i++){
        scanf("%d",&preorder[i]);
    }
    int preorderIndex = 0;
    struct node* root = buildTree(inorder, preorder, 0, n - 1, &preorderIndex);


    char  ch ='p';
    while( ch!='e'){
        scanf("%c",&ch);
        switch(ch){
            case 'p':
                PostOrder(root);
                printf("\n");
                break;
            case 'z':
                zigzag(root);
                break;
            case 'm':
                levelmax(root);
                break;
            case 'd':
                printf("%d\n",diameter(root));
                break;
            case 's':
                printf("%d\n",rightleafsum(root));
                break;
            case 'e':
                break;
        }
    }
    freeall(&root);
    return 1;
    
}


