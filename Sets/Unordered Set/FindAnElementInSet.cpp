#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    cout<<"Welcome to the world of programming\n";
    cout<<"This program is dedicated to explore functionalities of find function of unordered set\n";
    cout<<"Find function searches an element in the set and if element not found then it returns s.end()\n";
    // Creation of an unordered set
    unordered_set<char>s;
    // Insertion Function
    s.insert('a');
    s.insert('b');
    s.insert('c');
    s.insert('d');
    s.insert('e');
    s.insert('f');
    // Checking an item exist
    if(s.find('a')!=s.end()){
        cout<<"Item 'a' exists in unordered set\n";
    }
    // Checking an item does not exist in set
    if(s.find('z')==s.end()){
        cout<<"Item 'z' does not exist in unordered set\n";
    }
    return 0;
}