#include<bits/stdc++.h>
using namespace std;


void bubble_sort( int arr[] , int n )
{

     int i , j ;
     bool swapped ;

     for ( i =  0 ; i < n -1 ;  i ++ )
     {
          swapped = false ;
          for ( j = 0 ; j < n-1 ; j ++ )
          {
               if ( arr [j ]   > arr [ j +1  ] )
               {
                    swapped = true;
                    swap ( arr[ j ]  , arr [ j+1 ]) ;
               }
          }
          // if there is no swapping happend it means our array is sorted 
          // so no need to iterative again we simply break the loop
          if  ( !swapped )
          {    
                    break;
          }
     }
     return ;
}

void print_val ( int arr[] , int n )
{
     for ( int idx = 0  ; idx < n ; idx ++ )
     {
          cout << arr [ idx ] <<" "  ; 
     }
     cout << endl;

}
int main ()
{
     int arr[ ] = { 20,5,40,5,60};
     bubble_sort ( arr , 5 );
     print_val( arr  , 5 ) ;
     return 0 ;
}