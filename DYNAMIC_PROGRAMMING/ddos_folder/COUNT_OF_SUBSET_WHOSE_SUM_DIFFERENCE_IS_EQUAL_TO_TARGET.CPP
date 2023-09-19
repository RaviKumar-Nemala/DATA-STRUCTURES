#include<iostream>
using namespace std;
class sum_difference{
     public:
     int  count_of_subsets(int n,int arr[],int target_difference_sum){
          int array_sum=0;
          int i,j;
          for(i=0;i<n;i++){
               array_sum+=arr[i];
          }

          int required_sum=(target_difference_sum+array_sum)/2;

          int dp[n+1][required_sum+1];

          for(i=0;i<=n;i++){
               dp[i][0]=1;
          }

          for(i=1;i<=required_sum;i++){
               dp[0][i]=0;
          }

          for(i=1;i<=n;i++){
               for(j=1;j<=required_sum;j++){
                    if(j<arr[i]){
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


/*
RECURSIVE CODE
class Solution {
public:
    int count = 0;
    void findWays(vector<int>& nums, int target,int start,int sum){
       if(start == nums.size() && sum == target){
           count++;
           return;
       }
        if(start >= nums.size()){
            return;
        }
        findWays(nums, target, start + 1, sum + nums[start]);
        findWays(nums, target, start + 1 ,sum - nums[start]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        findWays(nums, target,0,0);
        return count;
    }
    */
int main(){
     int arr[]={1,1,2,3};//{1,3} {2,1}  ,{1,2} {1,3} ,{1 1 2} {3} //
     int n=4;
     int target_difference_sum=2;
     sum_difference obj;
     cout<<obj.count_of_subsets(n,arr,target_difference_sum);
}    