#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector <vector<bool>> map(100);
int width, height;
int dfs(int x, int y)
{
    if(x < 1 || y < 1 || y > width || x > height) return 0;
    if(map[x][y]) return 0;
    map[x][y] = 1;
    return 1 + dfs(x-1,y) + dfs(x+1,y) + dfs(x,y+1) +dfs(x,y-1);
}
int main()
{
    int dataSet = 0;
    scanf("%d",&dataSet);
    while(dataSet--){
        map.clear();
        int inrow, incol;
        scanf("%d %d",&inrow, &incol);
        cin.ignore();
        string temp;
        int i = 1;
        while(getline(cin,temp) && temp != ""){
            if(!width) width = temp.length();
            map[i].push_back(1);
            for(int j = 0; j <= temp.length(); j++) map[i].push_back(temp[j] - '0');
            i++;
        }
        height = i-1;
        int count = 0;
        count = dfs(inrow, incol);
        cout << count <<'\n';
    }
}