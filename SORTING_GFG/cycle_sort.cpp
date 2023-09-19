#include<bits/stdc++.h>
using namespace std ;

int no_of_swaps = 0 ;

void cycle_sort( int arr[] , int  n )
{
     int pos ;
     
     for( int curr_idx = 0 ; curr_idx < n ; curr_idx ++ )
     {
          pos = curr_idx;     
          int curr_val = arr[ curr_idx ] ;

          for ( int idx  = curr_idx + 1 ; idx < n ; idx++ )
          {
               if( arr[idx] < curr_val )
               {
                    pos ++;
               }
          }
          swap ( curr_val , arr[pos]);

          while ( pos != curr_idx )
          {
               no_of_swaps ++;
               pos = curr_idx ;
               for ( int idx  = curr_idx +1  ; idx < n ; idx++)
               {
                    if ( arr[ idx ] <  curr_val)
                    {
                         pos ++;
                    }
               }
               swap ( curr_val , arr[pos]);
          }
     }
     return;
}

void print_val ( int arr[] , int n )
{
     for ( int idx =  0 ; idx <  n ; idx ++) 
          cout << arr[  idx ] <<" ";
     cout<< endl;

}
int main ()
{
     int arr[]  = { 10,20,15,6,1};
     int n = 5;
     cycle_sort ( arr , n );
     cout << no_of_swaps << endl;
     // print_val( arr ,n); 
     return 0;
}