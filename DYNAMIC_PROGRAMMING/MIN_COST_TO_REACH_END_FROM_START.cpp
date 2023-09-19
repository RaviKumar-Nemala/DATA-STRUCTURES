#include<iostream>
using namespace std;
#include<bits/stdc++.h>

#define rows 3
#define col  4
class Solution
{
     public: 
         int min_cost(int arr[][col] )
         {
              int i, j;
              int dp[rows+1][col+1];
               int sum = 0 ;
               for(i = 0 ; i <= rows ; i++)
               {
                    sum  += arr[0][i];
                    dp[0][i] =  sum;
               }
               sum = 0 ;
               for( i = 0 ; i <= col ; i++)
               {
                    sum += arr[i][0];
                    dp[i][0] = sum;
               }
               
               for (  i = 1 ; i <= rows; i ++ )
               {
                    for ( j = 1 ; j <= col ; j++ )
                    {
                         dp[i][j] = arr[i][j] + min(dp[i-1][j] , dp[i][j-1] );
                    }
               }
               return dp[rows-1][col-1];
         }
};

int main(){
     int arr[rows][col] = {{1,3,5,8,} , {4,2,1,7} , {4,3,2,3}};
     Solution obj;
     cout<<obj.min_cost(arr);
}
