#include <iostream>
#include <set>
using namespace std;

int main()
{
    //topic : initialize set
    set <char> s;
    set <char> s2;

    //topic : add elements
    for(char i = 'a'; i <= 'z'; i++) s.insert(i); //Copies or moves the element into the set.
    for(char i = 'A'; i <= 'Z'; i++) s2.emplace(i); //Constructs the new element in-place and inserts it into the set if it is unique.

    //topic : remove elements
    for(char i = '0'; i < 'p'; i++) if(s.find(i) != s.end()) s.erase(s.find(i)); //Removes the element at pos.

    //topic : print elements 
    for(auto i = s.begin(); i != s.end(); i++) cout << *i << ' ';
    cout<<'\n';

    //topic : count elements
    cout << "The number of z in the set is " << s.count('z') << '\n';
}