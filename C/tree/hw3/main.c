#include <stdio.h>
#include "./lib/base.h"
#include "./lib/algobase.h"
#define ElementType i32

i32 nodes[1000] = {0};
i32 length = 0;
typedef struct Node* tree;
typedef struct Node{
    ElementType data;
    tree left;
    tree right; 
} Node;
void commandList()
{
    printf("(1) Read dataset\n");
    printf("(2) Insert a new node (storing IDs) into the BST\n");
    printf("(3) Delete a node with a given value fomr the BST (If thd node does not exist, print not found)\n");
    printf("(4) Search for a node with a specific value in the BST (If th node does not exist, print not found)\n");
    printf("(5) Perform an in-order traversal of the BST (Print the values of the nodes in ascending order)\n");
    printf("(6) Compute balance factor of a specfic node\n");
    printf("(7) Find the k-th Smallest Element\n");
    printf("(8) Exit\n");
}
void init(tree *t)
{
    *t = NULL;
}
Status read(char *filename)
{
    FILE *file;
    file = fopen(filename,"r");
    if(file == NULL){
        perror("Error Opening file\n");
        return ERROR;
    }
    i32 i = 0;
    while(fscanf(file,"%d",&nodes[i]) != EOF){
        i++;
    }
    length = i;
    fclose(file);
    return OK;
}
Status tree_empty(tree t)
{
    if(t)
        return FALSE;
    else
        return TRUE;
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
void InOrderTraverse(tree T)
{
    if(!T)
        return;
    InOrderTraverse(T->left);
    printf(" %d",T->data);
    InOrderTraverse(T->right);
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
int main() {
    tree t;
    u8 command = 0;
    while(command != 8){
        commandList();
        scanf(" %d", &command);
        getchar();
        switch(command){
            case 1:
                char filename[100];
                printf("input file path: ");
                scanf(" %s", filename);
                read(filename);
                init(&t);
                for(i32 i = 0; i < length; i++)
                    insert_node(&t, nodes[i]);   
                break;
            case 2:
                printf("input ID: ");
                ElementType ikey;
                scanf(" %d", &ikey);
                insert_node(&t, ikey);
                break;
            case 3:
                printf("input ID: ");
                ElementType dkey;
                scanf(" %d", &dkey);
                if(!delete_tree(&t, dkey))
                    printf("delete %d failed\n", dkey);
                break;
            case 4:
                printf("input ID: ");
                ElementType skey;
                scanf(" %d", &skey);
                if(recur_search(t, skey))
                    printf("find it\n");
                else
                    printf("not found\n");
                break;
            case 5:
                InOrderTraverse(t);
                printf("\n");
                break; 
            case 8:
                clear_tree(&t);
                if(!tree_empty(t))
                    printf("tree clear failed\n");
                break;
            default:
                break;
        } 
    }
    return 0;
}