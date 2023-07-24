#include <iostream>
#include <stdio.h>
using namespace std;

int townRoad[1010];

// topic : find the root node and assign
int find(int x)
{
    if(x != townRoad[x]) townRoad[x] = find(townRoad[x]);
    return townRoad[x];
}

//topic : merge two set
void merge(int x, int y)
{
    if(find(x) != find(y)) townRoad[find(y)] = find(x);
    //merge(1,3) townRoad : [1,2,1,4]
    //merge(4,3) townRoad : [4,2,1,4]
}
int main()
{
    int town, road;
    while(scanf("%d %d",&town, &road) == 2 && town){
        for(int i = 1; i <= town; i++) townRoad[i] = i;
        for(int i= 0; i < road; i++){
            int a, b;
            scanf("%d %d",&a, &b);
            merge(a,b);
        }
        int count = 0;
        for(int i = 1; i <= town; i++){
            if(find(i) == i) count++;
            //find(3) townRoad : [4,2,4,4]
        }
        cout << count-1 << '\n';
    }
}

// !Test Input:
// 4 2
// 1 3
// 4 3