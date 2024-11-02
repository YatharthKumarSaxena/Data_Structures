#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    cout<<"Welcome to the world of Programming\n";
    cout<<"This Program is dedicated to explore basic functionalities of unordered map\n";
    // Creation of a map
    unordered_map<string,int> mp;
    // Insertion Functions
    // Method-1 to insert a pair in map using pair class
    pair<string,int> p1,p2,p3,p4;
    p1.first = "Yatharth";
    p1.second = 10;
    p2.first = "Austin";
    p2.second = 20;
    p3.first = "Rupesh";
    p3.second = 30;
    p4.first = "Yatharth";
    p4.second = 40;
    mp.insert(p1);
    mp.insert(p2);
    mp.insert(p3); // Key is duplicate hence Yatharth,40 pair is not inserted in map
    mp.insert(p4);
    cout<<"Size of Map = "<<mp.size()<<endl;
    // Method-2 to insert a member in map (Good Method as compare to method 1)
    mp["Austin"] = 25; // Key is duplicate hence Austin,25 pair is not inserted in map
    mp["Tarun"] = 45;
    mp["Abhi"] = 100;
    // Checking Size of the map
    cout<<"Size of Map = "<<mp.size()<<endl;
    // Deletion Functions
    mp.erase("Austin"); // To delete a pair in map delete the key by deletion of key pair will be automatically deleted
    cout<<"Size of Map after deletion of Austin = "<<mp.size()<<endl;
    mp.erase("Austin");
    cout<<"Size of Map after deletion of deleted key in map = "<<mp.size()<<endl;
    return 0;
}