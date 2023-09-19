#include<bits/stdc++.h>
using namespace std;


void selection_sort ( int arr[]  , int n )
{
     for ( int idx = 0 ;idx < n ;idx ++ )
     {    
          int min_idx = idx ;
          int min_val = INT_MAX;
          for ( int j = idx +1  ; j< n; j ++)
          {
               if ( arr [ j ]  < min_val)
               {
                    min_idx  = j ;
                    min_val = arr [ j ] ;
               }
          }
         swap( arr[idx ] , arr[min_idx]);
     }

     return;
}

void print_val (  int arr[] , int n )
{
     for ( int idx = 0 ; idx < n ; idx ++ )
     {
          cout << arr [ idx ] << " " ; 
     }
     cout << endl;

}

int main ()
{

     int arr[] = { 20,5,40,60,10,30};

     int n = 6;

     selection_sort( arr , n );

     print_val ( arr , n ) ;
     
     return 0;
}