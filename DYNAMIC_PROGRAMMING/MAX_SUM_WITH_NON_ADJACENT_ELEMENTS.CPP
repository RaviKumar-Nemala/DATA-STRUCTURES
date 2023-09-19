#include<bits/stdc++.h>
using namespace std;

class Solution{
     public : 

     int max_sum_recursive(int arr[] , int idx  )
     {
          if( idx == 0)
          return arr[idx];
          else if(idx ==1 )
          return max(arr[idx ], arr[idx -1]);
          return  max( ( max_sum_recursive(arr ,  idx-2) +arr[idx] ) , max_sum_recursive(arr , idx -1 ) );
          return 0;

     }
          int max_sum ( int arr [] , int n )
          {
               if( n == 0 )
               return arr[0];
               else if( n == 1 )
               return max(arr[0] , arr[1] );

               int incl =arr[0];
               int excl = 0;
               int  i ;
               
               for ( i =0 ;i < n ;i ++){
                    int temp = incl ;
                    incl = max( excl + arr[i] , incl );
                    excl = temp ;
               }
               return incl;
          }
};

int main(){
     int arr []   = {5,1,5,1,2};
     Solution obj ;
     cout<<obj.max_sum(arr, 5);
}