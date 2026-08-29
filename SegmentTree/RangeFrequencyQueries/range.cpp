#include <bits/stdc++.h>
using namespace std;

class RangeFreqQuery {
public:
    typedef unordered_map<int,int> type;
    vector<type>freqTree;
    int n;
    type addUnorderedMap(type mp1, type mp2){
        type mp;
        for(auto Pair: mp1){
            int ele = Pair.first;
            mp[ele] = mp1[ele];
            if(mp2.find(ele)!=mp2.end()){
                mp[ele] += mp2[ele];
                mp2.erase(ele);
            }
        }
        for(auto Pair: mp2){
            int ele = Pair.first;
            mp[ele] = mp2[ele];
        }
        return mp;
    }
    void buildFreqTree(int i, vector<type>& freqTree, vector<int>& arr, int lo, int hi){
        if(lo==hi){
            unordered_map<int,int>mp;
            mp[arr[lo]] = 1;
            freqTree[i] = mp;
            return;
        }
        int mid = lo+(hi-lo)/2;
        buildFreqTree(2*i+1,freqTree,arr,lo,mid);
        buildFreqTree(2*i+2,freqTree,arr,mid+1,hi);
        freqTree[i] = addUnorderedMap(freqTree[2*i+1],freqTree[2*i+2]);
    }
    RangeFreqQuery(vector<int>& arr) {
        this->n = arr.size();
        freqTree.resize(4*n);
        buildFreqTree(0,freqTree,arr,0,n-1);
    }
    int doQuery(int l, int r, int i, int lo, int hi, int val){
        if(l>hi || r<lo)return 0;
        else if(l<=lo && hi<=r){
            if(freqTree[i].find(val)==freqTree[i].end())return 0;
            return freqTree[i][val];
        }
        int mid = lo+(hi-lo)/2;
        int left = doQuery(l,r,2*i+1,lo,mid,val);
        int right =doQuery(l,r,2*i+2,mid+1,hi,val);
        return left+right;
    }
    int query(int left, int right, int value) {
        return doQuery(left,right,0,0,n-1,value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */