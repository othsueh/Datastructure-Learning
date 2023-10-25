#include "../lib/base.h"
#include "../lib/algobase.h"
#define MAXSIZE 100
typedef char ElemType;
typedef char String[24];
typedef struct BiTNode *BiTree;
typedef struct BiTNode
{
    ElemType data;
    BiTree lchild, rchild;
} BiTNode;
String str;
i32 treeIndex = 1;
ElemType Nil = ' ';
Status StrAssign(String T, char *chars)
{
    if(strlen(chars) > MAXSIZE)
        return ERROR;
    else
    {
        T[0] = strlen(chars);
        for(szt i = 1; i <= T[0];i++){
            T[i] = *(chars + i - 1);
        }
        return OK;
    }
}
Status InitBiTree(BiTree *T)
{
    *T = NULL;
    return OK;
}
Status CreateBiTree(BiTree *T)
{
    ElemType ch = str[treeIndex++];
    if(ch == '#')
        *T = NULL;
    else{
        *T = (BiTree) malloc(sizeof(BiTNode));
        if(!*T)
            exit(ERROR);
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
    return OK;
}
Status BiTreeEmpty(BiTree T)
{
    if(T)
        return FALSE;
    else 
        return TRUE;
}
Status BiTreeDepth(BiTree T)
{
    i32 i, j;
    if(!T)
        return 0;
    if(T->lchild)
        i = BiTreeDepth(T->lchild);
    else
        i = 0;
    if(T->rchild)
        j = BiTreeDepth(T->rchild);
    else 
        j = 0;
    return i > j ? i + 1 : j + 1;
}
void PreOrderTraverse(BiTree T)
{
    if(!T)
        return;
    printf("%c",T->data); 
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}
void InOrderTraverse(BiTree T)
{
    if(!T)
        return;
    InOrderTraverse(T->lchild);
    printf("%c",T->data);
    InOrderTraverse(T->rchild);
}
void InOrderTraverseIter(BiTree T)
{
    i32 top = -1;
    BiTree stack[MAXSIZE];
    BiTree node = T;
    while(1){
        for(;node;node = node->lchild)
            stack[++top] = node;
        node = stack[top--];
        if(!node)
            break;
        printf("%c",node->data);
        node = node->rchild;
    }
}
void PostOrderTraverse(BiTree T)
{
    if(!T)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c",T->data);
}
void LevelOrderTraverse(BiTree T)
{
    i32 front = 0, rear = 0;
    BiTree queue[MAXSIZE];
    if(!T) 
        return;
    queue[rear++] = T; 
    while(front != rear){
        BiTree node = queue[front++];
        printf("%c",node->data);
        if(node->lchild)
            queue[rear++] = node->lchild;
        if(node->rchild)
            queue[rear++] = node->rchild;
    }
}
void ClearBiTree(BiTree *T)
{
    if(*T){
        if((*T)->lchild)
            ClearBiTree(&(*T)->lchild);
        if((*T)->rchild)
            ClearBiTree(&(*T)->rchild);
        free(*T);
        *T = NULL;
    }
}
ElemType Root(BiTree tree)
{
    if(BiTreeEmpty(tree))
        return Nil;
    else
        return tree->data;
}
BiTree Copy(BiTree T)
{
    BiTree newTree;
    if(T){
        newTree = (BiTree)malloc(sizeof(BiTNode));
        if(!newTree)
            exit(ERROR);
        newTree->data = T->data;
        newTree->lchild = Copy(T->lchild);
        newTree->rchild = Copy(T->rchild);
        return newTree;
    }
    else
        return NULL;
}

i32 Equal(BiTree first, BiTree second)
{
    if(!first && !second)
        return TRUE;
    if(first && second && first->data == second->data)
        return Equal(first->lchild, second->lchild) && Equal(first->rchild, second->rchild);
    return FALSE;
}
int main()
{
    BiTree tree;
    InitBiTree(&tree);
	StrAssign(str,"ABDH#K###E##CFI###G#J##");
    CreateBiTree(&tree);
    if(BiTreeEmpty(tree))
        printf("The tree is empty.\n");
    else
        printf("The tree is not empty.\n");
    printf("%d\n",BiTreeDepth(tree));
    ElemType root = Root(tree);
    printf("%c\n",root);
    printf("PreOrderTraverse:\n");
    PreOrderTraverse(tree);
    printf("\n");
    printf("InOrderTraverse:\n");
    InOrderTraverse(tree);
    printf("\n");
    InOrderTraverseIter(tree);
    printf("\n");
    printf("PostOrderTraverse:\n");
    PostOrderTraverse(tree);
    printf("\n");
    printf("LevelOrderTraverse:\n");
    LevelOrderTraverse(tree);
    printf("\n");
    BiTree leftSubTree = Copy(tree->lchild);
    printf("Left SubTree's PreOrderTraverse:\n");
    PreOrderTraverse(leftSubTree);
    printf("\n");
    BiTree rightSubTree = Copy(tree->rchild);
    if(Equal(leftSubTree, rightSubTree))
        printf("The left sub tree is equal to the right sub tree.\n");
    else
        printf("The left sub tree is not equal to the right sub tree.\n"); 
    ClearBiTree(&tree);
    ClearBiTree(&leftSubTree);
    ClearBiTree(&rightSubTree);
    if(BiTreeEmpty(tree))
        printf("The tree is empty.\n");
    else
        printf("The tree is not empty.\n");
    return 0;
}