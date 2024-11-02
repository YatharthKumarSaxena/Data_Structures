#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    cout<<"Welcome to the world of programming\n";
    cout<<"The elements of a set are unordered hence they cannot be printed via for or while loop\n";
    cout<<"To print the elements of an unordered set , for each loop is used as given below :- \n";
    // Creation of a set
    unordered_set<int>s;
    // Insertion Functions
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(6);
    // For Each Loop
    for(int ele : s){
        cout<<ele<<" ";
    }
    return 0;
}