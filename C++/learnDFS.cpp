#include <iostream>
#include <cstring>
using namespace std;

bool connections[102][102] = {0};
bool visited[102] = {0};

void dfs(int s, int n)
{
    for(int i = 1; i <= n; i++){
        if(connections[s][i] && !visited[i]){
            visited[i] = true;
            dfs(i, n);
        }
    }
}
int main()
{
    int vertices = 0;
    while(scanf("%d", &vertices) == 1 && vertices)
    {
        int node = 0;
        //topic : understanding way
        // while(scanf("%d",&node) == 1 && (node || count)){
        //     if(!node){
        //         count = 0;
        //         continue;
        //     }
        //     if(count){
        //         connections[preNode][node] = 1;
        //     }
        //     preNode = node;
        //     count++; 
        // }
        //topic : pro way
        while(scanf("%d", &node) == 1 && node){
            int preNode = 0;
            while(scanf("%d", &preNode) == 1 && preNode){
                connections[node][preNode] = 1;
            }
        }
        int m = 0;
        int count;
        scanf("%d", &m);
        for(int i = 0; i < m;i++){
            count = 0;
            int start;
            memset(visited, 0, sizeof(visited));
            scanf("%d", &start);
            dfs(start, vertices);
            for(int i = 1;i <= vertices; i++){
                if(visited[i]) count++;
            }
            printf("%d", vertices - count);
            for(int i = 1;i <= vertices; i++){
                if(!visited[i]) printf(" %d", i);
            }
            printf("\n");
        }
    }
}