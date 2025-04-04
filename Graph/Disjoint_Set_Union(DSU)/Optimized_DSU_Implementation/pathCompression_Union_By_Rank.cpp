#include <iostream>
using namespace std;
class DSU{
    // Data Members
    int *par; // Parent Array
    int *rank; // Size of the Parent Array
    int capacity;
public:
    // Parameterized Constructor
    DSU(int capacity){
        this->capacity = capacity;
        this->par = new int[capacity];
        this->rank = new int[capacity];
        for(int i=0;i<capacity;i++){
            par[i]=i;
            rank[i]=1; // Each Element is Linked To Itself , So there is one Direct Link
        }
    }
    // Member Functions
    int findGroupLeader(int ele);
    void unionGroups(int eleA,int eleB);
    int getRank(int ele);
    int getSize();
};

// Path Compression
int DSU::findGroupLeader(int ele){ // Return the Group Element of the Element ele present in a group
    return par[ele] = ((ele == par[ele])?ele:findGroupLeader(par[ele]));
}
void DSU::unionGroups(int eleA,int eleB){ // Combine the Group Elements of B into Group Elements of A
    int parA = findGroupLeader(eleA);
    int parB = findGroupLeader(eleB);
    if(rank[parA]>=rank[parB]){
        par[parB] = parA;
        rank[parA]++;
    }
    else{
        par[parA] = parB;
        rank[parB]++;
    }
    return;
}
int DSU::getSize(){ // Return the Size of the Disjoint Set Union
    return this->capacity;
}
int DSU::getRank(int ele){ // Return the Rank of the Element
    return this->rank[ele];
}

void displayMenu(){
    cout<<"\n----------------Main Menu----------------\n";
    cout<<"1. To Union A Group into Another\n";
    cout<<"2. To find the Group Leader of the Element Group\n";
    cout<<"3. To find the Size of Element Group\n";
    cout<<"0. To Exit Main Program\n";
}

int main(){
    cout<<"\nWelcome to the World of Programming\n";
    cout<<"This Program is dedicated to Explore Union By Rank Path Compression Implementation of DSU Data Structure\n";
    cout<<"Please enter total number of independent groups in your DSU:- ";
    int n;
    cin>>n;
    DSU dsu(n);
    cout<<"DSU of size "<<n<<" containing independent group elements from 0 to "<<n-1<<" created successfully\n";
    while(true){
        displayMenu();
        cout<<"Please enter your Choice:- ";
        int choice;
        cin>>choice;
        if(choice == 1){
            int a,b;
            cout<<"Please enter the Element of the first Group :- ";
            cin>>b;
            cout<<"Please enter the Element of the another Group:- ";
            cin>>a;
            if(a>=dsu.getSize() || b>=dsu.getSize()){
                cout<<"Please enter valid Element Present in Group\n";
                continue;
            }
            dsu.unionGroups(a,b);
            cout<<"Union Done Successfully\n";
        }
        else if(choice == 2){
            int a;
            cout<<"Please enter the Element for which you want to find the leader of its Group:- ";
            cin>>a;
            if(a>=dsu.getSize()){
                cout<<"Please enter valid Element Present in Group\n";
                continue;
            }
            cout<<"Group Leader of the Element "<<a<<" is "<<dsu.findGroupLeader(a)<<endl;
        }
        else if(choice == 3){
            int a;
            cout<<"Please enter the Element to find its rank:- ";
            cin>>a;
            if(a>=dsu.getSize()){
                cout<<"Please enter valid Element Present in Group\n";
                continue;
            }
            cout<<"Rank of the Element "<<a<<" is "<<dsu.getRank(a)<<endl;
        }
        else if(choice == 0){
            cout<<"\nExiting Main Program\n";
            exit(0);
        }
        else{
            cout<<"Invalid choice , please try again\n";
        }
    }
}