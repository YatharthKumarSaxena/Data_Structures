#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    typedef pair<int,int> pip;
    string isKSortedArray(int arr[], int n, int k) {
        // code here.
        vector<pip>check;
        for(int i=0;i<n;i++){
            check.push_back({arr[i],i});
        }
        sort(check.begin(),check.end());
        for(int i=0;i<n;i++){
            if(abs(check[i].second-i)>k)return "No";
        }
        return "Yes";
    }
};