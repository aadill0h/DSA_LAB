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

int main(){
    struct node* head1,head2;
    int ch=1;
    int list_num;
    int n;
    while(ch!=4){
        scanf("%d",&ch);
        switch(ch){
            case 1:
                scanf("%d",&list_num);
                scanf("%d",&n);
                if(list_num == 1){
                    insert(&head1,n)
                }
                else if(list_num == 2){
                    insert(&head2,num);
                }
            case 2:

        }
    }
}
