#include<iostream>
using namespace std;
class equal_sum_partioning{
     public:
     bool is_parition(int arr[],int n)
     {    
          int i,sum=0,j;
          for(i=0;i<n;i++)
          sum=sum+arr[i];
          if(sum%2!=0)return false;


          sum=sum/2;
          int dp[n+1][sum+1];
           for(i=0;i<=sum;i++){
               dp[0][i]=false;
          }
          for(i=0;i<=n;i++){
               dp[i][0]=true;
          }
          for(i=1;i<=n;i++){
               for(j=1;j<=sum;j++){
                    if(j>=arr[i-1]){
                         dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
                    }
                  if(j<arr[i-1])
                         dp[i][j]=dp[i-1][j];
                    
               }
          }
          return dp[n][sum];
     }
};
int main(){
     int arr[]={1,11,5,5};
     equal_sum_partioning obj;
     cout<<obj.is_parition(arr,4);

}