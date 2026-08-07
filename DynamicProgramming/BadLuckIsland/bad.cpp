#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

double dp[105][105][105];

double calcRockWin(int r, int s, int p){
    if(s==0 || r==0)return 0.0;
    else if(p==0)return 1.0;
    else if(dp[r][s][p]>-0.9)return dp[r][s][p];
    int total = r*s + s*p + p*r;
    double prs = (1.0*r*s)/total;
    double psp = (1.0*s*p)/total;
    double ppr = (1.0*p*r)/total;
    double result = prs * calcRockWin(r,s-1,p) + psp * calcRockWin(r,s,p-1) + ppr * calcRockWin(r-1,s,p);
    return dp[r][s][p] = result;
}
double calcSciWin(int r, int s, int p){
    if(s==0 || p==0)return 0.0;
    else if(r==0)return 1.0;
    else if(dp[r][s][p]>-0.9)return dp[r][s][p];
    int total = r*s + s*p + p*r;
    double prs = (1.0*r*s)/total;
    double psp = (1.0*s*p)/total;
    double ppr = (1.0*p*r)/total;
    double result = prs * calcSciWin(r,s-1,p) + psp * calcSciWin(r,s,p-1) + ppr * calcSciWin(r-1,s,p);
    return dp[r][s][p] = result;
}
double calcPapWin(int r, int s, int p){
    if(r==0 || p==0)return 0.0;
    else if(s==0)return 1.0;
    else if(dp[r][s][p]>-0.9)return dp[r][s][p];
    int total = r*s + s*p + p*r;
    double prs = (1.0*r*s)/total;
    double psp = (1.0*s*p)/total;
    double ppr = (1.0*p*r)/total;
    double result = prs * calcPapWin(r,s-1,p) + psp * calcPapWin(r,s,p-1) + ppr * calcPapWin(r-1,s,p);
    return dp[r][s][p] = result;
}

int main(){
    int r,s,p;
    cin>>r>>s>>p;
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            for(int k = 0; k <= 100; k++){
                dp[i][j][k] = -1.0;
            }
        }
    }
    double res1 = calcRockWin(r,s,p);
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            for(int k = 0; k <= 100; k++){
                dp[i][j][k] = -1.0;
            }
        }
    }
    double res2 = calcSciWin(r,s,p);
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            for(int k = 0; k <= 100; k++){
                dp[i][j][k] = -1.0;
            }
        }
    }
    double res3 = calcPapWin(r,s,p);
    cout<<res1<<" "<<res2<<" "<<res3<<endl;
    return 0;
}