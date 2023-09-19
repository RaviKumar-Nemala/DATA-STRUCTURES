#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution{
public:


int max_profit_with_k_optimal_sol( int profit[] , int  k, int n)
{
     int i, j;
     int T[k+1][n];
     int max_val;
     for( int i=0 ; i <= k ;i++)
          T[i][0]=0;
     for(int j = 0 ;j<n;j++)
          T[0][j]=0;

     for( i = 1; i <= k ; i++ ) 
     {
          max_val = -profit[0];
          for( j =1 ; j <n ;j ++)
          {    
               T[i][j] = max (T[i][j-1]  , profit[j] + max_val); //here we finding the maximum of either if don't 
               max_val = max(max_val , T[i-1][j] - profit[j]);//here we are finding the optimal day to buy the stocks buying price  = max_profit  -  selling price //therefore when we have 2 transactions and 4 days then we find the best day to buy the stocks for k-1 i.e 2-1 transactions with same days it gives buying price then we add that to selling price then it will give total profit //here we should add selling price to the buying pirce because initially buying price is taken negatively  // 
          }
     }
     return T[k][n-1];
}
     int max_profit_with_k(int profit[] ,int k, int  n)
     {
          int i,j;
          int T[k+1][n];//no need to take the n+1 because assigning the dp based on the given array size ///
          //here n represents the number of days if n = 8 then no of days started from 0 upto 7 
          int m; //k+1 is used because transactions are started from 0->k// if k=3 it starts from 0->3transcactions//
          int max_val=INT_MIN;
          for( int i=0 ; i <= k ;i++)
          T[i][0]=0;
          for(int j = 0 ;j<n;j++)
          T[0][j]=0;
          //where k is the transactions and n+1 is the days //
          for(  i = 1 ; i <= k ; i++ )
          {
               max_val = 0;
               for( j =1 ; j < n ;j++)
               {
                    for(m = 0 ; m <j ; m++)
                    {
                    max_val= max(max_val  , profit[j] - profit[m] + T[i-1][m]);//here we are try to sell the stock that is why profit[j] - profit[m] is used to find the profit that we have gain to that stock we need to maximize the profit //
                         //same time we need to add this stock profit to the before k-1 transactions max profit // that is why we used t[i-1][m]//
                    }
                    T[i][j] = max ( max_val , T[i][j-1]);
               }
          }
          return T[k][n-1]; //n = 8 no of days = 7 from 0th day last answer is at n-1th day that is 8-1 = 7 //
     }  
};


int main(){
     int arr[] = { 2,5,7,1,4,3,1,3};
     Solution obj;
     int no_of_transactions=3;
     int n=8;
     //cout<<obj.max_profit_with_k(arr , no_of_transactions , n);
     cout<<obj.max_profit_with_k_optimal_sol(arr, no_of_transactions, n);
}