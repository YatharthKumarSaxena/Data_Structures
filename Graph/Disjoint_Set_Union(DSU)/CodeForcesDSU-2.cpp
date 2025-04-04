#include <iostream>
using namespace std;
class DSU{
    // Data Members
    int *par; // Parent Array
    int *size; // Size of the Parent Arrayi
    int *maximum;
    int *minimum;
    int capacity;
public:
    // Parameterized Constructor
    DSU(int capacity){
        this->capacity = capacity;
        this->maximum = new int[capacity];
        this->minimum = new int[capacity];
        this->par = new int[capacity];
        this->size = new int[capacity];
        for(int i=0;i<capacity;i++){
            par[i]=i;
            size[i]=1;
            maximum[i] = i;
            minimum[i] = i;
        }
    }
    // Member Functions
    int findGroupLeader(int ele);
    void unionGroups(int eleA,int eleB);
    int groupSize(int ele);
    int getSize();
    int getMaximumElementOfGroup(int ele);
    int getMinimumElementOfGroup(int ele);
    // Destructor
    ~DSU(){
        delete[] par;
        delete[] size;
        delete[] maximum;
        delete[] minimum;
    }
    
};

// Path Compression Used
int DSU::findGroupLeader(int ele){ // Return the Group Element of the Element ele present in a group
    return (par[ele] = (ele == par[ele])?ele:findGroupLeader(par[ele]));
}
void DSU::unionGroups(int eleA,int eleB){ // Combine the Group Elements of B into Group Elements of A
    int parA = findGroupLeader(eleA);
    int parB = findGroupLeader(eleB);
    if(parA == parB)return;
    maximum[parA] = max(maximum[parA],maximum[parB]);
    maximum[parB] = max(maximum[parA],maximum[parB]);
    minimum[parA] = min(minimum[parA],minimum[parB]);
    minimum[parB] = min(minimum[parA],minimum[parB]);
    if(size[parA]>=size[parB]){
        par[parB] = parA;
        size[parA] += size[parB];
        
    }
    else{
        par[parA] = parB;
        size[parB] += size[parA];
    }
    return;
}
int DSU::getSize(){ // Return the Size of the Disjoint Set Union
    return this->capacity;
}
int DSU::groupSize(int ele){ // Return the Group Size of The Element Where the Element Belongs
    ele = findGroupLeader(ele);
    return this->size[ele];
}
int DSU::getMaximumElementOfGroup(int ele){
    ele = findGroupLeader(ele);
    return maximum[ele];
}
int DSU::getMinimumElementOfGroup(int ele){
    ele = findGroupLeader(ele);
    return minimum[ele];
}

void displayMenu(){
    cout<<"\n----------------Main Menu----------------\n";
    cout<<"1. To Union A Group into Another\n";
    cout<<"2. To find the Group Leader of the Element Group\n";
    cout<<"3. To find the Size of Element Group\n";
    cout<<"4. To find the maximum element in the Group\n";
    cout<<"5. To find the minimum element in the Group\n";
    cout<<"0. To Exit Main Program\n";
}

int main(){
    cout<<"\nWelcome to the World of Programming\n";
    cout<<"This Program is dedicated to Explore Union By Size Implementation of DSU Data Structure\n";
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
            cout<<"Please enter the Element of the first Group:- ";
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
            cout<<"Please enter the Element for which you want to find the size of its Group:- ";
            cin>>a;
            if(a>=dsu.getSize()){
                cout<<"Please enter valid Element Present in Group\n";
                continue;
            }
            cout<<"Group Size of the Element "<<a<<" is "<<dsu.groupSize(a)<<endl;
        }
        else if(choice == 4){
            int a;
            cout<<"Please enter the Element in order to find the maximum element of its Group:- ";
            cin>>a;
            if(a>=dsu.getSize()){
                cout<<"Please enter valid Element Present in Group\n";
                continue;
            }
            cout<<"Maximum Element of the Group where Element "<<a<<" belongs is "<<dsu.getMaximumElementOfGroup(a)<<endl;
        }
        else if(choice == 5){
            int a;
            cout<<"Please enter the Element in order to find the minimum element of its Group:- ";
            cin>>a;
            if(a>=dsu.getSize()){
                cout<<"Please enter valid Element Present in Group\n";
                continue;
            }
            cout<<"Minimum Element of the Group where Element "<<a<<" belongs is "<<dsu.getMinimumElementOfGroup(a)<<endl;
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