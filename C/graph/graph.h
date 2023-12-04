#include <stdio.h>
#include "../lib/base.h"
#include "../lib/algobase.h"
#define Elementype i32

// i32 graphList[10][2] = {
//     {0,1},
//     {0,2},
//     {1,3},
//     {1,4},
//     {2,5},
//     {2,6},
//     {3,7},
//     {4,7},
//     {5,7},
//     {6,7}
// };
typedef struct edge* edgeptr;
typedef struct edge{
    u8 marked;
    Elementype v1, v2;
    edgeptr p1,p2;
} edge;

typedef struct graph {
    u32 n;
    u8 *visited;
    edgeptr* edges;
} graph;
typedef struct Node* queue;
typedef struct Node {
    Elementype value;
    queue link;
}Node;
Status emptyGraph(graph g){
    for(u32 i = 0; i < g.n; i++){
        if(g.edges[i]) return FALSE;
    }
    return TRUE;
}
void maintainEdge(graph* g,Elementype v, edgeptr* e){
    edgeptr* temp = &g->edges[v];
    while(*temp){
        if((*temp)->v1 == v){
            if((*temp)->p1 == NULL){
                (*temp)->p1 = *e;
                break;
            }else{
                temp = &(*temp)->p1;
            }
        }else{
            if((*temp)->p2 == NULL){
                (*temp)->p2 = *e;
                break;
            }else{
                temp = &(*temp)->p2;
            }
        }
    }
}
Status addEdge(graph* g, Elementype v1, Elementype v2){
    if (v1 >= g->n || v2 >= g->n) return ERROR;
    edgeptr e = (edgeptr)malloc(sizeof(edge));
    e->v1 = v1;
    e->v2 = v2;
    e->p1 = NULL;
    e->p2 = NULL;
    if(g->edges[v1] && g->edges[v2]){
        maintainEdge(g, v1, &e);
        maintainEdge(g, v2, &e);
    }else{
        if(!g->edges[v1]){
            g->edges[v1] = e;
            e->p1 = NULL;
        }else
            maintainEdge(g, v1, &e);
        if(!g->edges[v2]){
            g->edges[v2] = e;
            e->p2 = NULL;
        }else
            maintainEdge(g, v2, &e);
    }
    return OK;
}
Status initGraph(graph*g, u32 n){
    g->n = n;
    g->edges = (edgeptr*)malloc(sizeof(edgeptr)*n);
    for (u32 i = 0; i < n; ++i) {
        g->edges[i] = NULL;
    }
    return OK;
}
// Status createGraph(graph* g, u32 n){
//     initGraph(g, n);
//     g->visited = (u8*)malloc(sizeof(u8)*n);
//     u32 length = sizeof(graphList)/sizeof(graphList[0]);
//     for(u32 i = 0; i < 10; i++){
//         addEdge(g, graphList[i][0], graphList[i][1]);
//     }
//     return OK;
// }
//Change the graph to a tree(for deleting)
void dfsTree(edgeptr *e){
    if(*e){
        (*e)->marked = 1;     
        if((*e)->p1){
            if((*e)->p1->marked == 0){
                dfsTree(&((*e)->p1));
            } 
            else (*e)->p1 = NULL;
        }
        if((*e)->p2){
            if((*e)->p2->marked == 0){
                dfsTree(&((*e)->p2));
            } 
            else (*e)->p2 = NULL;
        }
    }
}
//Delete the tree
void deleteTree(edgeptr *e){
    if(*e){
        deleteTree(&((*e)->p1));
        (*e)->p1 = NULL;
        deleteTree(&((*e)->p2));
        (*e)->p2 = NULL;
        free(*e);
        *e = NULL;
    }
}
void cleanGraph(graph* g) {
    if (g == NULL) return;
    edgeptr *e = &(g->edges[0]);
    dfsTree(e);
    deleteTree(e);
    free(g->edges);
    free(g->visited);
    g->n = 0;
}
Status printGraph(graph g)
{
    for(u32 i = 0; i < g.n; ++i){
        printf("%d: ", i);
        edgeptr e = g.edges[i];
        while(e){
            printf("%d ", e->v1 == i ? e->v2 : e->v1);
            e = e->v1 == i ? e->p1 : e->p2;
        }
        printf("\n");
    }
}
void visitedclean(graph *g)
{
    for(u32 i = 0; i < g->n; i++)
        g->visited[i] = 0; 
}
void dfsTraverse(graph g, u32 v)
{
    if(v >= g.n) return;
    edgeptr e = g.edges[v];
    printf(" %d", v);
    g.visited[v] = 1;
    while(e){
        if(e->v1 == v && g.visited[e->v2] == 0)
            dfsTraverse(g, e->v2);
        else if(e->v2 == v && g.visited[e->v1] == 0)
            dfsTraverse(g, e->v1); 
        e = e->v1 == v ? e->p1 : e->p2;
    }
    return;
}
void addq(queue* front, queue* rear, Elementype v)
{
    queue temp = (queue)malloc(sizeof(Node));
    temp->value = v;
    temp->link = NULL;
    if(!*front && !*rear){
        *front = temp;
        *rear = temp;
    }else{
        (*rear)->link = temp;
        *rear = temp;
    } 
}
Elementype deleteq(queue* front, queue* rear)
{
    if(*front == NULL)
        return -1;
    queue temp = *front;
    Elementype pop = temp->value;
    *front = (*front)->link;
    if(*rear == temp) 
        *rear = *front;
    free(temp);
    return pop;
}
void bfsTraverse(graph g, u32 v)
{
    if(v >= g.n) return;
    queue front, rear;
    front = rear = NULL;
    printf(" %d",v);
    g.visited[v] = 1; 
    addq(&front,&rear,v);
    while(front){
        v = deleteq(&front,&rear);
        edgeptr e = g.edges[v];
        while(e){
            Elementype t = e->v1 == v ? e->v2 : e->v1;
            if(!g.visited[t]){
                printf(" %d",t);
                g.visited[t] = 1;
                addq(&front, &rear, t);
            }
            e = e->v1 == v ? e->p1 : e->p2;
        }
    }
    
}
// int main() {
//     graph g;
//     createGraph(&g, 8);  
//     printGraph(g);
//     dfsTraverse(g, 7);
//     visitedclean(&g);
//     printf("\n");
//     bfsTraverse(g, 7);
//     visitedclean(&g);
//     printf("\n");
//     cleanGraph(&g);
//     if(emptyGraph(g)) printf("Empty\n");
//     else printf("Not Empty\n");
//     return 0;
// }
