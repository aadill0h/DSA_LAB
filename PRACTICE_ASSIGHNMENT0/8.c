#include <stdio.h>
#include <stdlib.h>

struct stack{
    int * arr;
    int size;
};

void push(struct stack* stack1, int n){
    stack1->size++;
    stack1->arr = (int *)realloc(stack1->arr, stack1->size * sizeof(int));
    if (stack1->arr == NULL){
        printf("memeory allocation failed!\n");
        exit(1);
    }
    for (int i=stack1->size-1; i>0; i--){
        stack1->arr[i] = stack1->arr[i-1];
    }
    stack1->arr[0] = n;
}

void pop(struct stack* stack1){
    if (stack1->size == 0){
        printf("stack empty\n");
        return ;
    }
    int temp = stack1->arr[0];
    for(int i=0; i<stack1->size; i++){
        stack1->arr[i] = stack1->arr[i+1];        
    }
    printf("%d\n",temp);
    stack1->size--;
    stack1->arr = (int *)realloc( stack1->arr , stack1->size * sizeof(int));
    if(stack1->size > 0 && stack1->arr ==NULL){
        printf("memory allocation failed");
        exit(1);
    }
    return;
}

void peek(struct stack* stack1) {
    if (stack1->size == 0) {
        printf("Stack is empty\n");
    } else {
        printf("%d\n", stack1->arr[0]);
    }
}

void display(struct stack *stack1) {
    if (stack1->size == 0) {
        printf("Stack is empty\n");
    } else {
        for (int i = 0; i < stack1->size; i++) {
            printf("%d ", stack1->arr[i]);
        }
        printf("\n");
    }
}

void freeStack(struct stack *stack1) {
    free(stack1->arr);
}



int main() {
    struct stack* stack1 ;
    stack1->size = 0;
    stack1->arr = NULL;
    int choice, value;

    do {
        printf("1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. EXIT\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to push: ");
                scanf("%d", &value);
                push(stack1, value);
                break;
            case 2:
                pop(stack1);
                break;
            case 3:
                peek(stack1);
                break;
            case 4:
                display(stack1);
                break;
            case 5:
                freeStack(stack1);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 5);

    return 0;
}