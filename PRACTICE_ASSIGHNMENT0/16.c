#include <stdio.h>

struct  queue{
    int size;
    int * arr;
};


int main(){
    struct queue*  q1;
    struct queue*  q2;

    q1->size=0;
    q1->arr = NULL;

    q2->size=0;
    q2->arr = NULL;


};

enqueue(struct queue * q, int n){
    q->size++;
    q->arr = (int *)realloc(q->arr, q->size * sizeof(int));
    if (q->arr == NULL){
        printf("memeory allocation failed!\n");
        exit(1);
    }
    q->arr[q->size-1] = n;
}

int dequeue(struct queue * q,int n){
    if (q->size = 0){
        printf("empty queue ");
        exit(0);
    }
    int temp = q->arr[q->size - 1];
    q->size--;
    q->arr = (int *)realloc(q->arr, q->size * sizeof(int));
    if(q->arr == NULL){
        printf("memeory allocation failed\n");
        exit(1);
    }
    return temp;
}

void push(struct queue *q1,struct queue *q2, int n){
    enqueue(q1,n);
    for(int i=0 ; i<q2->size;i++){
        enqueue(q1,dequeue(q2));
    }
    for(int i=0;i<q1->size; i++){

    }
}

void pop(struct )
