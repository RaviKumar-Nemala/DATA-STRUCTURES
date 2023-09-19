#include<bits/stdc++.h>
using namespace std;

int no_of_inversions =  0 ;

int merge( int [], int , int , int );

int count_inversions ( int arr[] , int  low , int high )
{
     int no_of_inversions = 0 ;
     if( high > low )
     {
          int mid_idx = ( low + high)/2;
          no_of_inversions += count_inversions(arr,low , mid_idx);
          no_of_inversions += count_inversions( arr, mid_idx +1 , high);
          no_of_inversions+= merge( arr , low , mid_idx, high);
     }
     return no_of_inversions;
}
int  merge( int arr[] , int low , int mid , int high )
{
     int n1 = mid -low + 1 ;
     int n2 = high - mid ;
     
     int left [ n1 ] ;
     int right [ n2 ] ;

     for( int idx = 0 ; idx  < n1 ; idx ++)
     {
          left [ idx ] = arr [ low + idx ] ;
     }
     for ( int idx = 0 ; idx < n2 ; idx ++ )
     {
          right [ idx ] = arr [ mid  + 1 + idx ] ;
     }

     int idx_1 = 0 ,  idx_2 = 0 ;

     int k = low ; 

     int inversions = 0;

     while( idx_1 < n1 and idx_2 < n2 )
     {
          if ( left[ idx_1 ]  < right [ idx_2 ] )
          {
               arr[ k ++] = left [ idx_1 ++];
          }
          else 
          {
               inversions +=  ( n1 - idx_1);
               arr [ k ++] = right [ idx_2 ++];
          }
     }

     while( idx_1 < n1 )
     {
          arr [ k++ ] =  left [ idx_1 ++ ];
     }
     while ( idx_2 < n2 )
     {
          arr[  k ++ ] = right [ idx_2 ++ ] ;
     }

     return  inversions;
}

int main ()
{
     int arr[] = { 5, 4 , 3,2};
     int n  = 4 ;
     cout << count_inversions( arr , 0 , n-1)<< endl;
     return  0 ;
}