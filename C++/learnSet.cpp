#include <iostream>
#include <set>
using namespace std;

int main()
{
    //topic : initialize set
    set <char> s;
    set <int> s2;

    //topic : add elements
    for(char i = 'a'; i <= 'z'; i++) s.insert(i); //Copies or moves the element into the set.
    for(int i = 0; i <= 16; i += 2) s2.emplace(i); //Constructs the new element in-place and inserts it into the set if it is unique.

    //topic : remove elements
    // for(char i = '0'; i < 'p'; i++) if(s.find(i) != s.end()) s.erase(s.find(i)); //Removes the element at pos.

    //topic : print elements 
    // for(auto i = s.begin(); i != s.end(); i++) cout << *i << ' ';
    // cout<<'\n';

    //topic : count elements
    // cout << "The number of z in the set is " << s.count('z') << '\n';

    //topic : lower_bound and upper_bound
    cout << "The lower bound of 6 is " << *s2.lower_bound(6) << '\n';
    cout << "The upper bound of 6 is " << *s2.upper_bound(6) << '\n';

    //topic : equal_range
    auto range = s2.equal_range(6);
    if(range.first != range.second) cout << "The range of 6 is " << *range.first << " ~ " << *range.second << '\n';

    //topic : hint
    auto hint = s2.find(8);
    s2.emplace_hint(hint, 9);
    for(auto i = s2.begin(); i != s2.end(); i++) cout << *i << ' ';
    cout<<'\n';

    //topic : key_comp and value_comp
    //subtopic : key_comp
    auto comp = s2.key_comp();
    bool comp1 = comp(1,2);
    if(comp1) cout << "1 is less than 2\n";
    else cout << "1 is not less than 2\n";

    //subtopic : value_comp
    auto comp2 = s.value_comp();
    bool comp3 = comp2('b','a');
    if(comp3) cout << "a is less than b\n";
    else cout << "a is not less than b\n";
}