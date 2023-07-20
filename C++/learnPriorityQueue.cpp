#include <iostream>
#include <stdio.h>
#include <queue>
#include <stdlib.h>

using namespace std;


int main()
{
    priority_queue<int> pq;
    for(size_t i=0;i < 10;i++){
        pq.push(i);
    }
    size_t size = pq.size();
    for(size_t i = 0; i < size;i++){
        cout << pq.top() << ' ';
        pq.pop();
        if(i==size-1) cout<<'\n';
    }

}