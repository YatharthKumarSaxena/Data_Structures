#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    cout<<"Welcome to the world of programming\n";
    cout<<"In this program we learn to print elements of a map\n";
    cout<<"Since map used is unordered ,for each loop is used\n";
    // Creation of a map
    unordered_map<string,int> mp;
    mp["Austin"] = 25; 
    mp["Tarun"] = 45;
    mp["Abhi"] = 100;
    // Method-1 to print elements of a map
    cout<<"Printing of elements of map by normal method :- \n";
    for(pair<string,int> p : mp){
        cout<<p.first<<" "<<p.second<<endl;
    }
    // Method-2 to print elements of a map (Good Method)
    cout<<"Printing of elements of map by auto keyword :- \n";
    for(auto p : mp){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}