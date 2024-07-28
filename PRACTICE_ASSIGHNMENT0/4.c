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

void merge(struct node* a, struct node** b) {
    struct node* a_temp = a;
    struct node* b_temp = *b;

    struct node* a_next;
    struct node* b_next;

    while (a_temp != NULL && b_temp != NULL) {
        a_next = a_temp->next;
        b_next = b_temp->next;

        a_temp->next = b_temp;
        if (a_next == NULL) {
            break;
        }
        b_temp->next = a_next;

        a_temp = a_next;
        b_temp = b_next;
    }
    *b = b_temp;
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
        printf("1.ADD\n2.DISPLAY\n3.MERGE\n");
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
                merge(head1, &head2);
                display(head1);
                printf("\n");
                display(head2);
                break;
        }
    }
    freelist(head1);
    freelist(head2);
    return 0;
}
