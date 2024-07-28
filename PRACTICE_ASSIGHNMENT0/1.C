#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node* next;
};

struct node* createnode(int n)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL){
        printf("memory allocation failed\n");
        exit(1);
    }
    newnode->num = n;
    newnode->next = NULL;
    return newnode;
}

void insert(struct node** head, int n)
{
    if(*head == NULL){
        *head = createnode(n);
    }
    else{
        struct node* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next=createnode(n);
    }
}

void delete(struct node** head, int n)
{
    if (*head == NULL){
        printf("empty LLS\n");
        return;
    }
    else{
        struct node* temp = *head;
        struct node* prev =NULL;
        while(temp->next!=NULL){
            if(temp->num == n){
                if (prev == NULL){
                    *head = (*head)->next;
                    break;
                }
                else{
                    prev->next = temp->next;
                    break;
                }
            }
            prev = temp;
            temp = temp->next;
        }
    }
}

void display(struct node* head)
{
    if(head == NULL){
        printf("emprty\n");
    }
    else{
        struct node* temp=head;
        while(temp != NULL){
            printf("%d ",temp->num);
            temp = temp->next;
        }
        printf("/n");
    }
}

void reverse(struct node** head){
    struct node* prev = NULL;
    struct node* temp = *head;
    struct node* next_node = (*head)->next;

    while(temp!=NULL){
        if(next_node == NULL){
            temp->next =prev;
            (*head)=temp;
            temp = next_node;
        }
        else{
            temp->next = prev;
            prev = temp;
            temp = next_node;
            next_node = next_node->next;
        }
    }
}

int main()
{
    struct node* head;
    int ch=1;
    int n;
    do{
        printf("1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT5\n5.reverse\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("enter numebr to inserrt");
                scanf("%d",&n);
                insert(&head,n);
                break;
            case 2:
                scanf("%d",&n);
                delete(&head,n);
                break;
            case 3:
                display(head);
                break;
            case 4:
                break;
            case 5:
                reverse(&head);
                display(head);
                break;
        }
    }while(ch!=4);

    while(head!=NULL){
        struct node*temp =head;
        head =head->next;
        free(temp);
    }
    return 1;
}
