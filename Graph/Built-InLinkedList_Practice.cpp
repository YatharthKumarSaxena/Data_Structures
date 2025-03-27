#include <iostream>
#include <list> // Built-in Linked List of C++
using namespace std;

int main(){
    // Practising Built in Linked List
    list<int>LL;
    LL.push_back(1); // Insert at End;
    LL.push_front(0); // Insert At Head;
    LL.push_back(2);
    LL.push_back(3);
    cout<<"\nFront Element:- ";
    LL.push_back(4); // Get First Element of Linked List
    cout<<LL.front(); // Get Last Element Of Linked List
    cout<<"\nLast Element:- ";
    cout<<LL.back();
    cout<<"\nDisplay of Linked List :- \n";
    for(auto ele: LL){ // Method to display Linked List
        cout<<ele<<" ";
    }
    cout<<"\nLinked List Size:- "<<LL.size();
    LL.reverse();   // Reverse of Linked List
    cout<<"\nAfter Reverse Linked List Looks as given Below :- \n";
    for(auto ele: LL){ // Method to display Linked List
        cout<<ele<<" ";
    }
    LL.sort(); // Sorting of Linked List
    cout<<"\nAfter Sorting Linked List Looks as given Below :- \n";
    for(auto ele: LL){ // Method to display Linked List
        cout<<ele<<" ";
    }
    cout<<"\nFront Element:- ";
    cout<<LL.front(); // Get First Element of Linked List
    cout<<"\nLast Element:- ";
    cout<<LL.back(); // Get Last Element of Linked List
    LL.pop_front(); // Deletion at Head
    LL.pop_back(); // Deletion at Tail
    cout<<"\nAfter deletion Linked List Looks as given Below :- \n";
    for(auto ele: LL){ // Method to display Linked List
        cout<<ele<<" ";
    }
    LL.remove(2); // Remove Specific Value from Linked List
    cout<<"\nAfter deletion Linked List Looks as given Below :- \n";
    for(auto ele: LL){ // Method to display Linked List
        cout<<ele<<" ";
    }
    
    return 0;
}