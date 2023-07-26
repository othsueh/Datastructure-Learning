#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector <vector<int>>conquerMap(21,vector<int>(21));
vector <int> visited(21);
int bfs(int s, int t)
{
    fill(visited.begin(),visited.end(),0);
    queue <int> q;
    q.push(s);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(node == t) break;
        for(int i = 1; i <= 20; i++){
            if(visited[i] < 1 && conquerMap[node][i]){
                q.push(i);
                visited[i] = visited[node] + 1;
            }
        }
    }
    return visited[t];
}
int main()
{
    int connect, country;
    int count = 1;
    while(scanf("%d",&connect) == 1){
        fill(conquerMap.begin(),conquerMap.end(), vector<int>(21,0));
        while(connect--){
            scanf("%d", &country);
            conquerMap[1][country] = 1;
            conquerMap[country][1] = 1;
        }
        for(int i = 2; i < 20; i++){
            scanf("%d",&connect);
            while(connect--){
                scanf("%d", &country);
                conquerMap[i][country] = 1;
                conquerMap[country][i] = 1;
            }
        }
        int test;
        scanf("%d",&test);
        printf("Test Set #%d\n", count);
        count++;
        for(int i = 0; i < test; i++){
            int start, end;
            scanf("%d%d", &start, &end);
            printf("%2d to %2d: %2d\n",start,end,bfs(start,end));
        }
        printf("\n");
        count++;
    }

}