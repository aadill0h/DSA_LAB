struct max_arr_node{
    int capacity;
    int * arr;
};

void push_max(struct max_arr_node** array,int n){
    if((*array)->capacity==0){
        (*array)->capacity = 1;
        (*array)->arr = (int*)malloc((*array)->capacity *sizeof(int));
    }
    else{
        (*array)->capacity++;
        (*array)->arr=(int *)realloc((*array)->arr, (*array)->capacity * sizeof(int));
    }
    if((*array)->arr == NULL){
        printf("memory allocation failed");
        exit(1);
    }
    (*array)->arr[(*array)->capacity - 1] = n;
}

void level_max_helper(struct max_arr_node** array, struct node* root, int d ){
    if (root == NULL){
        return;
    }
    if(d == (*array)->capacity){
        push_max(array,root->num);
    }
    else{
        (*array)->arr[d] = max((*array)->arr[d], root->num);
    }
    level_max_helper((array),root->left,d+1);
    level_max_helper((array),root->right,d+1);

}



void levelmax(struct node *root) {
    struct max_arr_node *array = (struct max_arr_node *)malloc(sizeof(struct max_arr_node));
    array->capacity = 0;
    array->arr = NULL;

    level_max_helper(&array, root, 0);

    for (int i = 0; i < array->capacity; i++) {
        printf("%d ", array->arr[i]);
    }
    printf("\n");

    free(array->arr);
    free(array);
}