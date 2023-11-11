#include "../lib/base.h"
#include "../lib/algobase.h"
#define ElementType i32
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
tree search(tree t, ElementType key)
{
    if(tree_empty(t))
        return NULL;
    if(key == t->data)
        return t;
    else if(key < t->data)
        return search(t->left, key);
    else
        return search(t->right, key);
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


int main()
{
    tree t;
    init(&t);
    create_tree(&t);
    return 0;
}