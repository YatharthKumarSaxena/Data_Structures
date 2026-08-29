#include <bits/stdc++.h>
using namespace std;

void buildMaxTree(vector<int>& maxTree, vector<int>& nums, int i, int lo, int hi){
    if(lo==hi){
        maxTree[i] = nums[lo];
        return;
    }
    int mid = lo+(hi-lo)/2;
    buildMaxTree(maxTree,nums,2*i+1,lo,mid);
    buildMaxTree(maxTree,nums,2*i+2,mid+1,hi);
    maxTree[i] = max(maxTree[2*i+1],maxTree[2*i+2]);
}

void updateMaxTree(vector<int>& maxTree, int i, int idx, int val, int lo, int hi){
    if(lo==hi){
        maxTree[i] = val;
        return;
    }
    int mid = lo+(hi-lo)/2;
    if(idx <= mid)updateMaxTree(maxTree,2*i+1,idx,val,lo,mid);
    else updateMaxTree(maxTree,2*i+2,idx,val,mid+1,hi);
    maxTree[i] = max(maxTree[2*i+1],maxTree[2*i+2]);
}

int getMaxEle(vector<int>& maxTree, int i, int l, int r, int lo, int hi){
    if(l>hi || r<lo)return INT_MIN;
    if(l<=lo && hi<=r)return maxTree[i];
    int mid = lo+(hi-lo)/2;
    int left = getMaxEle(maxTree,2*i+1,l,r,lo,mid);
    int right = getMaxEle(maxTree,2*i+2,l,r,mid+1,hi);
    return max(left,right);
}

int main(){
    return 0;
}