#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int LIS_length(vector<int>&arr)
{
     int n=arr.size();
     int dp[n];//in this size n shoule be enough//
     int i,j;
     for(i=0;i<=n;i++){
     dp[i]=1;
     }

     for(i=1;i<=n;i++)
     {
          for(j=0;j< i ;j++)
          {
               if(arr[j] < arr[i])
               {
                    if(dp[j] + 1 > dp[i]){
                    dp[i]=dp[j]+1;
                    }
               }
          }
     }
     cout<<"PRINTING THE DP VALUES : ";
     for(auto it :  dp )
     cout<<it<<" ";
     cout<<endl;
    cout<<"PRINTING THE LONGEST increasing SUBSEQUENCE LENGTH: ";
     return *max_element(dp ,dp +n); //it returns the maximum longest increasing subsequence//
}


int main(){
     vector<int>arr={3,4,-1,0,6,2,3};
     cout<<LIS_length(arr);
}