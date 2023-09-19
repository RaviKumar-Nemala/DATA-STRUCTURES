#include<iostream>
using namespace std;
int unbounded_knapsack(int coin[],int sum,int size){
     int i,j;//i represents the size of those arrays where as j represents the max_wt /
     int dp[size+1][sum+1];
     dp[0][0]=1;
     for(i=1;i<=sum;i++){
          dp[0][i]=0;
     }
     for(i=0;i<=size;i++)
     dp[i][0]=1;

     for(i=1;i<=size;i++){
          for(j=1;j<=sum;j++){
              if(j<coin[i-1]){
                   dp[i][j]=dp[i-1][j];
              }
              else{
                   dp[i][j]=dp[i][j-coin[i-1]]+dp[i-1][j];//minor change that is val[i-1]+dp[i][j-wt[i-1]]  is used instead of dp[i-1][j-wt[i-1]] because if we take one element by including that element if we ge max profit then we can able to take that element againg that is what unbounded kanp sack if we dont want to include that item then we dont call for that againg//
              }
          }
     }
     return dp[size][sum];
}
int main(){
     int a[]={1,2,3};
     int n=3;
     int target_sum=4;
     cout<<unbounded_knapsack(a,target_sum,n);
}
