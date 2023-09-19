#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution{

     private : 
               int find_max( int idx , int n , int arr[])
          {
               int max_var = INT_MIN;
               for(int i = idx ; i < n; i++ )
               {
                    if(max_var <  arr[i])
                    {
                         max_var = arr[i];
                    }
               }
               return max_var;
          }
     public:

          int max_profit_brute_force(int arr[] ,  int  n)
          {
               int current_profit = INT_MIN;
               int max_profit = INT_MIN;
               int i,j; 
               int max_var = INT_MIN;
               for(i=0 ; i < n-1 ; i++)
               {
                    max_var =  find_max(i+1 , n , arr );
                    current_profit = max_var - arr[i];
                    if(current_profit > max_profit )
                    {
                         max_profit = current_profit;
                    }
               }
               return max_profit;
          }

          int max_profit_optimal( int arr[]  , int n )
          {
               int current_profit=0;
               int max_profit = 0;
               int min_val =INT_MAX;
               int i;
                    for( i = 1 ; i < n ; i++)
                    {
                         min_val = min(min_val , arr[i-1]);
                         current_profit = arr[i] - min_val;
                         if(current_profit > max_profit )
                         max_profit = current_profit;
                    }
                    return max_profit;
          }
};


int main () {
     int arr[] = { 7,1,5,3,6,4};
     int n =6;
     Solution obj;
     cout<<"using the brute force approch to solve the given problem : ";
     cout<<obj.max_profit_brute_force(arr, n );
     cout<<"\n using the optimal solution to solve the givern problem : ";
     cout<<obj.max_profit_optimal(arr , n);
}