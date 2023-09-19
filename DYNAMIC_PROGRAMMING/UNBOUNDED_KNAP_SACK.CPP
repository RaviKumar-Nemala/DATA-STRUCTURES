#include<iostream>
using namespace std;

int unbounded_knapsack(int wt[],int val[],int n,int max_wt){
     int i,j;//i represents the size of those arrays where as j represents the max_wt /
     int dp[n+1][max_wt+1];
     for(i=0;i<=n;i++){
          for(j=0;j<=max_wt;j++){
               if(i==0||j==0){
                    dp[i][j]=0;
               }
              else if(j<wt[i-1]){
                   dp[i][j]=dp[i-1][j];
              }
              else{
                   dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);//minor change that is val[i-1]+dp[i][j-wt[i-1]]  is used instead of dp[i-1][j-wt[i-1]] because if we take one element by including that element if we ge max profit then we can able to take that element againg that is what unbounded kanp sack if we dont want to include that item then we dont call for that againg//
              }
          }
     }
     return dp[n][max_wt];
}
int main(){
     int wt[]={20,30,25,40};
     int val[]={50,20,10,30};
     int max_wt=50;
     cout<<unbounded_knapsack(wt,val,4,max_wt)<<endl;
}