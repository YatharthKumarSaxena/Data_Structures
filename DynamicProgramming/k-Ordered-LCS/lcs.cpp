#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[2005][2005][10];

int kOrderedLCS(int i, int j, int k, vector<int>& seq1, vector<int>& seq2){
	int n = seq1.size();
	int m = seq2.size();
	if(i==n || j==m)return 0;
	else if(dp[i][j][k]!=-1)return dp[i][j][k];
	int res = 0;
	if(seq1[i]==seq2[j]) res = 1+kOrderedLCS(i+1,j+1,k,seq1,seq2);
	else{
		if(k>0){
			res = max(res,1+kOrderedLCS(i+1,j+1,k-1,seq1,seq2));
		}
		res = max(res,kOrderedLCS(i+1,j,k,seq1,seq2));
		res = max(res,kOrderedLCS(i,j+1,k,seq1,seq2));
	}
	return dp[i][j][k] = res;
}

int main(){
	int N,M,K;
	cin>>N>>M>>K;
	vector<int>seq1(N);
	vector<int>seq2(M);
	for(int i=0;i<N;i++){
		cin>>seq1[i];
	}
	for(int i=0;i<M;i++){
		cin>>seq2[i];
	}
	memset(dp,-1,sizeof(dp));
	cout << kOrderedLCS(0,0,K,seq1,seq2) << endl;	// Writing output to STDOUT
}