#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main()
{
    int n;
    stack <pair<int,int>> colStack;
    int max = 0;
    cin >> n;
    for(int i = 0;i < n;i++){
        int h;
        cin >> h;
        if(colStack.empty() || colStack.top().first < h) colStack.push({h,i});
        else if(colStack.top().first == h) continue;
        else{
            while(!colStack.empty() && (colStack.top().first > h)){
                int width = i - colStack.top().second;
                int area = colStack.top().first * width;
                if(area > max) max = area;
                colStack.pop();
            }
            if(colStack.empty()){
                if(h == 1) colStack.push({h,0});
                else colStack.push({h,i});
            }
            else{
                if(colStack.top().first == h) continue;
                else colStack.push({h, i});
            }
        }
        if(i == n-1){
            int width = i - colStack.top().second;
            int area = colStack.top().first * width;
            if(area > max) max = area;
        }
    }

    cout<<max<<'\n';
}