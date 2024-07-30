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

void selectionSort(struct node* head) {
    if (head == NULL) {
        return;
    }

    struct node* current = head;
    while (current != NULL) {
        struct node* min = current;
        struct node* nextNode = current->next;

        while (nextNode != NULL) {
            if (nextNode->num < min->num) {
                min = nextNode;
            }
            nextNode = nextNode->next;
        }

        // Swap data
        if (min != current) {
            int temp = current->num;
            current->num = min->num;
            min->num = temp;
        }

        current = current->next;
    }
}


void freelist(struct node* head) {
    while (head != NULL) {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
}


int main() {
    struct node* head = NULL; 
    insert(&head,12);
    insert(&head,15);
    insert(&head,20);
    insert(&head,1);
    insert(&head,99);
    insert(&head,72);
    insert(&head,4);
    display(head);
    selectionSort(head);
    display(head);
    
    freelist(head);
    return 0;
}