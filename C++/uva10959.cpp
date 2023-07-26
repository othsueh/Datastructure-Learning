#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int dancePair[1001][1001] = {0};
int dis[1001] = {0};
bool check[1001] = {0};
void bfs(int start,int num)
{
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(int i = 0; i < num; i++){
            if(dancePair[front][i] && !check[i])
            {
                q.push(i);
                dis[i] = dis[front] + 1;
                check[i] = 1;
            }
        }
    }
}
int main()
{
    int testData = 0;
    scanf("%d",&testData);
    while(testData--){
        memset(dancePair,0,sizeof(dancePair));
        memset(check,0,sizeof(check));
        memset(dis,0,sizeof(dis));
        int number, couple;
        scanf("%d %d",&number, &couple);
        while(couple--){
            int p1, p2;
            scanf("%d%d",&p1,&p2);
            dancePair[p1][p2] = 1;
            dancePair[p2][p1] = 1;
        }
        bfs(0,number);
        for(int i = 1; i < number; i++) printf("%d\n",dis[i]);
        printf("\n");
    }

}