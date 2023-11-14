#include "../lib/base.h"
#include "../lib/algobase.h"
#define MAXSIZE 100
typedef char ElemType;
typedef struct BiTNode *BiTree;
typedef struct BiTNode
{
    ElemType data;
    BiTree lchild, rchild;
    u8 lthread, rthread;
} BiTNode;
u32 treeIndex = 0;
str string = NULL;
BiTree pre = NULL;
BiTree origin = NULL;
Status initBitree(BiTree *T)
{
    *T = NULL;
    return OK;
}
Status createBitree(BiTree *T)
{
    ElemType ch = string[treeIndex++];
    if(ch == '#')
        *T = NULL;
    else{
        *T = (BiTree) malloc(sizeof(BiTNode));
        if(!*T)
            exit(ERROR);
        (*T)->data = ch;
        createBitree(&(*T)->lchild);
        if((*T)->lchild)
            (*T)->lthread = 0;
        else
            (*T)->lthread = 1;
        createBitree(&(*T)->rchild);
        if((*T)->rchild)
            (*T)->rthread = 0;
        else
            (*T)->rthread = 1;
    }
    return OK;
}
Status bitreeEmpty(BiTree T)
{
    if(T)
        return FALSE;
    else 
        return TRUE;
}
Status Inthreading(BiTree T)
{
    if(T){
        Inthreading(T->lchild);
        if(!(T)->lchild){
            (T)->lthread = 1;
            (T)->lchild = pre;
            }
        if(!pre->rchild){
            pre->rthread = 1;
            pre->rchild = T;
        }
        pre = T;
        Inthreading(T->rchild);
    }
    return OK;
}
Status Insert_right(BiTree *Thr, BiTree *new)
{
    BiTree temp;
    u8 thread;
    temp = (*Thr)->rchild;
    thread = (*Thr)->rthread;
    (*Thr)->rchild = *new;
    (*Thr)->rthread = 0;
    (*new)->rchild = temp;
    (*new)->rthread = thread;
    (*new)->lthread = 1;
    (*new)->lchild = *Thr;
    return OK;
}
Status InorderThreading(BiTree *Thr, BiTree T)
{
    *Thr = (BiTree) malloc(sizeof(BiTNode));
    (*Thr)->lthread = 0;
    (*Thr)->rthread = 1;
    (*Thr)->rchild = *Thr;
    if(bitreeEmpty(T))
        (*Thr)->lchild = *Thr;
    else{
        (*Thr)->lchild = T;
        pre = (*Thr);
        Inthreading(T);
        pre->rchild = *Thr;
        pre->rthread = 1;
        (*Thr)->rchild = pre;
    }
    return OK;
}
Status InorderTravserse_Thr(BiTree T)
{
    BiTree p;
    p = T->lchild;
    while(p != T){
        while(p->lthread == 0)
            p = p->lchild;
        printf("%c", p->data);
        while(p->rthread == 1 && p->rchild != T){
            p = p->rchild;
            printf("%c", p->data);
        }
        p = p->rchild;
    }
    printf("\n");
    return OK;
}
void ClearBiTree(BiTree *T)
{
    if(*T){
        if(!(*T)->lthread && (*T)->lchild)
            ClearBiTree(&(*T)->lchild);
        if(!(*T)->rthread && (*T)->rchild)
            ClearBiTree(&(*T)->rchild);
        free(*T);
        *T = NULL;
    }
    return;
}
int main()
{
    BiTree H,T;
    string = "FBA##DC##E##G#IH###";
    initBitree(&T);
    createBitree(&T);
    InorderThreading(&H, T);
    BiTree new = (BiTree) malloc(sizeof(BiTNode));
    new->data = 'J';
    Insert_right(&T, &new);
    InorderTravserse_Thr(H);
    ClearBiTree(&T);
    free(H);
    return 0;
}
