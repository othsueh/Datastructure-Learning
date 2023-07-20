#include <stdio.h>
#include <iostream>
#include <forward_list>
#define it iterator

using namespace std;

int main()
{
    //topic : initialize forward_list
    forward_list<char> flist1;
    forward_list<char> flist2;
    //topic : add elements
    for(char i = 'Z' ; i >= 'A'; i--) flist1.push_front(i);
    for(char i = '1'; i <= '9'; i++) flist2.push_front(i);
    //topic : print elements
    // for(auto i = flist1.begin(); i != flist1.end(); i++) cout << *i << ' ';
    // cout << '\n';

    //topic : insert element
    flist1.insert_after(flist1.begin(), 'A');

    //topic : erase element
    for(auto i = flist1.begin(); i != flist1.end(); i++){
        if(*i == 'I'){
            flist1.erase_after(i);
            break;  
        }
    }

    //topic : sort
    flist2.sort();
    //topic : merge
    // flist1.merge(flist2);

    //topic : splice
    for(auto i = flist1.begin(); i != flist1.end(); i++){
        if(*i == 'I'){
            flist1.splice_after(i, flist2);
            break;  
        }
    }
    //topic : remove_if
    flist1.remove_if([](char x){return x == 'I';});

    //topic : unique (remove consecutive duplicate)
    flist1.unique();

    //topic : assign
    flist1.assign(5, 'A');
    for(auto i = flist1.begin(); i != flist1.end(); i++) cout << *i << ' ';
    cout << '\n';
}