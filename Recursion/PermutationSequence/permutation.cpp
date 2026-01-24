#include <string>
using namespace std;

class Solution {
public:
    int calcFact(int n){
        int ans = 1;
        for(int i=2;i<=n;i++){
            ans *= i;
        }
        return ans;
    }
    string findPermutation(string ans,int n,int k,string remString){
        if(n==1){
            ans += remString;
            return ans;
        }
        int fact = calcFact(n-1);
        int idx = k/fact;
        if(k%fact==0){
            idx--;
            k=fact;
        }
        else k = k%fact;
        ans += remString[idx];
        remString.erase(idx,1);
        return findPermutation(ans,n-1,k,remString);
    }
    string getPermutation(int n, int k) {
        string remString = "";
        for(int i=1;i<=n;i++){
            remString += to_string(i);
        }
        return findPermutation("",n,k,remString);
    }
};