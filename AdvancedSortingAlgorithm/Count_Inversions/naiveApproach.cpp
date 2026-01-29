#include <iostream>
#include <vector>
using namespace std;

int naiveInversionCount(vector<int>& v){
    int count = 0;
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++){
            if(v[i]>v[j])count++;
        }
    }
    return count;
}

int main(){
    cout<<"\nWelcome to the World of Programming\n";
    int arr[] = {4,3,2,1}; // Inversion Count is 2+4+4+3+5+3 = 21
    int n = sizeof(arr)/sizeof(int);
    // Copy the Array into Vector
    vector<int> v(arr,arr+n);
    cout<<"Inversion Count is "<<naiveInversionCount(v)<<endl<<endl;
    return 0;
}