#include<iostream>
using namespace std;
bool subset_sum(int target,int arr[],int n){
     bool dp[n+1][target+1];
     int i,j;
     for(i=0;i<=n;i++){
         dp[i][0]=true;
     }
    for(j=1;j<=target;j++){
     	dp[0][j]=false;
	  }
     for(i=1;i<=n;i++){
          for(j=1;j<=target;j++){
              if(j>=arr[i-1]){
              	dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
				  }
				  if(j<arr[i-1]){
				  	dp[i][j]=dp[i-1][j];
				  }
          }
     }
     
   if(dp[n][target]==true){
     i=n,j=target;
     while(i>=0 and j>=0){
     	if(dp[i][j]==true and dp[i-1][j]!=true){
     		cout<<arr[i]<<" ";
     			j=j-arr[i];
		  	i--;
		  }
		  else{
		  	i--;
		  }
		  }
	  }
       
     return dp[n][target];
}
int main(){
     //int a[]={2,3,7,8,10};
     int a[]={3,34,4,12,5,4};
     cout<<subset_sum(11,a,6);
}