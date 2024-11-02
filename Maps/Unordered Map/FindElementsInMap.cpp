#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    cout<<"Welcome to the world of Programming\n";
    cout<<"The program is dedicated to explore the functionalities of find function in map\n";
    cout<<"Find function searches an element in the map and if element not found then it returns mp.end()\n";
    // To find a pair in unordered map key is searched as map exist in key,value pair
    // Creation of a map
    unordered_map<string,int> mp;
    mp["Austin"] = 25; 
    mp["Tarun"] = 45;
    mp["Abhi"] = 100;
    // Checking an item exists in map
    if(mp.find("Austin")!=mp.end()){
        cout<<"Item Austin exists in map\n";
    }
    // Checking an item does not exist in map
    if(mp.find("Yatharth")==mp.end()){
        cout<<"Item Yatharth does not exist in map\n";
    }
    return 0;
}