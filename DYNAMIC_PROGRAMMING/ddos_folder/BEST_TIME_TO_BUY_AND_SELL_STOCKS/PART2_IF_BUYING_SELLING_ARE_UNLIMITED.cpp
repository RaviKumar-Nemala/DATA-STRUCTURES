#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution{

     public:
          int max_profit( int arr[]  , int n)
          {
               int profit=0;
               int  i ;
               for( i = 1 ; i <  n; i++ )          
               {
                    if( arr[i-1] < arr[i] )
                    {
                         profit+=(arr[i] -  arr[i-1]);
                    }
               }
               return profit;
          }
};

int main () {
     int arr[] = /*{ 7,1,5,3,6,4}; */ {5,2,7,8};
     int n =4;
     Solution obj;
     cout<<obj.max_profit(arr , n);
}
