#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    cout<<"Welcome to the world of programming\n";
    cout<<"This program is dediacted to explore end and begin function of an unordered set\n";
    // Creation of an unordered set
    unordered_set<float>s;
    // Insertion Function
    s.insert(1.0);
    s.insert(1.01);
    s.insert(1.02);
    s.insert(1.03);
    s.insert(1.04);
    s.insert(1.05);
    s.begin();
    return 0;
}