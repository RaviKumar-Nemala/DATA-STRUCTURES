#include<bits/stdc++.h>
using namespace std ;

void heapify ( int arr[] , int idx , int n)
{
     int curr_val = arr[  idx ] ; 

     int left = 2 *idx +1 ;
     int right = 2 *idx+2;

     int large_idx = idx ;

     if ( left < n and arr [left ] > arr[large_idx])
     {
          cout << "left val " << arr [ left]<< endl;
          large_idx = left;
     }
     if ( right < n  and arr [ right ] > arr[large_idx])
     {
          cout <<"RIGHT VALUE " << arr [ right ] << endl;
          large_idx = right;
     }
     if ( large_idx != idx )
     {
          swap ( arr [ large_idx ] , arr [ idx ] ) ;
          heapify(arr, large_idx , n);
     }

}
void print_val ( int arr[]  , int n )
{
     for ( int i = 0 ; i < n ; i ++ )
          cout << arr [ i ] <<" " ;

     cout << endl; 
}
void build_max_heap(int arr[] , int n )
{

     int last_internal_node_idx =  ( n -2 )/2;    
    
     for ( int idx = last_internal_node_idx ; idx >= 0  ; idx --)
     {
          heapify( arr , idx ,n );
     }

     print_val ( arr , n );

     for(  int idx =  n-1 ; idx >= 1  ; idx -- )
     {
          swap( arr [ idx ] , arr[ 0 ] );
          ( arr,0,idx);
     }
     return;
}    

int main ()
{
     int arr [] = {  10 , 20 ,15,6, 1};
     int n = 5;
     build_max_heap( arr, n );
     print_val ( arr  , n ) ;
     return 0 ; 
}