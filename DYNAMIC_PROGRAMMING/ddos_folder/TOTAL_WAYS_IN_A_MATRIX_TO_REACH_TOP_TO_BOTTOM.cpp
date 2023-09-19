#include<bits/stdc++.h>
using namespace std;
// A C++  program to count all possible paths
// from top left to bottom right

#include <iostream>
using namespace std;

// Returns count of possible paths to reach cell at row
// number m and column number n from the topmost leftmost
// cell (cell at 1, 1)
int numberOfPaths(int m, int n)
{
    // If either given row number is first or given column
    // number is first
    if (m == 1 || n == 1)
        return 1;

    // If diagonal movements are allowed then the last
    // addition is required.
    return numberOfPaths(m - 1, n) + numberOfPaths(m, n - 1);
    // + numberOfPaths(m-1, n-1);
}

class Solution{
     public:
          int total_ways( vector<vector<int> > arr , int rows, int colms)
          {
               
           int dp[rows ][colms ];
           int i, j ;
           for ( i = 0 ;i < rows; i++ )    
           {
                     dp[0][i] = 1;
           }

           for( i = 0 ;i < colms ; i++ )
           {
                dp[i][0] =  1 ;
           }
           
           for ( i =1 ; i< rows ; i ++ )
           {
                for (j =1  ; j < colms ; j ++ )
                {
                     dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
           }
           return dp[rows-1][colms-1];
          }   
};

int main(){
     vector<vector<int> > arr  = { {1,2,3,4} , {5,6,7,8} , {9, 10 ,11 ,12 } , {13 , 14 ,15 ,16 }, {17, 18 ,19 ,20 } };
     Solution obj;
     cout<<obj.total_ways(arr , 4 , 4 );
}
