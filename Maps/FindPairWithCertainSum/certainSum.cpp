#include <vector>
#include <unordered_map>
using namespace std;

class FindSumPairs {
public:
    vector<int> nums1,nums2;
    unordered_map<int,int>mp1,mp2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i=0;i<n1;i++) this->mp1[nums1[i]]++;
        for(int i=0;i<n2;i++) this->mp2[nums2[i]]++;
    }
    
    void add(int index, int val) {
        int value = nums2[index];
        nums2[index] += val;
        int newKey = nums2[index];
        mp2[value]--;
        if(mp2[val] == 0)mp2.erase(val);
        mp2[newKey]++;
    }
    
    int count(int tot) {
        int totalPairs = 0;
        for(auto p: mp1){
            int ele = p.first;
            int target = tot - ele;
            if(mp2.find(target)!=mp2.end()){
                totalPairs += mp1[ele] * mp2[target];
            }
        }
        return totalPairs;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */