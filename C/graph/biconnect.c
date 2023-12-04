#include <stdio.h>
#include "../lib/base.h"
#include "../lib/algobase.h"
#include "./graph.h"
#define MIN(a,b) ((a) < (b) ? (a) : (b))

i8 dfn[10], low[10];
i8 num;
typedef struct biEdge* biEdgeptr;
typedef struct biEdge{
    Elementype v1, v2;
    biEdgeptr link;
} biEdge;
biEdgeptr top = NULL;
void push(Elementype v1, Elementype v2){
    biEdgeptr temp = (biEdgeptr)malloc(sizeof(biEdge));
    temp->v1 = v1;
    temp->v2 = v2;
    temp->link = top;
    top = temp;
}
void pop(Elementype* v1, Elementype* v2){
    biEdgeptr temp = top;
    *v1 = temp->v1;
    *v2 = temp->v2;
    top = top->link;
    free(temp);
}
i32 graphList[11][2] = {
    {0,1},
    {1,2},
    {3,4},
    {1,3},
    {2,4},
    {3,5},
    {5,6},
    {5,7},
    {6,7},
    {7,8},
    {7,9}
};
void init(graph *g)
{
    num = 0;
    for(u8 i = 0; i < 10; i++){
        dfn[i] = -1;
        low[i] = -1;
        g->visited[i] = 0;
    }
}
Status createGraph(graph* g, u32 n){
    initGraph(g, n);
    g->visited = (u8*)malloc(sizeof(u8)*n);
    u32 length = sizeof(graphList)/sizeof(graphList[0]);
    for(u32 i = 0; i < length; i++){
        addEdge(g, graphList[i][0], graphList[i][1]);
    }
    return OK;
}

void dfnlow(graph* g, Elementype u, Elementype v)
{
    if(!g->visited[u]){
        g->visited[u] = 1;
        dfn[u] = low[u] = num++;
    }
    for(edgeptr e = g->edges[u]; e ;e = e->v1 == u ? e->p1 : e->p2){
        Elementype w = e->v1 == u ? e->v2 : e->v1;
        if(v != w && dfn[w] < dfn[u]) push(u, w);
        if(dfn[w] < 0){
            dfnlow(g, w, u);
            low[u] = MIN(low[u], low[w]); // tree edge
            if(low[w] >= dfn[u]){
                printf("New biconnected component: ");
                Elementype x = -1, y = -1;
                while(x != u || y != w){
                    pop(&x, &y);
                    printf("(%d, %d)", x, y);
                }
                printf("\n");
            }
        }else if(w != v)
            low[u] = MIN(low[u], dfn[w]); // back edge
    }
}
int main()
{
    graph g;
    createGraph(&g, 10);
    init(&g);
    printGraph(g); 
    dfnlow(&g, 3,-1);
    printf("\n");
    cleanGraph(&g);
    if(emptyGraph(g)) printf("Empty\n");
    else printf("Not Empty\n");
    return 0;
}

