#include <iostream>
using namespace std;
class DSU{
    // Data Members
    int *par; // Parent Array
    int size; // Size of the Parent Array
public:
    // Parameterized Constructor
    DSU(int size){
        this->size = size;
        this->par = new int[size];
        for(int i=0;i<size;i++){
            par[i]=i;
        }
    }
    // Member Functions
    int findGroupLeader(int ele);
    void unionGroups(int eleA,int eleB);
    int getSize();
};

int DSU::findGroupLeader(int ele){ // Return the Group Element of the Element ele present in a group
    return par[ele];
}
void DSU::unionGroups(int eleA,int eleB){ // Combine the Group Elements of B into Group Elements of A
    int parA = findGroupLeader(eleA);
    int parB = findGroupLeader(eleB);
    if(parA == parB)return;
    for(int i=0;i<this->size;i++){
        if(par[i]==parB)par[i]=parA;
    }
    return;
}
int DSU::getSize(){ // Return the Size of the Disjoint Set Union
    return this->size;
}

void displayMenu(){
    cout<<"\n----------------Main Menu----------------\n";
    cout<<"1. To Union A Group into Another\n";
    cout<<"2. To find the Group Leader of the Element Group\n";
    cout<<"0. To Exit Main Program\n";
}

int main(){
    cout<<"\nWelcome to the World of Programming\n";
    cout<<"This Program is dedicated to Explore Naive Implementation of DSU Data Structure\n";
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
            cout<<"Please enter the Element of the Group which you want to merge in another Group:- ";
            cin>>b;
            cout<<"Please enter the Element of the Group in which you are merging another Group:- ";
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
            cout<<"Group Leader of the Element "<<a<<" is "<<dsu.findGroupLeader(a);
        }
        else if(choice == 0){
            exit(0);
        }
        else{
            cout<<"Invalid choice , please try again\n";
        }
    }
}