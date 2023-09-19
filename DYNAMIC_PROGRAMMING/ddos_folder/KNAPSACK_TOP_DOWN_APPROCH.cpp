#include<iostream>
using namespace std;

int knapsack(int wt[],int val[],int n,int max_wt){
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
                   dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);//we are using val[i-1]and wt[i-1]becase i referst to the value where as j referse to the max_wt of the knap sack///
              }
          }
     }
     return dp[n][max_wt];
}
int main(){
     int wt[]={20,30,25,40};
     int val[]={50,20,10,30};
     int max_wt=50;
     cout<<knapsack(wt,val,4,max_wt)<<endl;
}