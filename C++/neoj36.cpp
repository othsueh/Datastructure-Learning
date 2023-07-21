#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    stack <int> s;
    cin >>n;
    while(n--){
        int m;
        cin >> m;
        if(m == 1){
            int x;
            cin >> x;
            s.push(x);
        } 
        else{
            if(s.empty()) cout << "empty!" << '\n';
            else{
                cout << s.top() << '\n';
                s.pop();
            } 
        }
    }
}