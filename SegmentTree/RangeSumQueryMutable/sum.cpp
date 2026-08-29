#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> sumTree;
    int n;
    void buildSumTree(vector<int>& sumTree, vector<int>& nums, int i, int lo, int hi){
        if(lo==hi){
            sumTree[i] = nums[lo];
            return;
        }
        int mid = lo+(hi-lo)/2;
        buildSumTree(sumTree,nums,2*i+1,lo,mid);
        buildSumTree(sumTree,nums,2*i+2,mid+1,hi);
        sumTree[i] = sumTree[2*i+1]+sumTree[2*i+2];
    }

    NumArray(vector<int>& nums) {
        this->n = nums.size();
        sumTree.resize(4*n);
        buildSumTree(sumTree,nums,0,0,n-1);
    }

    void updateSumTree(vector<int>& sumTree, int i, int idx, int val, int lo, int hi){
        if(lo==hi){
            sumTree[i] = val;
            return;
        }
        int mid = lo+(hi-lo)/2;
        if(idx <= mid)updateSumTree(sumTree,2*i+1,idx,val,lo,mid);
        else updateSumTree(sumTree,2*i+2,idx,val,mid+1,hi);
        sumTree[i] = sumTree[2*i+1]+sumTree[2*i+2];
    }
    
    void update(int index, int val) {
        updateSumTree(sumTree,0,index,val,0,n-1);
    }

    int getSumEle(vector<int>& sumTree, int i, int l, int r, int lo, int hi){
        if(l>hi || r<lo)return 0;
        if(l<=lo && hi<=r)return sumTree[i];
        int mid = lo+(hi-lo)/2;
        int left = getSumEle(sumTree,2*i+1,l,r,lo,mid);
        int right = getSumEle(sumTree,2*i+2,l,r,mid+1,hi);
        return left+right;
    }
    
    int sumRange(int left, int right) {
        return getSumEle(sumTree,0,left,right,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(sumTree);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */