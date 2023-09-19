#include<bits/stdc++.h>
using namespace std ;

bool is_existed ( int arr[]  ,  int  target_sum , int n )
{
     int idx =  0 ;

     /**
      * here we use the sliding window approach to get solve this problem in optimal manner
      * 
      * increment the window size until the sum of all elements is greater then  the target sum 
      * 
      * if the target sum is greater then  window size sum then simply remove the first element in the window 
      */
     int sum =  0 ;
     int prev_idx = 0 ; 
     for ( idx = 0 ; idx <  n ;idx ++ )
     {
          sum += arr [ idx ] ; 
               while( sum  >  target_sum )
               {
                    sum  -= arr[ prev_idx] ;
                    prev_idx ++;
               }
          if( sum == target_sum)   return true;
     }
     return false; 
}
int main ()
{
     int arr[] = { 1 , 4 , 20 , 3 , 10 , 5 } ;    
     
     int n = 6;

     int target_sum = 33; 
      
     cout << is_existed (arr , target_sum ,  n ) ; 

     return 0;      
}