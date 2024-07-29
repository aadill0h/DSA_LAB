#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node* next;
};

struct node* createnode(int n) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("memory allocation failed\n");
        exit(1);
    }
    newnode->num = n;
    newnode->next = NULL;
    return newnode;
}

void insert(struct node** head, int n) {
    if (*head == NULL) {
        *head = createnode(n);
    } else {
        struct node* temp = *head;
        
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = createnode(n);
    }
}

void display(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct node* temp = head;
        while (temp != NULL) {
            printf("%d ", temp->num);
            temp = temp->next;
        }
        printf("\n");
    }
}

struct node* sort_merge(struct node** a, struct node** b) {
    struct node* temp_a = *a;
    struct node* temp_b = *b;
    struct node* copy;

    while(temp_a != NULL && temp_b != NULL){
        if(temp_a->num > temp_b->num){
            copy=temp_b;
            temp_b = temp_b->next;
            copy->next = temp_a;
            if(temp_a == *a){
                (*a)=copy;
            }
        }
        else{
            copy = temp_a;
            temp_a= temp_a->next;
            copy->next = temp_b;
        }

    }
    *b=NULL;   
}

void freelist(struct node* head) {
    while (head != NULL) {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
}

struct node* reverse_part(struct node* head,int k){
    if (!head){
        return NULL;
    }

    struct node* current = head;
    struct node* next = NULL;
    struct node* prev = NULL;
    int count = 0;

    while(count<k && current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != NULL){
        head->next = reverse_part(next, k);
    }

    return prev;
    
}

int main() {
    struct node* head = NULL; 
    


    display(head);
    printf("\n");
    head = reverse_part(head,3);
    display(head);
    
    freelist(head);
    return 0;
}