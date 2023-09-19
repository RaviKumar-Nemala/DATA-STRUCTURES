#include<bits/stdc++.h>
using namespace std ;

int lamudo_partition ( int arr[] , int low , int high )
{
     int i = low -1;
     int pivot =  arr[ high ] ;    
     for( int j = low ; j <= high-1 ; j ++)
     {
          if ( arr[ j ] <= pivot)
          {
               i ++;
               swap( arr[ i] , arr[j]);
          }
     }

     swap( arr[i+1] ,  arr[ high ]) ;
     
     return ( i +1 ) ;

}

int kth_smallest ( int arr[] , int n , int k , int low, int high)
{
     while ( low <= high)
     {
          int pivot_idx = lamudo_partition( arr , low , high);
          //left side of the pivot idx elements are smaller then the pivot element
          //if the pivot element is smaller then k elements then we say the pivot element is our kth smallest element
          // here ( k-1) is used because indexing starts from 0;
          if( pivot_idx ==  ( k -1 ))
          {
               return arr[ pivot_idx];
          }

          else if ( pivot_idx > (k-1) )
          {
               high = pivot_idx -1 ;
          }
          else 
          low = pivot_idx +  1 ;

     }
     return -1;


}

int main ()
{
     int arr[] = { 10,4,5,8,11,6,26};
     int n = 7 ;
     int k =  6 ;
     cout << kth_smallest(arr,n,k,0,n-1)<<endl;
     return 0 ;
}