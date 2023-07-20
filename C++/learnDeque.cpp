#include <iostream>
#include <stdio.h>
#include <deque>
#include <stdlib.h>

using namespace std;


int main()
{
    deque<int> dq;
    for(size_t i = 0; i < 10 ; i++){
        dq.push_back(i);
    }
    cout << "The size of this deque is" << dq.size() << '\n';
    if(dq.empty()) cout << "This deque is empty\n";
    else {
        cout << "The first element is " << dq.front() <<' ';
        cout << "The last element is " << dq.back() << '\n';
    }
    for(size_t i=0;i < dq.size();i++){
        cout<<dq.at(i)<<' ';
        if(i==dq.size()-1) cout<<'\n';
    }
    dq.pop_front();
    cout << dq.front()<<'\n';
    dq.pop_back();
    cout << dq.back()<<'\n';
    dq.insert(dq.begin()+2, 100);
    for(auto i= dq.begin(); i!=dq.end(); i++){
        cout<<*i<<' ';
        if(i==dq.end()-1) cout<<'\n';
    }
    dq.erase(dq.begin()+3);
    for(auto i= dq.begin(); i!=dq.end(); i++){
        cout<<*i<<' ';
        if(i==dq.end()-1) cout<<'\n';
    }
    dq.clear();
    if(dq.empty()) cout << "Yes\n" ;
}
