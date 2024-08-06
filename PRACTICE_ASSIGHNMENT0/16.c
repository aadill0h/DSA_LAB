#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int n;
    struct StackNode* next;
};

void Display(struct StackNode* top) {
    if (top == NULL) {
        printf("empty\n");
        return;
    }
    while (top != NULL) {
        printf("%d ", top->n);
        top = top->next;
    }
}

struct StackNode* createNode(int num) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->n=num;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct StackNode** top, int num) {
    struct StackNode* newNode = createNode(num);
    
 }

void pop(struct StackNode** top) {
    if (*top == NULL) {
        printf("empty\n");
        return;
    }
    struct StackNode* temp = *top;
    *top = (*top)->next;
    printf("%d\n", temp->n);
    free(temp);
}

void peek(struct StackNode* top){
    if (top == NULL ){
        printf("empty\n");
        return;
    }
    printf("%d\n",top->n);
    return;
}