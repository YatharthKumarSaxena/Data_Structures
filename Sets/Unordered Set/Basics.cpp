#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    cout<<"Welcome to the world of programming\n";
    cout<<"This program is dedicated to explore functionalities of an unordered set\n";
    // Creation of a set
    unordered_set<int>s;
    // Insertion Function in unordered set
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(1); // Not inserted as this is a duplicate value
    cout<<"Set Size = "<<s.size()<<endl; // Duplicate value are not inserted hence they are not considered in the size
    // Deletion Functions in unordered set
    s.erase(1);
    cout<<"Set Size = "<<s.size()<<endl;
    s.erase(2);
    cout<<"Set Size = "<<s.size()<<endl;
    s.erase(3);
    cout<<"Set Size = "<<s.size()<<endl;
    s.erase(4);
    cout<<"Set Size = "<<s.size()<<endl;
    s.erase(5);
    cout<<"Set Size = "<<s.size()<<endl;
    // No error generates even if you try to delete an element from set which does not exist
    s.erase(10); 
    cout<<"Set Size = "<<s.size()<<endl;
    s.erase(90);
    
}