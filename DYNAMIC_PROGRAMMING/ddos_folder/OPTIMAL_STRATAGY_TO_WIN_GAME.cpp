#include<iostream>
using namespace std;
#include<bits/stdc++.h>
class Solution 
{
     public: 
           int win_game(vector<int> arr )
           {

               int i, j; 
               int n = arr.size();
               int dp[n][n] = { 0 } ;
               int max_ele = INT_MIN;
               int max_sum = 0;

            for(int g = 0 ; g < n ; g ++)
               {
                    for ( i = 0 ,j = g ; i < n ; i++ ,j++)
                    {
                         if(g == 0)
                         {
                              dp[i][j] = arr[i];
                         }
                         else if( g==1 )
                         {
                              dp[i][j] = max (arr[i] , arr[j] );
                         }
                         else{
                              int val_1 = arr[i] + min (dp[i+2][j] , dp[i+1][j-1])  ;
                              int val_2 = arr[j] + min (dp[i+1][j-1] ,  dp[i][j-2]) ;
                              dp[i][j] = max(val_1,val_2);
                         }
                    }
               }
               return dp[0][n-1];
           }
};

int main(){
     vector<int>arr = { 20,30 ,2,2,10};
     arr.assign({20,30,2,10});
     Solution obj;
     cout<<obj.win_game(arr);
}
