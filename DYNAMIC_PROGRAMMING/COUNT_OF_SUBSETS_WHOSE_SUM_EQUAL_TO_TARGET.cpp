#include<iostream>
using namespace std;

     int  count_subsets(int n,int arr[],int target){
     int dp[n+1][target+1];
    dp[0][0]=1;
  int i,j;
     for(i=1;i<=target;i++){
          dp[0][i]=0;
     }        
     for(i=0;i<=n;i++){
          dp[i][0]=1;
     }
     for(i=1;i<=n;i++){
          for(j=1;j<=target;j++){
               if(j<arr[i-1])
                    dp[i][j]=dp[i-1][j];
                    else{
                    dp[i][j]=dp[i-1][j-arr[i-1]]+ dp[i-1][j];
               }
               
          }
      }
      return dp[n][target];
     }
int main(){
     int arr[]={6,4,3,13};
     int n=4;
     int sum=10;
cout<<count_subsets(n,arr,13);

}
