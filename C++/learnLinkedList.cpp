#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;
#define it iterator
#define rit reverse_iterator
int main()
{
    //topic : initalize list
    list <int> LinkedList;
    list <int> LinkedList2;
    //topic : add elements
    for(int i = 0; i < 10; i++) LinkedList.push_back(i);
    for(int i = 20; i > 10; i--) LinkedList2.push_back(i);
    //topic : print elements
    //subtopic : normal iterator
    // list <int>::it i;
    // for(i = LinkedList.begin(); i != LinkedList.end(); i++) cout << *i << ' ';
    // cout << '\n';
    //subtopic : reverse iterator
    // list <int>::rit ri;
    // for(ri = LinkedList.rbegin(); ri != LinkedList.rend(); ri++) cout << *ri << ' ';
    // cout << '\n';
    //topic : resize
    // LinkedList.resize(30);
    //topic : reverse
    // LinkedList.reverse();
    //topic : sort
    // LinkedList.sort();
    //topic : merge
    // LinkedList.merge(LinkedList2);
    //topic : splice
    // LinkedList.splice(LinkedList.end(), LinkedList2);

}