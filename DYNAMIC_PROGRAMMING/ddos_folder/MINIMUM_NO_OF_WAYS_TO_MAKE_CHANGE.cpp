#include<iostream>
using namespace std;
#include<algorithm>
#include<climits>
int min_change(int n,int coin[],int target_sum){
     int dp[n+1][target_sum+1];
     int i,j;
     dp[0][0]=0;
     for(i=1;i<=target_sum;i++)
     dp[0][i]=INT_MAX-1;

     for(i=0;i<=n;i++)
     dp[i][0]=0;

     for(i=1;i<=n;i++){
          for(j=1;j<=target_sum;j++){
              
                    if(j<coin[i-1]){
                         dp[i][j]=dp[i-1][j];
                    }
                    else{
                         dp[i][j]=min(1+dp[i][j-coin[i-1]],dp[i-1][j]);
                    }
          }
          }
          return dp[n][target_sum];
}
int min_total_recursive(int n,int coin[],int target_sum){
	if(target_sum==0)
	return 0;
	
	int res=INT_MAX;
	int i;
	for(i=0;i<n;i++){
		if(coin[i]<=target_sum){
				int min_value=min_total_recursive(n,coin,target_sum-coin[i]);
				if(min_value!=INT_MAX and min_value+1<res)
				res=min_value+1;
		}
	}
	return res;
}
int main(){
     int a[]={1,2,3};
     int n=3;
     int target_sum=0
     
     ;
    cout<<min_change(n,a,target_sum);
	//cout<<min_total_recursive(n,a,target_sum);
          } 
