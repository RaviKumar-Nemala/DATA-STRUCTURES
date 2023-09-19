#include<iostream>
using namespace std;

class target_sum{
      public:
     int count_no_of_subsets(int n, int arr[],int target_sum){
          int array_sum=0;
          register int i,j;
          for(i=0;i<n;i++){
               array_sum+=arr[i];
          }
          int required_sum=(array_sum+target_sum)/2;
          int dp[n+1][required_sum+1];
          for(i=0;i<=n;i++){
               dp[i][0]=1;
          }
          for(i=1;i<=required_sum;i++){
               dp[0][i]=0;
          }
          for(i=1;i<=n;i++){
               for(j=1;j<=required_sum;j++){
                     if( arr[i-1] > j){
                     dp[i][j]=dp[i-1][j];
                    }
                    else{
                         dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
                    }
               }
          }
          return dp[n][required_sum];
     }
          };
int main(){
      int arr[]={1,1,2,3};//{1,3} {2,1}  ,{1,2} {1,3} ,{1 1 2} {3} //
     int n=4;
     int target_difference_sum=1;
     target_sum obj;
     cout<<obj.count_no_of_subsets(n,arr,target_difference_sum);
}
