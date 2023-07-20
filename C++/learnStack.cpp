#include <iostream>
#include <stdio.h>
#include <stack>
#include <stdlib.h>

using namespace std;

int main()
{
    stack<int> st;
    for(size_t i = 0; i < 10 ; i++){
        st.push(i);
    }
    if(st.empty()) cout << "This stack is empty\n";
    else{
        cout << "The size of this stack is " << st.size() << '\n';
        cout << "The top element is " << st.top() <<'\n';
    }
    size_t size = st.size();
    for(size_t i=0;i < size;i++){
        cout<<st.top()<<' ';
        st.pop();
        if(i==size-1) cout<<'\n';
    }
}