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

void insert(struct node* node1, struct node* node2)
{
    node1->next = node2;
}



void loop_detector(struct node*head)
{
    struct node* temp;
    struct node* copy;
    while (temp!=NULL){
        copy =temp->next;
        while(copy!=NULL || copy!=temp){
            copy = copy->next;
            /*if (copy == temp){
                printf("loop present at %d",copy->num);
                break;
            }*/
        }
        if(copy!=NULL && copy==temp ){
            printf("loop is present at %d",copy->num);
            return;
        }

    }
    printf("no loop");
    return ;
}

void free_list(struct node* head){
    while(head!=NULL){
        struct node*temp =head;
        head =head->next;
        free(temp);
    }
}

int main()
{
    struct node* head1=createnode(10);
    struct node* head1_1=createnode(20);
    insert(head1,head1_1);
    insert(head1_1,head1);

    loop_detector(head1);

    free(head1);
    free(head1_1);



    return 1;
}
