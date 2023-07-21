#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int n;
    stack <char> s;
    cin >> n;
    cin.ignore();
    while(n--){
        string str;
        getline(cin,str);
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '(') s.push(str[i]);
            else if(str[i] == ')'){
                if(s.empty()){
                    cout << "Invalid string" <<'\n';
                }
                else s.pop();
            }
        }
        if(s.empty()) cout << "Valid string" << '\n';
        else cout << "Invalid string" << '\n';
    }
}