#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//HERE IS THE PROGRAM OF BURSTING BALLOONS GIVEN  N NUMBER OF BALLOONS AND IF WE BURST THAT BALLOON WE WILL GET THE VALUE OF MULTIPLICATION OF LEFT AND ITSELF AND ITS RIGHT//
//WE NEED TO FIND THE OPTIMAL WAY TO BURSTING BALLON IN SUCH THAT THE VALUE  IS GOING TO BE MAXIMUM//

class Solution{
     public : 
           int max_profit( vector<int> arr  , int n )
           {
               int dp[n][n];
               //for( int i  = 0 ; i < n ;i ++)
               //{
               //     dp[i][i] = arr[i];
               //}
               int i, j , g , k;
               memset(dp , 0 , sizeof(dp));
               int max_val = INT_MIN;
               for ( g = 0 ; g < n ; g++ ) //HERE WE ARE USING THE GAP STRATAGY 
               {
                    for ( j  = g , i = 0 ; j < n ;  i++ ,j ++ )  // 
                    {
                         max_val=INT_MIN;

                         for( k = i ; k <= j ; k ++) //this loop is similar to the matrix chaing multipiclation 
                         {
                              int left = (k==i)? 0 : dp[i][k-1]; //if we have 1234 since  k = 0  and i =0  then dp[k-1] = invalid becaz minimum possible index = 0 not  -1 /
                                        //if i == k when k=0 then place  0 on left otherwise take the value from dp[i][k-1]//
                              int right= (k == j )? 0 : dp[k+1][j]; //when k reaches end = = j say 1234 since j=3 and k = 3 then k+1 is not possible //
                              //if k == j then place 0 //
                              int val =  arr[k]; //according to the problem statement if we are bursting the ballon we ge value of its left and right and itself values multiplication//
                              // k always points to the value that we want to burst//
                              if( i > 0 ) 
                              val = arr[i-1] * val ; // multiplying balloon left side value with ballon //
                              //when i = 0 then there no arr[i-1] then it is going to be invalid case that is why we used i > 0
                              if(j < n-1) //when  j reaches end of the arr then there is no j + 1  so j should less then  n-1 //
                              val  = arr[j+1]*val; 
                              val = val +left +right ; //left + right + value profit gives total profit that we can get by bursting that balloon //

                              if(max_val  <  val ) //we need a maximum value so maximize the profit//
                              max_val = val;
                         }
                         dp[i][j] = max_val;

                    }
               }
               return dp[0][n-1];
           }
};

int main(){
     vector<int>arr  = {2, 3 , 1 , 5 , 6 }; /*{1, 2, 3, 4, 5};*/
     Solution obj;
     cout<<obj.max_profit(arr , 5);
}