#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

void push(struct StackNode** top, int num) {
    struct StackNode* newNode = createNode(num);
    newNode->next = *top;
    *top = newNode;
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

int main()
{
    struct StackNode* top;
    int ch=1;
    int n;
    do{
        printf("1.PSUH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("enter numebr to inserrt");
                scanf("%d",&n);
                push(&top,n);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                peek(top);
                break;
            case 4:
                Display(top);
                break;
            case 5: 
                break;
        }
    }while(ch!=5);

    while(top!=NULL){
        struct StackNode*temp = top;
        top =top->next;
        free(temp);
    }
    return 1;
}
