#include<bits/stdc++.h>
using namespace std;

class Solution
{
     public: 
     int dp[100][100];
          int sum( vector<vector<int > > arr )
          {
               int row = arr.size();
               int col = arr[0].size() ;
               //cout<<row <<col;
               //int dp[row+1][col+1];
               int i ,j ;
               for ( i =0 ; i <= row ; i ++)
               {
                    dp[0][i] = 0;
               }

               for ( j = 0 ; j <= col ; j++ )
               {
                    dp[j][0] = 0;
               }

               for ( i = 1  ; i <=row ; i ++ )
               {
                    for ( j =1 ; j <= col  ; j++ )
                    {
                         dp[i][j] = dp[i-1][j] + dp[i][j-1] + arr[i-1][j-1] - dp[i-1][j-1];
                    }
               }
          }

          int sum_query( int row_1 , int col_1 , int row_2 ,int col_2)
          {
               row_1++;
               row_2 ++;
               col_1++;
               col_2 ++;
               return (dp[row_2][col_2] - dp[row_1 - 1][col_2] - dp[row_2][col_1 - 1] + dp[row_1 - 1 ][col_1 - 1]);
          }

};

int main(){ 
     
    vector<vector<int > > arr =  {{2,0,-3,4}, {6, 3, 2, -1}, {5, 4, 7, 3}, {2, -6, 8, 1}} ; 
     Solution obj;
     obj.sum(arr);
     cout<<obj.sum_query(1,1,2,2);
}