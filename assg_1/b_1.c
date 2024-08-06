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

// Function to insert a number into the binary tree
void insert(struct node** root, int num) {
    if (*root == NULL) {
        *root = createnode(num);
        return;
    }
    if ((*root)->num == num) {
        return;
    }
    if ((*root)->num > num) {
        insert(&(*root)->left, num);
    } else {
        insert(&(*root)->right, num);
    }
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

int main() {
    struct node* root = NULL;
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 8);
    insert(&root, 1);
    insert(&root, 4);
    insert(&root, 7);
    insert(&root, 9);

    printf("Zigzag Level Order Traversal: \n");
    zigzag(root);
    return 1;
}

