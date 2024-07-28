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
        printf("empty\n");
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

int main() {
    struct node* head1 = NULL; 
    struct node* head2 = NULL; 
    int ch = 1;
    int list_num;
    int n;
    while (ch != 4) {
        printf("1.ADD 2.DISPLAY 3.MERGE  \n");
        printf("choice:");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("list:");
                scanf("%d", &list_num);
                scanf("%d", &n);
                if (list_num == 1) {
                    insert(&head1, n);
                } else if (list_num == 2) {
                    insert(&head2, n);
                }
                break;
            case 2:
                scanf("%d", &list_num);
                if (list_num == 1) {
                    display(head1);
                } else if (list_num == 2) {
                    display(head2);
                }
                break;
            case 3:
                sort_merge(&head1, &head2);
                display(head1);
                break;

        }
    }
    freelist(head1);
    return 0;
}
