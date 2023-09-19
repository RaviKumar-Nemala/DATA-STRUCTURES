#include<bits/stdc++.h>
using namespace std; 


int max_sum_sub_arr_optimal ( int arr[] , int n )
{
     int max_sum = INT_MIN;

     int curr_max = arr [ 0 ] ;

     for ( int idx = 1 ;idx < n ;idx ++ )
     {
          int curr_val = arr [ idx ] ;

          curr_max = max ( curr_val , curr_val + curr_max);

          max_sum =  max ( max_sum , curr_max);  
     }
     // cout << max_sum << endl;
     return max_sum;
}


int max_sum_sub_arr ( int arr [] ,  int n ) 
{
     int max_sum = INT_MIN;

     for( int idx = 0 ; idx < n ;idx ++ )
     {
         int sum =  0 ;
          for ( int j  = idx ;  j < n ; j ++)
          {
               sum += arr[  j ] ;
               if (  sum >  max_sum )
                    max_sum = sum;
          }

     }
     return max_sum;
}

int main ()
{
     int arr [] = { -1 ,2,3,-4 } ;
     int n = 4 ;
     cout << max_sum_sub_arr_optimal( arr, n ) << endl;
     return 0 ;
}