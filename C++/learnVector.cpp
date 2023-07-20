#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


int main()
{
    //topic : initialize iterator
    vector<int> v;

    //topic : add elements
    for(int i = 0; i < 10; i++) v.push_back(i);

    //topic : get the size of the vector
    // cout << "The size of this vector is " << v.size() << '\n';
    //topic : get the element at the index
    //subtopic : at method
    // int a;
    // try{
    //     a = v.at(9);
    //     cout << a <<'\n';
    // }catch(out_of_range& e){
    //     cout <<"Out of Rnage error" <<e.what() << '\n';
    // }
    //subtopic : operator method
    // for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';
    // cout <<'\n';

    //subtopic : front and back method
    // cout << "The first element is " << v.front() << '\n';
    // cout << "The last element is " << v.back() << '\n';

    //topic : clear the vector
    // v.clear();

    //topic : check if the vector is empty
    // if(v.empty()) cout << "the vector is empty\n";
    // else{
    //     cout<<"the vector is not empty\n";

        //topic : initialize iterator 
        //subtopic : normal iterator
        // vector<int>::iterator it;
        // for(it = v.begin(); it != v.end(); it++) cout << 10* (*it)<<' ';

        //subtopic : reverse iterator
    //     vector<int>::reverse_iterator rit;
    //     for(rit = v.rbegin(); rit != v.rend(); rit++) cout << 10* (*rit)<<' ';
    //     cout <<'\n';
    // }

    //topic : change vector
    //subtopic : insert
    // int newElement = 100;
    // v.insert(v.begin()+5, newElement);
    
    //subtopic : erase
    // v.erase(v.begin()+4);

    //subtopic : swap (have to do with another vector)
    // vector <int> v2 = {1,3,5,7,9};
    // v.swap(v2);
    // for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';
    // cout <<'\n';
    // for(int i = 0; i < v2.size(); i++) cout << v2[i] << ' ';
    // cout <<'\n';

}