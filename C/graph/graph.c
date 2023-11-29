#include <stdio.h>
#include "../lib/base.h"
#include "../lib/algobase.h"
#define Elementype i32

typedef struct edge* edgeptr;
typedef struct edge{
    u8 marked;
    Elementype v1, v2;
    edgeptr p1,p2;
} edge;

typedef struct graph {
    u32 n;
    edgeptr* edges;
} graph;

Status createGraph(graph*g, u32 n){
    g->n = n;
    g->edges = (edgeptr*)malloc(sizeof(edgeptr)*n);
    for (u32 i = 0; i < n; ++i) {
        g->edges[i] = NULL;
    }
    return OK;
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
Status printGraph(graph g){
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

int main() {
    graph g;
    createGraph(&g, 5);
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 0, 3);
    addEdge(&g, 1, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 2, 3);
    printGraph(g);
    return 0;
}
