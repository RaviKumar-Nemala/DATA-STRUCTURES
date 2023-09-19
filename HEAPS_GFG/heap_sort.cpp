#include<bits/stdc++.h>
using namespace std ;

void heapify ( int arr[] ,int idx , int n )
{
     int left = 2  *idx + 1 ;

     int right = 2 *idx + 2;

     int largest_idx = idx;

     int current_val = arr[ idx ] ; 

     if( left < n  and  arr[ left ] > arr[largest_idx]) 
     {
          largest_idx = left;
     }
     if ( right < n  and arr [ right ] > arr[ largest_idx])
     {
          largest_idx = right;
     }
     if  ( largest_idx != idx)
     {
          swap ( arr [ idx ] , arr [ largest_idx]) ;
          heapify ( arr , largest_idx, n );
     }
}

void build_max_heap ( int arr[] , int   n )
{
     /**
      * build the max heap by using the internal nodes
      */
     // getting the last internal node idx = ( n - 2 )/2 ;

     int last_internal_node_idx = (n-2)/2;

     for( int idx = last_internal_node_idx ; idx >=0 ; idx --)
     {
          heapify ( arr , idx , n);
     }

}

/**
 * initially we build the max heap 
 * by using the max heap we build the min_heap
*/
void build_heap( int arr[] , int n )
{

     build_max_heap ( arr , n ) ;

     /**
      *   AFTER BUILDING MAX HEAP SWAP THE LAST ELEMENT WITH THE FIRST ELEMENT ( )
      *   THEN CALL THE HEAPIFY FUNCTION
      *   INITIALLY THE HEAP IS MAX HEAP ( LARGEST ELEMEN IS ON THE TOP OF THE HEAP)
      *   SWAPPING THE FIRST ELEMENT WITH THE LAST EVERY TIME THEN WE GET THAT ( MAX ELEMENT  , 2ND MAX ELEMENT AT THE END OF THE ARRAY ) FINALLY THE LAST LARGEST ELEMENT IS ON THE FIRST THEN OUR ARRAY WILL BE SORTED
      */

     for ( int i = n-1 ;i >=0 ;i --)
     {
          swap ( arr [ i ] ,  arr [ 0 ]  ) ;

          heapify( arr , 0 , i );
     }
     return;
}

void display ( int arr[] , int n ) 
{
     for( int i = 0 ;i <  n ; i ++ )
     {
          cout << arr [i ] << " " ;

     }
     cout<< endl;
}

int main () 
{
     
     int arr [5 ] = {  10,20,15,6,1};

     int n  = 5; 
     
     build_heap ( arr , n );

     display ( arr , n );

     return 0;
}