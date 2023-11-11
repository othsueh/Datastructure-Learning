#include "../lib/base.h"
#include "../lib/algobase.h"
#define ElementType i32
#define MAXSIZE 100
typedef struct Node* tree;
typedef struct Node{
    ElementType data;
    tree left;
    tree right; 
} Node;
void init(tree *t)
{
    *t = NULL;
}
Status tree_empty(tree t)
{
    if(t)
        return FALSE;
    else
        return TRUE;
}
Status create_tree(tree *t)
{
    *t = (tree)malloc(sizeof(Node));
    if(!*t)
        return ERROR;
    (*t)->data = 0;
    (*t)->left = NULL;
    (*t)->right = NULL; 
    return OK;
}
tree recur_search(tree t, ElementType key)
{
    if(tree_empty(t))
        return NULL;
    if(key == t->data)
        return t;
    else if(key < t->data)
        return recur_search(t->left, key);
    else
        return recur_search(t->right, key);
}
tree* search_min(tree *t)
{
    if(tree_empty(*t))
        return NULL;
    else if((*t)->left)
        return search_min(&((*t)->left));
    else
        return t;
}
tree *search_max(tree *t)
{
    if(tree_empty(*t))
        return NULL;
    else if((*t)->right)
        return search_max(&((*t)->right));
    else
        return t;
}
Status delete_tree(tree *t, ElementType key)
{
    if(tree_empty(*t))
        return ERROR;
    if(key == (*t)->data){
        if((*t)->left && (*t)->right){
            tree *min = search_min(&((*t)->right));
            (*t)->data = (*min)->data;
            return delete_tree(min, (*min)->data);
        }
        else{
            tree tmp = *t;
            if((*t)->left)
                *t = (*t)->left;
            else
                *t = (*t)->right;
            free(tmp);
        }
    }
    else if(key < (*t)->data)
        return delete_tree(&((*t)->left), key);
    else
        return delete_tree(&((*t)->right), key); 
    return OK;
}
tree iter_search(tree t, ElementType key)
{
    while(t){
        if(key == t->data) 
            return t;
        else if(key < t->data)
            t = t->left;
        else 
            t = t->right;
    }
    return NULL;
}
Status insert_node(tree *t, ElementType key)
{
    if(tree_empty(*t)){
        *t = (tree)malloc(sizeof(Node));
        if(tree_empty(*t))
            return ERROR;
        (*t)->data = key;
        (*t)->left = NULL;
        (*t)->right = NULL;
    }
    else if((*t)->data == key) 
        return ERROR;
    else if((*t)->data > key)
        insert_node(&(*t)->left, key);
    else
        insert_node(&(*t)->right, key);
    return OK;
}
void LevelOrderTraverse(tree T)
{
    i32 front = 0, rear = 0;
    tree queue[MAXSIZE];
    if(!T) 
        return;
    queue[rear++] = T; 
    while(front != rear){
        tree node = queue[front++];
        printf("%d ",node->data);
        if(node->left)
            queue[rear++] = node->left;
        if(node->right)
            queue[rear++] = node->right;
    }
    printf("\n");
}
Status clear_tree(tree *t)
{
    if(tree_empty(*t))
        return ERROR;
    if((*t)->left)
        clear_tree(&(*t)->left);
    if((*t)->right)
        clear_tree(&(*t)->right);
    free(*t);
    *t = NULL;
    return OK;
}


int main()
{
    tree t;
    init(&t);
    // create_tree(&t);
    i32 a[] = {11,1, 35, 2, 43, 6, 8, 10, 29, 17, 31, 56};
    for(szt i = 1; i <= a[0]; i++)
        insert_node(&t, a[i]);
    LevelOrderTraverse(t);
    i32 del[] = {3, 35, 11, 31};
    for(szt i=1; i <= del[0]; i++){
        if(delete_tree(&t, del[i]))
            printf("delete %d success\n", del[i]);
        else
            printf("delete %d failed\n", del[i]);
    }
    LevelOrderTraverse(t);
    clear_tree(&t);
    if(tree_empty(t))
        printf("clear tree success\n");
    return 0;
}