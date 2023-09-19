#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution{
     public: 
           int Lagrest_Square_Matrix( vector<vector<int>  > arr )
           {
                int m = arr.size();
                int n = arr[0].size();
                int dp[m][n];
                int i , j; 
                int max_var = INT_MIN;

               for( i = 0 ; i <  m ; i++ ){
                    dp[i][0] = arr[i][0];
                    if(dp[i][0] == 1 )
                    max_var =  1;
               }

               for( j = 0 ; j < n ; j++ )
               {
                    dp[0][j] =  arr[0][j];
                    if(dp[0][j] == 1)
                    max_var = 1;
               }

               for( i = 1 ; i < m ; i++ )
               {
                    for ( j =1 ; j < n ; j ++ )
                    {
                         if(arr[i][j] == 0 ){
                         continue;
                         }
                         dp[i][j] = min({dp[i-1][j-1] , dp[i-1][j] , dp[i][j-1]}) + 1;
                         if(max_var < dp[i][j])
                         max_var = dp[i][j];
                    }
               }
               if(max_var!=INT_MIN)
               return max_var;
               return 0;
           } 
};

int main(){
     vector<vector<int> > arr = /* {{0,1,1,0,1},{1,1,1,0,0},{1,1,1,1,0},{1,1,1,0,1}}; */ /*{{0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}; */ /* { {0,0} , {0 , 0}}  */ {{1,1,} ,{ 1, 1}};
     Solution obj;
    cout<< obj.Lagrest_Square_Matrix(arr);
}