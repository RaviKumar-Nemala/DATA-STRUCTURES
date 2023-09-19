#include<bits/stdc++.h>
using namespace std; 

bool is_alternative( int  curr_val , int prev_val  )
{
     bool case_1 = curr_val %2 == 0 and prev_val %2 != 0 ;

     bool case_2 = curr_val %2 != 0 and prev_val %2 == 0 ;

     if( case_1 or case_2 )   return true;

     else      return false; 

}

int get_max_even_odd ( int arr[] , int n ) 
{
     int  even_odd_len  = 1 ;
     int res = INT_MIN;
     for ( int idx = 1; idx < n ;idx++ )
     {
          int curr_val = arr [ idx ] ;
          int prev_val = arr [ idx -1 ] ;
//if the previous value is the alternative of the current value then we increment then even odd count by one
//otherwise we set to the 1 
//every time we find the maximum of the even and odd length
          if( is_alternative( curr_val , prev_val))
          {
               even_odd_len ++;
               res  = max( res , even_odd_len ) ;
          }    
          else 
          {
               even_odd_len = 1 ; 
          }
     }

     return res; 

}

int main ()
{

     int arr[]  = { 5 , 10 , 20 , 6, 3,8};
     
     //need to find the even odd consecutive elements length 
     //here ( 6 , 3, 8 ) are max even odd consecutive elements and the length = 3

     int n = 6;

     cout << get_max_even_odd ( arr , n ) << endl;

     return 0;

}